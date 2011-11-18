#ifndef DOCUMENTFACTORY_HH
#define DOCUMENTFACTORY_HH

#include <QString>

class iDocument;

class DocumentFactory
{
public:

	/**
		Open a document
	*/
	static iDocument* openDocument(const QString& path);
};

#endif // DOCUMENTFACTORY_HH
