#ifndef ZIPWRITER_H
#define ZIPWRITER_H

#include <private/qzipwriter_p.h>

#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class ZipWriter {
public:
    explicit ZipWriter(const QString& file_path);
    explicit ZipWriter(QIODevice* device);
    ~ZipWriter() = default;

    void AddFile(const QString& file_path, const QByteArray& data);
    bool Error() const;
    void Close();

private:
    QScopedPointer<QZipWriter> writer_ {};
};

QT_END_NAMESPACE_XLSX

#endif // ZIPWRITER_H
