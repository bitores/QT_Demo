#ifndef CCFG_H
#define CCFG_H


#include <QtCore/qglobal.h>
#include "cifapp.h"

#if defined(CONFIGURE_LIB_LIBRARY)
#  define CONFIGURE_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CONFIGURE_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class CONFIGURE_LIBSHARED_EXPORT CCfg : public QObject
{
    Q_OBJECT
public:
    static CCfg* Instance();
    ~CCfg();

private:
    explicit CCfg(QObject *parent = 0);

signals:
    void lack_of_file(QString& filepath);

public slots:

public:
    void setDestDir(const QString& destdir);
    void setAppFileName(const QString& filename);

public:
    int readIni();
    int writeIni();

private:
    static CCfg* m_cfg;
    QString destDir;
    QString appFileName;

public:
    CIFApp  m_client;

};

#endif // CCFG_H
