#ifndef XML_FILE_ABSTRACT_H
#define XML_FILE_ABSTRACT_H

#include <QObject>
#include <QtCore/qfile.h>
#include <QtXml/qdom.h>

class CXFAbstract : public QObject
{
    Q_OBJECT
public:
    explicit CXFAbstract(QObject *parent = 0);
    virtual ~CXFAbstract() = 0;

public:
    int Read(QString strFile = "");
    int Write(QString strFile, bool bCoverIfExist = true);

protected:
    virtual int ExistFile(const QString& strFile);
    virtual int OpenFile(QFile& file, const QString& strFile);
    virtual int SetContent(QFile& file, QDomDocument& qdoc, const QString& strFile);
    virtual int ParseRoot(const QDomDocument& qdoc, QDomElement& deRoot, const QString& strFile);

    //以上函数基本上封装好,不需要子类重新实现
    //以下函数的框架和样例已封装好,基本上子类需要重新实现

protected:
    virtual int CheckFile(QString& strFile);
    virtual int ParseXml(const QDomDocument& qdoc, const QString& strFile);
    virtual int ParseNode(const QDomElement& deParent, QDomElement& deThis, const QString& strNodeName, const QString& strFile);

    virtual int SaveXml(const QFile& file);

    
signals:
    
public slots:
    
};

#endif // XML_FILE_ABSTRACT_H
