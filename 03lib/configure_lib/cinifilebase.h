#ifndef CINIFILEBASE_H
#define CINIFILEBASE_H

#include <QObject>
#include <QSettings>
#include <QString>

class CIniFileBase:public QObject
{
    Q_OBJECT
public:
    explicit CIniFileBase(QObject *parent = 0);
    virtual ~CIniFileBase();

public:
    int read(QString strFile = "");
    int write(QString strFile = "");

protected:
    bool checkFile(const QString& strFile);
    virtual void readData(QSettings &set)=0;
    virtual void writeData(QSettings &set)=0;
    void defaultFile(QString& str);
};

#endif // CINIFILEBASE_H
