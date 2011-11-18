
#include "documentfactory.hh"

#include "popplerdocument.hh"

iDocument* DocumentFactory::openDocument(const QString &path)
{
	return new PopplerDocument(path);
}
