#include "zipwriter.h"

QT_BEGIN_NAMESPACE_XLSX

ZipWriter::ZipWriter(const QString& file_path)
    : writer_(new QZipWriter(file_path, QIODevice::WriteOnly))
{
    writer_->setCompressionPolicy(QZipWriter::AutoCompress);
}

ZipWriter::ZipWriter(QIODevice* device)
    : writer_(new QZipWriter(device))
{
    writer_->setCompressionPolicy(QZipWriter::AutoCompress);
}

bool ZipWriter::Error() const { return writer_->status() != QZipWriter::NoError; }

void ZipWriter::AddFile(const QString& file_path, const QByteArray& data) { writer_->addFile(file_path, data); }

void ZipWriter::Close() { writer_->close(); }

QT_END_NAMESPACE_XLSX
