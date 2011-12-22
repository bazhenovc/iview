#include "mainwindow.hh"

#include "idocument.hh"
#include "documentfactory.hh"

#include <QFileDialog>
#include <QScrollBar>
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

static QString num = QString();
static iDocument emptyDocument = iDocument();

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), document(&emptyDocument)
{
	ui.setupUi(this);
	statusBarLabel = new QLabel(ui.statusBar);
	statusBarLabel->setText("No document");
	scale = 1.0f;
}

void MainWindow::openDocument(const QString &path)
{
	if (document && document != &emptyDocument)
	{
		delete document;
		document = &emptyDocument;
	}
	iDocument* newDocument = DocumentFactory::openDocument(path);
	if (newDocument)
	{
		document = newDocument;
		ui.label->setPixmap(document->renderPage(0, physicalDpiX(), physicalDpiY()));
		currentPage = 0;
		statusBarLabel->setText("Page: 0");
	}
}

void MainWindow::on_actionOpen_triggered()
{
	QString path = QFileDialog::getOpenFileName(this, "Select document",
												QApplication::applicationDirPath(),
												"PDF files (*.pdf)");
	if (path != "")
	{
		openDocument(path);
	}
}

void MainWindow::on_actionQuit_triggered()
{
	close();
}

void MainWindow::on_actionNext_page_triggered()
{
	QScrollArea* sa = ui.scrollArea;
	if (sa->verticalScrollBar()->sliderPosition() == sa->verticalScrollBar()->maximum())
	{
		currentPage++;
		if (currentPage < document->numPages())
		{
			updateDocument();
			scrollTo(MINIMUM);
		}
		else
			currentPage--;
	}
	else
		scrollTo(MAXIMUM);
}

void MainWindow::on_actionPrevious_page_triggered()
{
	QScrollArea* sa = ui.scrollArea;
	if (sa->verticalScrollBar()->sliderPosition() == sa->verticalScrollBar()->minimum())
	{
		currentPage--;
		if (currentPage >= 0)
		{
			updateDocument();
			scrollTo(MAXIMUM);
		}
		else
			currentPage++;
	}
	else
		scrollTo(MINIMUM);
}

void MainWindow::scrollTo(Pos pos)
{
	if (ui.scrollArea->verticalScrollBar())
	{
		if (MAXIMUM == pos)
		{
			ui.scrollArea->verticalScrollBar()->setSliderPosition(
						ui.scrollArea->verticalScrollBar()->maximum());
		}
		if (MINIMUM == pos)
		{
			ui.scrollArea->verticalScrollBar()->setSliderPosition(
						ui.scrollArea->verticalScrollBar()->minimum());
		}
	}
}

void MainWindow::on_actionZoom_in_triggered()
{
	scale += 0.1f;
	updateDocument();
}

void MainWindow::on_actionZoom_out_triggered()
{
	if (scale >= 0.0f)
	{
		scale -= 0.1f;
		updateDocument();
	}
}

void MainWindow::updateDocument()
{
	ui.label->setPixmap(document->renderPage(currentPage,
											 physicalDpiX() * scale,
											 physicalDpiY() * scale));
	num.setNum(currentPage);
	statusBarLabel->setText("Page: " + num);
}

void MainWindow::on_actionGo_to_page_triggered()
{
	QDialog* dlg = new QDialog(this);
	dlg->setLayout(new QHBoxLayout(dlg));

	QLineEdit* lineEdit = new QLineEdit(dlg);
	lineEdit->setInputMask("0000000000");

	QPushButton* btn = new QPushButton(dlg);
	btn->setText("Ok");
	btn->setShortcut(QKeySequence("Enter"));
	connect(btn, SIGNAL(clicked()), dlg, SLOT(accept()));

	dlg->layout()->addWidget(lineEdit);
	dlg->layout()->addWidget(btn);
	dlg->exec();

	goToPage(lineEdit->text().toInt());
}

void MainWindow::goToPage(int pageNum)
{
	if (pageNum <= document->numPages())
	{
		currentPage = pageNum;
		updateDocument();
		scrollTo(MINIMUM);
	}
}

void MainWindow::on_actionCredits_triggered()
{
	QDialog* dlg = new QDialog(this);
	dlg->setLayout(new QHBoxLayout(dlg));
	QLabel* label = new QLabel(dlg);
	label->setText("Idea and coding: Cyril Bazhenov\n"
				   "Gentoo ebuild: Alexey Mamlin");
	dlg->layout()->addWidget(label);
	dlg->show();
}
void MainWindow::on_actionLicense_triggered()
{
	QDialog* dlg = new QDialog(this);
	dlg->setLayout(new QHBoxLayout(dlg));
	QLabel* label = new QLabel(dlg);
	label->setText("GNU General Public License version 3");
	dlg->layout()->addWidget(label);
	dlg->show();
}
