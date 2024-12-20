#include "zipreader.h"

QT_BEGIN_NAMESPACE_XLSX

ZipReader::ZipReader(const QString& filePath)
    : reader_(new QZipReader(filePath))
{
    Init();
}

ZipReader::ZipReader(QIODevice* device)
    : reader_(new QZipReader(device))
{
    Init();
}

void ZipReader::Init()
{
    const auto& files { reader_->fileInfoList() };
    for (const auto& file : files) {
        if (file.isFile || (!file.isDir && !file.isFile && !file.isSymLink))
            file_paths_.append(file.filePath);
    }
}

bool ZipReader::Exists() const { return reader_->exists(); }

QStringList ZipReader::FilePaths() const { return file_paths_; }

QByteArray ZipReader::FileData(const QString& file_name) const { return reader_->fileData(file_name); }

QT_END_NAMESPACE_XLSX
