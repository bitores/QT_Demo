#include "cifapp.h"
#include "../../01public/logout/log.h"

CIFApp::CIFApp(QObject *parent):
    CIniFileBase(parent)
{
}

CIFApp::~CIFApp()
{
}

//virtual
void CIFApp::readData(QSettings& set)
{
    trcInfo("开始读["+set.fileName()+"]配置");
    readApp(set);
    readWindow(set);
    readAddress(set);
    readScriptDir(set);
    trcInfo("结束读["+set.fileName()+"]配置");
}

//virtual
void CIFApp::writeData(QSettings& set)
{
    trcInfo("开始写["+set.fileName()+"]配置");
    writeApp(set);
    writeWindow(set);
    writeAddress(set);
    writeScriptDir(set);
    trcInfo("结束写["+set.fileName()+"]配置");
}

void CIFApp::readApp(QSettings& set)
{
    set.beginGroup("Application");
    m_app.company = set.value("company","").toString();
    m_app.author = set.value("author","").toString();
    m_app.version = set.value("version","").toString();
    m_app.describe = set.value("describe","").toString();
    set.endGroup();
}

void CIFApp::writeApp(QSettings& set)
{
    set.beginGroup("Application");
    set.setValue("company",QVariant(m_app.company));
    set.setValue("author",QVariant(m_app.author));
    set.setValue("version",QVariant(m_app.version));
    set.setValue("describe",QVariant(m_app.describe));
    set.endGroup();
}

void CIFApp::readWindow(QSettings& set)
{
    set.beginGroup("MainWindow");
    m_window.posion = set.value("posion",QPoint(0,0)).toPoint();
    m_window.size = set.value("size",QSize(0,0)).toSize();
    m_window.fullscreen = set.value("fullscreen",false).toBool();
    set.endGroup();
}

void CIFApp::writeWindow(QSettings& set)
{
    set.beginGroup("MainWindow");
    set.setValue("posion",QVariant(m_window.posion));
    set.setValue("size",QVariant(m_window.size));
    set.setValue("fullscreen",QVariant(m_window.fullscreen));
    set.endGroup();
}

void CIFApp::readAddress(QSettings& set)
{
    set.beginGroup("Address");
    m_address.ip = set.value("ip","").toString();
    m_address.port = set.value("port",0).toInt();
    set.endGroup();
}

void CIFApp::writeAddress(QSettings& set)
{
    set.beginGroup("Address");
    set.setValue("ip",QVariant(m_address.ip));
    set.setValue("port",QVariant(m_address.port));
    set.endGroup();
}

void CIFApp::readScriptDir(QSettings& set)
{
    set.beginGroup("Script");
    m_script.sdkdir = set.value("sdk.dir").toString();
    m_script.prooutdir = set.value("out.dir").toString();
    m_script.releasedir = set.value("release.dir").toString();
    m_script.importdir = set.value("import.dir").toString();
    set.endGroup();
}

void CIFApp::writeScriptDir(QSettings& set)
{
    set.beginGroup("Script");
    set.setValue("sdk.dir",QVariant(m_script.sdkdir));
    set.setValue("out.dir",QVariant(m_script.prooutdir));
    set.setValue("release.dir",QVariant(m_script.releasedir));
    set.setValue("import.dir",QVariant(m_script.importdir));
    set.endGroup();
}

QString CIFApp::getCompany()
{
    return this->m_app.company;
}

void CIFApp::setCompany(const QString& company)//传入参数用const修饰，除了
{
    this->m_app.company = company;
}

QString CIFApp::getAuthor()
{
    return this->m_app.author;
}

void CIFApp::setAuthor(const QString& author)
{
    this->m_app.author = author;
}

QString CIFApp::getVersion()
{
    return this->m_app.version;
}

void CIFApp::setVersion(const QString& version)
{
    this->m_app.version = version;
}

QString CIFApp::getDescribe()
{
    return this->m_app.describe;
}

void CIFApp::setDescribe(const QString& describe)
{
    this->m_app.describe = describe;
}

QPoint CIFApp::getPosion()
{
    return this->m_window.posion;
}

void CIFApp::setPosion(const QPoint& point)
{
    this->m_window.posion = point;
}

QSize CIFApp::getSize()
{
    return this->m_window.size;
}

void CIFApp::setSize(const QSize& size)
{
    this->m_window.size = size;
}

bool CIFApp::getFullscreen()
{
    return this->m_window.fullscreen;
}

void CIFApp::setFullscreen(const bool& flag)
{
    this->m_window.fullscreen = flag;
}

QString CIFApp::getIP()
{
    return this->m_address.ip;
}

void CIFApp::setIP(const QString& ip)
{
    this->m_address.ip = ip;
}

int CIFApp::getPort()
{
    return this->m_address.port;
}

void CIFApp::setPort(const int& port)
{
    this->m_address.port = port;
}

QString CIFApp::getSDKDir()
{
    return this->m_script.sdkdir;
}

void CIFApp::setSDKDir(QString path)
{
    this->m_script.sdkdir = path;
}

QString CIFApp::getProOutDir()
{
    return this->m_script.prooutdir;
}
void CIFApp::setProOutDir(QString path)
{
    this->m_script.prooutdir = path;
}
QString CIFApp::getReleaseDir()
{
    return this->m_script.releasedir;
}
void CIFApp::setReleaseDir(QString path)
{
    this->m_script.releasedir = path;
}
QString CIFApp::getImportDir()
{
    return this->m_script.importdir;
}
void CIFApp::setImportDir(QString path)
{
    this->m_script.importdir = path;
}

