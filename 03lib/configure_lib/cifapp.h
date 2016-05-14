#ifndef CIFAPP_H
#define CIFAPP_H

#include <QPoint>
#include <QSize>
#include "cinifilebase.h"
#include <QtCore/qglobal.h>

#if defined(CONFIGURE_LIB_LIBRARY)
#  define CONFIGURE_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CONFIGURE_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

class CONFIGURE_LIBSHARED_EXPORT CIFApp : public CIniFileBase
{
    Q_OBJECT
public:
    explicit CIFApp(QObject *parent = 0);
    virtual ~CIFApp();

public:
    QString getCompany();
    void setCompany(const QString& company);
    QString getAuthor();
    void setAuthor(const QString& author);
    QString getVersion();
    void setVersion(const QString& version);
    QString getDescribe();
    void setDescribe(const QString& describe);
    QPoint getPosion();
    void setPosion(const QPoint& point);
    QSize getSize();
    void setSize(const QSize& size);
    bool getFullscreen();
    void setFullscreen(const bool& flag);
    QString getIP();
    void setIP(const QString& ip);
    int getPort();
    void setPort(const int& port);

    QString getSDKDir();
    void setSDKDir(QString path);
    QString getProOutDir();
    void setProOutDir(QString path);
    QString getReleaseDir();
    void setReleaseDir(QString path);
    QString getImportDir();
    void setImportDir(QString path);




protected:
    void readData(QSettings &set);
    void writeData(QSettings &set);

public:
    void readApp(QSettings& set);
    void writeApp(QSettings& set);
    void readWindow(QSettings& set);
    void writeWindow(QSettings& set);
    void readAddress(QSettings& set);
    void writeAddress(QSettings& set);
    void readScriptDir(QSettings& set);
    void writeScriptDir(QSettings& set);


private:
    struct CIPApp{
        QString company;
        QString author;
        QString version;
        QString describe;
    }  m_app;

    struct CIPMainWindow{
        QPoint posion;       //window start point
        QSize  size;        //window's width and height
        bool   fullscreen;  //window's screen
    }  m_window;

    struct CIPAddress{
        QString ip;
        int port;
    }  m_address;

    struct CIPScript {
        QString sdkdir;
        QString prooutdir;
        QString releasedir;
        QString importdir;
    } m_script;
};

#endif // CIFAPP_H

