#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsObject>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QDeclarativeItem>
#include <QMetaObject>
#include <QVBoxLayout>
#include <QFileInfoList>
#include <QImage>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QProcess>

#include "fontconvert.h"
#include "../../01public/config/ccfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
//    virtual resizeEvent(QResizeEvent *);
private:
    Ui::MainWindow *ui;

//----------def


public:
//   Q_INVOKABLE void exitApp();
    QString bg;
    QString path;
    QStringList otherimages;
    QStringList filelist;

    int bg_w;
    int bg_h;

    QString material;
    QString erect;
    QString gameobj;

    Fontconvert convert;


private:
    QDeclarativeView*  m_pView;
    QVBoxLayout *vbox;
    QDeclarativeItem *root;
    CCfg* sm_cfg ;

    QString sdkdir;
    QString prooutdir;
    QString releasedir;
    QString importdir;
    QString proPath;

    QProcess *cmd;


public:
    void createSceneXML(QString material,QString erect,QString gameobj);
    void initData();




private slots:
    void on_selBg_clicked();
    void on_selOther_clicked();
    void on_createScene_clicked();
    void on_fontconvt_clicked();
    void on_sdkconfig_clicked();
    void on_outdirconfig_clicked();
    void on_importdirconfig_clicked();
    void on_createBtn_clicked();

    void readmess();
    void on_importBtn_clicked();
    void on_pushButton_6_clicked();
    void on_propathBtn_clicked();
    void on_selectICO_clicked();
    void on_createICO_clicked();
};

#endif // MAINWINDOW_H


//# 最大正向匹配
//def conv(string,dic):
//    i = 0
//    while i < len(string):
//        for j in range(len(string) - i, 0, -1):
//            if string[i:][:j] in dic:
//                t = dic[string[i:][:j]]
//                string = string[:i] + t + string[i:][j:]
//                i += len(t) - 1
//                break
//        i += 1
//    return string

//# 生成转换字典
//def mdic():
//    table = open('ZhConversion.php','r').readlines()
//    dic = dict()
//    name = []
//    for line in table:
//        if line[0] == '$':
//            #print line.split()[0][1:]
//            name.append(dic)
//            dic = dict()
//        if line[0] == "'":
//            word = line.split("'")
//            dic[word[1]] = word[3]
//    name[3].update(name[1]) # 简繁通用转换规则(zh2Hant)加上台湾区域用法(zh2TW)
//    name[4].update(name[1]) # 简繁通用转换规则(zh2Hant)加上香港区域用法(zh2HK)
//    name[5].update(name[2]) # 繁简通用转换规则(zh2Hans)加上大陆区域用法(zh2CN)
//    return name[3],name[4],name[5]

//if __name__=="__main__":
//    a="头发发展萝卜卜卦秒表表达 "
//    b="大衛碧咸在寮國見到了布希"
//    c="大卫·贝克汉姆在老挝见到了布什"

//    [dic_TW,dic_HK,dic_CN] = mdic()
//    str_TW = conv(a,dic_TW)
//    str_HK = conv(c,dic_HK)
//    str_CN = conv(b,dic_CN)
//    print a, ' <-> ', str_TW, '\n', c, ' < -> ',str_HK,'\n', b,' < -> ',str_CN
