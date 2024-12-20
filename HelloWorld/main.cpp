#include <QCoreApplication>
#include <QDir>

#include "xlsxdocument.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    //--------------------------------------
    // [1]  Writing excel file(*.xlsx)

    xlsx::Document document_write {};

    int row = 1;
    int col = 1;

    // write "Hello Qt!" to cell(A,1).
    QVariant value { "Hello Qt!" };
    document_write.write(row, col, value);

    if (document_write.saveAs("Test.xlsx")) // save the document as 'Test.xlsx'
    {
        qDebug() << "[debug] success to write xlsx file";
    } else {
        qDebug() << "[debug][error] failed to write xlsx file";
        exit(-1);
    }

    qDebug() << "[debug] current directory is " << QDir::currentPath();

    //--------------------------------------
    // [2] Reading excel file(*.xlsx)

    xlsx::Document document_read("Test.xlsx");
    if (document_read.load()) {
        qDebug() << "[debug] success to load xlsx file.";

        auto cell { document_read.cellAt(row, col) };
        if (cell != NULL) {
            QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
            qDebug() << "[debug] cell(1,1) is " << var; // Display value. It is 'Hello Qt!'.
        } else {
            qDebug() << "[debug][error] cell(1,1) is not set.";
            exit(-2);
        }
    } else {
        qDebug() << "[debug][error] failed to load xlsx file.";
    }

    return 0;
}
