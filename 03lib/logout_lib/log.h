#ifndef LOG_H
#define LOG_H

#include <QtCore/qglobal.h>
#include <QString>
#include <iostream>
using namespace std;

#if defined(LOGOUT_LIB_LIBRARY)
#  define LOGOUT_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGOUT_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

/*
 * 导出函数
*/
void LOGOUT_LIBSHARED_EXPORT trcFilePathSet(const QString& content);
void LOGOUT_LIBSHARED_EXPORT trcDebug(const QString& content);
void LOGOUT_LIBSHARED_EXPORT trcInfo(const QString& content);


//class LOGOUT_LIBSHARED_EXPORT Log
class Log
{

public:
    Log();
    ~Log();

public:
    static void debug(const QString& content);
    static void info(const QString& content);
    static void setFilePath(const QString& content);
private:
    static void out(const int& flag,const QString& content);
    static QString getFilePath();

private:
    static QString logFilePath; //静态成员变量一定要在类体外初始化
};

#endif // LOG_H
