// xlsxabstractooxmlfile.h

#ifndef ABSTRACTOOXMLFILE_H
#define ABSTRACTOOXMLFILE_H

#include "xlsxglobal.h"
#include "xlsxrelationships_p.h"

QT_BEGIN_NAMESPACE_XLSX

class AbstractOOXmlFilePrivate;

class AbstractOOXmlFile {
    Q_DECLARE_PRIVATE(AbstractOOXmlFile)

public:
    enum CreateFlag { F_NewFromScratch, F_LoadFromExists };

public:
    virtual ~AbstractOOXmlFile();

    virtual void saveToXmlFile(QIODevice* device) const = 0;
    virtual bool loadFromXmlFile(QIODevice* device) = 0;

    virtual QByteArray saveToXmlData() const;
    virtual bool loadFromXmlData(const QByteArray& data);

    Relationships* relationships() const;

    void setFilePath(const QString path);
    QString filePath() const;

protected:
    AbstractOOXmlFile(CreateFlag flag);
    AbstractOOXmlFile(AbstractOOXmlFilePrivate* d);

    AbstractOOXmlFilePrivate* d_ptr {};
};

QT_END_NAMESPACE_XLSX

#endif // ABSTRACTOOXMLFILE_H
