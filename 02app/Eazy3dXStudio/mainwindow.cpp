#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>
#include <QList>
#include <QPixmap>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QProcess>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <qdebug.h>

#include "../../01public/logout/log.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //icon
    ui->iconLabel->installEventFilter(this);
    ui->iconLabel->setAcceptDrops(true); // [[1]]: 使label可接受拖放操作
    //screenshot
    ui->screenshotLabel->installEventFilter(this);
    ui->screenshotLabel->setAcceptDrops(true); // [[1]]: 使label可接受拖放操作

    connect(&cmd,SIGNAL(readyRead()),this,SLOT(cmdLog()));

    //scene
    ui->scrollArea->setWidget(&scene);
    ui->scrollArea->resize(scene.size());

    //create pro
    ui->createProArea->setWidget(&proCreate);
    //import
    ui->importArea->setWidget(&importform);



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->iconLabel) {
        QFileInfo file("icon_create.py");
        if(!file.exists())
        {
            trcDebug("icon_create.py does not exist!");
            return false;
        }
        if (event->type() == QEvent::DragEnter) {
            // [[2]]: 当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            // [[3]]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            QString path = urls.first().toLocalFile();

            // [[4]]: 在label上显示拖放的图片
            QImage image(path); // QImage对I/O优化过, QPixmap对显示优化
            if (!image.isNull()) {
                ui->iconLabel->setPixmap(QPixmap::fromImage(image));
                QStringList arguments;
                QFileInfo file(path);
                arguments<<"icon_create.py"<<file.absolutePath()<<file.fileName();
                cmd.start("python",arguments);//非阻塞
                int flag = cmd.execute("python",arguments);//阻塞
                switch (flag) {
                case -1:
                   ui->statusBar->showMessage("The process crashes");
                    break;
                case -2:
                    ui->statusBar->showMessage("The process cannot be started");
                default:
                    ui->statusBar->showMessage("Icon to create success");
                    break;
                }
            }

            return true;
        }
    }else if(watched == ui->screenshotLabel){
        QFileInfo file("screenshot_create.py");
        if(!file.exists())
        {
            trcDebug("screenshot_create.py does not exist!");
            return false;
        }
        if (event->type() == QEvent::DragEnter) {
            // [[2]]: 当拖放时鼠标进入label时, label接受拖放的动作
            QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
            dee->acceptProposedAction();
            return true;
        } else if (event->type() == QEvent::Drop) {
            // [[3]]: 当放操作发生后, 取得拖放的数据
            QDropEvent *de = dynamic_cast<QDropEvent *>(event);
            QList<QUrl> urls = de->mimeData()->urls();

            if (urls.isEmpty()) { return true; }
            foreach (QUrl file, urls) {
                QString path = file.toLocalFile();

                // [[4]]: 在label上显示拖放的图片
                QImage image(path); // QImage对I/O优化过, QPixmap对显示优化
                if (!image.isNull()) {
                    ui->screenshotLabel->setPixmap(QPixmap::fromImage(image));

                    QStringList arguments;
                    QFileInfo file(path);
                    arguments<<"screenshot_create.py"<<file.absolutePath()<<file.fileName();
                    cmd.execute("python",arguments);//非阻塞
                    int flag = cmd.execute("python",arguments);//阻塞
                    switch (flag) {
                    case -1:
                       ui->statusBar->showMessage("The process crashes");
                        break;
                    case -2:
                        ui->statusBar->showMessage("The process cannot be started");
                    default:
                        ui->statusBar->showMessage("Icon to create success");
                        break;
                    }
                }

            }
            return true;
        }

    }

    return QWidget::eventFilter(watched, event);
}

void MainWindow::on_turingTraditional_clicked()
{
    QString info = ui->simple->text();
    if(info.isEmpty())
    {
        QMessageBox::information(this,"Error","参数不能为空...",QMessageBox::Ok);
        return;
    }
    QProcess cmd;
    QStringList arguments;
    arguments<<"font.py";
    cmd.execute("python",arguments);//非阻塞
}


void MainWindow::cmdLog()
{
    trcInfo(cmd.readAll());
}

void MainWindow::on_iconClear_clicked()
{
    ui->iconLabel->clear();
}
