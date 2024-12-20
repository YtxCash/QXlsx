// xlsxcellreference.h

#ifndef XLSX_XLSXCELLREFERENCE_H
#define XLSX_XLSXCELLREFERENCE_H

#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class CellReference {
public:
    CellReference();
    /*!
        Constructs the Reference from the given \a row, and \a column.
    */
    constexpr CellReference(int row, int column)
        : _row(row)
        , _column(column)
    {
    }
    CellReference(const QString& cell);
    CellReference(const char* cell);
    CellReference(const CellReference& other);
    ~CellReference();

    QString toString(bool row_abs = false, bool col_abs = false) const;
    bool isValid() const;
    inline void setRow(int row) { _row = row; }
    inline void setColumn(int col) { _column = col; }
    inline int row() const { return _row; }
    inline int column() const { return _column; }

    inline bool operator==(const CellReference& other) const { return _row == other._row && _column == other._column; }
    inline bool operator!=(const CellReference& other) const { return _row != other._row || _column != other._column; }

    inline bool operator>(const CellReference& other) const { return _row > other._row || _column != other._column; }

private:
    void init(const QString& cell);
    int _row { -1 };
    int _column { -1 };
};

QT_END_NAMESPACE_XLSX

Q_DECLARE_TYPEINFO(xlsx::CellReference, Q_MOVABLE_TYPE);

#endif // XLSX_XLSXCELLREFERENCE_H
