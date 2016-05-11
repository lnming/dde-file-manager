#ifndef FILEINFO_H
#define FILEINFO_H

#include <QObject>
#include <QFileInfo>
#include <QUrl>
#include <QMimeType>

#include "utils/debugobejct.h"

#include "abstractfileinfo.h"

class FileInfo : public AbstractFileInfo
{
public:
    FileInfo();
    FileInfo(const QString& fileUrl);
    FileInfo(const DUrl& fileUrl);
    FileInfo(const QFileInfo &fileInfo);

    virtual void setFile(const DUrl &fileUrl);
    void setUrl(const DUrl &url) Q_DECL_OVERRIDE;

    static bool exists(const DUrl &fileUrl);
    static QMimeType mimeType(const QString &filePath);

    bool isCanRename() const Q_DECL_OVERRIDE;

    QString mimeTypeName() const Q_DECL_OVERRIDE;

    QIcon fileIcon() const Q_DECL_OVERRIDE;

private:
    using AbstractFileInfo::setUrl;
};

Q_DECLARE_METATYPE(FileInfo)

#endif // FILEINFO_H
