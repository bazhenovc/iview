#-------------------------------------------------
#
# Project created by QtCreator 2011-11-17T21:51:25
#
#-------------------------------------------------

QT       += core gui

TARGET = iview
TEMPLATE = app

INCLUDEPATH += /usr/include/poppler/qt4
LIBS += -lpoppler -lpoppler-qt4

SOURCES += main.cc\
		mainwindow.cc \
	documentfactory.cc \
	popplerdocument.cc

HEADERS  += mainwindow.hh \
	idocument.hh \
	documentfactory.hh \
	popplerdocument.hh

FORMS    += mainwindow.ui







