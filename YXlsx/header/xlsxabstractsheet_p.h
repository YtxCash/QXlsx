// xlsxabstractsheet_p/h

#ifndef XLSXABSTRACTSHEETPRIVATE_H
#define XLSXABSTRACTSHEETPRIVATE_H

#include <QString>

#include "xlsxabstractooxmlfile_p.h"
#include "xlsxabstractsheet.h"
#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class AbstractSheetPrivate : public AbstractOOXmlFilePrivate {
    Q_DECLARE_PUBLIC(AbstractSheet)
public:
    AbstractSheetPrivate(AbstractSheet* p, AbstractSheet::CreateFlag flag);
    ~AbstractSheetPrivate();

    Workbook* workbook;

    QString name;
    int id;
    AbstractSheet::SheetState sheetState;
    AbstractSheet::SheetType type;
};

QT_END_NAMESPACE_XLSX

#endif // XLSXABSTRACTSHEETPRIVATE_H
