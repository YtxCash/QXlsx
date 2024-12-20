#ifndef ZIPREADER_H
#define ZIPREADER_H

#include <private/qzipreader_p.h>

#include "xlsxglobal.h"

QT_BEGIN_NAMESPACE_XLSX

class ZipReader {
public:
    explicit ZipReader(const QString& fileName);
    explicit ZipReader(QIODevice* device);

    ZipReader(const ZipReader&) = delete;
    ZipReader& operator=(const ZipReader&) = delete;
    ~ZipReader() = default;

    bool Exists() const;
    QStringList FilePaths() const;
    QByteArray FileData(const QString& file_name) const;

private:
    void Init();

private:
    QScopedPointer<QZipReader> reader_ {};
    QStringList file_paths_ {};
};

QT_END_NAMESPACE_XLSX

#endif // ZIPREADER_H
