
#include "popplerdocument.hh"

#include <QApplication>
#include <QDesktopWidget>

PopplerDocument::PopplerDocument()
	: document(NULL)
{}

PopplerDocument::PopplerDocument(const QString &path)
	: document(NULL)
{
	load(path);
}

PopplerDocument::~PopplerDocument()
{
	if (document)
		delete document;
}

QPixmap PopplerDocument::renderPage(int pageNum, float dpiX, float dpiY)
{
	if (document)
	{
		if (pageNum < document->numPages())
		{
			Poppler::Page* page = document->page(pageNum);
			QImage img = page->renderToImage(dpiX, dpiY);
			delete page;
			return QPixmap::fromImage(img);
		}
	}
	return QPixmap();
}

bool PopplerDocument::load(const QString &path)
{
	if (document)
	{
		delete document;
	}
	document = Poppler::Document::load(path);
	return document != NULL;
}

int PopplerDocument::numPages() const
{
	if (document)
		return document->numPages();
	return 0;
}
