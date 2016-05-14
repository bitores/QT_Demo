#include "ccfg.h"

CCfg::CCfg(QObject *parent) :
    QObject(parent)
  ,m_client(NULL)
{
}

CCfg* CCfg::m_cfg = NULL;

CCfg* CCfg::Instance()
{
    if(NULL==m_cfg)
    {
        m_cfg = new CCfg();
    }
    return m_cfg;
}

CCfg::~CCfg()
{

}

void CCfg::setDestDir(const QString &destdir)
{
    this->destDir = destdir;
}

void CCfg::setAppFileName(const QString &filename)
{
    this->appFileName = filename;
}

int CCfg::readIni()
{
    QString tmpPath = "";
    if(destDir.isEmpty()||appFileName.isEmpty())
        tmpPath.clear();
    else
        tmpPath = this->destDir+"/"+appFileName;
    if(m_client.read(tmpPath)!=0)
    {
        emit lack_of_file(tmpPath);
        return -1;
    }

//    tmpPath = this->destDir+"/"+xxFilename;
//    if(m_xx.read(tmpPath)>=0)
//    {
//        emit lack_of_file(tmpPth);
//        return;
//    }

    return 0;

}

int CCfg::writeIni()
{
    m_client.write();

    //other.write();

    return 0;
}
