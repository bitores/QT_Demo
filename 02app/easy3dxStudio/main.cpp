#include <QObject>
#include <QApplication>
#include <qtextcodec.h>
#include <qmessagebox.h>
#include <QString>
#include <QDebug>
#include "../../01public/qtsingleapplication/qtsingleapplication.h"
#include "../../01public/config/ccfig.h"
#include "mainwindow.h"




#define VERSION "V1.1.0"

void showMsg(QString str)
{
    QMessageBox box;
    box.setText(str);
    box.exec();
}

class MessBox;


class MessBox:public QObject{
    Q_OBJECT
public:
    explicit MessBox(QObject* parent =0){}
    ~MessBox(){
        if(NULL!=sm_msgbox)
            delete sm_msgbox;
    }

    static MessBox* Instance(){
        if(NULL==sm_msgbox)
            sm_msgbox = new MessBox();
        return sm_msgbox;
    }

public slots:
    void getANDshowMsg(QString& str)
    {
        this->msg = str;
       showMsg(str);
    }

   friend void showMsg(QString str);

private:
    static MessBox* sm_msgbox;
    QString msg;
};
MessBox* MessBox::sm_msgbox = NULL;

int main(int argc, char *argv[])
{
    QtSingleApplication::addLibraryPath("./plugins");
    QtSingleApplication app("my_appid",argc, argv);
    //保证IDE应用程序输出中文显示正常
//    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    //设置编辑器中字符串和用tr包含的字符采用UTF-8编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

//    Processor w;
//    app.connect(&w,SIGNAL(app_exit()),&app,SLOT(quit()));
    MainWindow w;
    w.show();

    return app.exec();
}
