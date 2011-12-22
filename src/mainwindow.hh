#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "ui_mainwindow.h"

class iDocument;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

	explicit
	MainWindow(QWidget *parent = 0);

	void openDocument(const QString& path);

private slots:
	void on_actionOpen_triggered();

	void on_actionQuit_triggered();

	void on_actionNext_page_triggered();

	void on_actionPrevious_page_triggered();

	void on_actionZoom_in_triggered();

	void on_actionZoom_out_triggered();

	void on_actionGo_to_page_triggered();

	void goToPage(int pageNum);

	void on_actionCredits_triggered();

	void on_actionLicense_triggered();

private:
	Ui::MainWindow ui;

	enum Pos
	{
		MINIMUM,
		MAXIMUM
	};

	void scrollTo(Pos pos);
	void updateDocument();

	iDocument* document;
	int currentPage;
	QLabel* statusBarLabel;
	float scale;
};

#endif // MAINWINDOW_HH
