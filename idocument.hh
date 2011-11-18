#ifndef IDOCUMENT_HH
#define IDOCUMENT_HH

#include <QPixmap>
#include <QString>

class iDocument
{
public:

	virtual QPixmap renderPage(int page, float dpiX, float dpiY)
	{
		Q_UNUSED(page);
		Q_UNUSED(dpiX);
		Q_UNUSED(dpiY);
		return QPixmap();
	}

	virtual bool load(const QString& path)
	{
		Q_UNUSED(path);
		return false;
	}

	virtual int numPages() const
	{
		return 0;
	}
};

#endif // IDOCUMENT_HH
