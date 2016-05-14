#ifndef INI_FILE_ABSTRACT_H
#define INI_FILE_ABSTRACT_H

#include <QObject>
#include <QtCore/qsettings.h>

class CIFAbstract : public QObject
{
    Q_OBJECT
public:
    explicit CIFAbstract(QObject *parent = 0);
    virtual ~CIFAbstract() = 0;
    
signals:
    
public slots:

public:
    int Read(QString strFile = "");
    int Write(QString strFile = "", bool bCoverIfExist = true, bool bEncrypt = false);

protected:
    int WriteUTF8(QSettings& set);

protected:
    virtual bool IsEncryptFile(const QString& strFile);
    virtual int ExistFile(const QString& strFile);    

    //以上函数基本上封装好,不需要子类重新实现
    //以下函数的框架和样例已封装好,基本上子类需要重新实现

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ReadData(QSettings& set);
    virtual int WriteData(QSettings& set);
    virtual void Clear();

    
};

#endif // INI_FILE_ABSTRACT_H
