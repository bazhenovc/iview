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

SOURCES += src/main.cc\
		src/mainwindow.cc \
	src/documentfactory.cc \
	src/popplerdocument.cc

HEADERS  += src/mainwindow.hh \
	src/idocument.hh \
	src/documentfactory.hh \
	src/popplerdocument.hh

FORMS    += src/mainwindow.ui







