#ifndef XML_FILE_BASE_H
#define XML_FILE_BASE_H

#include "XFAbstract.h"

class CXFBase : public CXFAbstract
{
    Q_OBJECT
public:
    explicit CXFBase(QObject *parent = 0);
    ~CXFBase();

//public:
//    int Read(QString strfile = "");
//    int Write(QString strfile = "");

    
signals:
    
public slots:
    
};

#endif // XML_FILE_BASE_H
