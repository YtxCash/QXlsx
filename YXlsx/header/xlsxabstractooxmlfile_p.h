// xlsxabstractooxmlfile_p.h

#ifndef ABSTRACTOOXMLFILEPRIVATE_H
#define ABSTRACTOOXMLFILEPRIVATE_H

#include "xlsxabstractooxmlfile.h"

QT_BEGIN_NAMESPACE_XLSX

class AbstractOOXmlFilePrivate {
    Q_DECLARE_PUBLIC(AbstractOOXmlFile)

public:
    AbstractOOXmlFilePrivate(AbstractOOXmlFile* q, AbstractOOXmlFile::CreateFlag flag);
    virtual ~AbstractOOXmlFilePrivate();

public:
    QString filePathInPackage; // such as "xl/worksheets/sheet1.xml"

    Relationships* relationships;
    AbstractOOXmlFile::CreateFlag flag;
    AbstractOOXmlFile* q_ptr;
};

QT_END_NAMESPACE_XLSX

#endif // ABSTRACTOOXMLFILEPRIVATE_H
