// xlsxcelllocation.h

#ifndef CELL_LOCATION_H
#define CELL_LOCATION_H

#include <QList>
#include <QMetaType>
#include <QObject>
#include <QString>
#include <QVector>
#include <memory>

#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class Cell;

class CellLocation {
public:
    CellLocation();

    int col;
    int row;

    std::shared_ptr<Cell> cell;
};

QT_END_NAMESPACE_XLSX
#endif
