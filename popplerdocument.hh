#ifndef POPPLERDOCUMENT_HH
#define POPPLERDOCUMENT_HH

#include "idocument.hh"

#include <poppler-qt4.h>

class PopplerDocument : public iDocument
{
public:

	PopplerDocument();

	PopplerDocument(const QString& path);

	virtual ~PopplerDocument();

	virtual QPixmap renderPage(int page, float dpiX, float dpiY);

	virtual bool load(const QString &path);

	virtual int numPages() const;

private:
	Poppler::Document* document;
};

#endif // POPPLERDOCUMENT_HH
