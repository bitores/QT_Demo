#ifndef IFBASE_H
#define IFBASE_H

#include "IFAbstract.h"

class CIFBase : public CIFAbstract
{
    Q_OBJECT
public:
    explicit CIFBase(QObject *parent = 0);//explicit防止隐式转换
    
signals:
    
public slots:
    
};

#endif // IFBASE_H
