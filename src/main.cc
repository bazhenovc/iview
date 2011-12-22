#include <QtGui/QApplication>
#include "mainwindow.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
	if (argv[1])
		w.openDocument(argv[1]);
    w.show();

    return a.exec();
}
