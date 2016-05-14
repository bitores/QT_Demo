#include "mainwindow.h"
#include <QApplication>
#include <qtextcodec.h>
#include <qmessagebox.h>
#include <QString>
#include <QDebug>

#include "../../01public/logout/log.h"

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
    QApplication::addLibraryPath("./plugins");
    trcInfo("load plugins");
    QApplication app(argc, argv);
    //设置编辑器中字符串和用tr包含的字符采用UTF-8编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    trcInfo("set codec UTF-8");
    trcInfo("界面启动");
    MainWindow w;
    w.show();

    return app.exec();
}
