#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "scenewidget.h"
#include "createproform.h"
#include "importform.h"



class SceneWidget;
class CreateProForm;
class ImportForm;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *event);
    ~MainWindow();



private slots:
    void on_turingTraditional_clicked();
    void cmdLog();

    void on_iconClear_clicked();


private:
    Ui::MainWindow *ui;
    QProcess cmd;
    SceneWidget scene;
    CreateProForm proCreate;
    ImportForm importform;



};

#endif // MAINWINDOW_H
