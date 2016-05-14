#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "scenewidget.h"

class SceneWidget;
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

private:
    Ui::MainWindow *ui;
    QProcess cmd;
    SceneWidget scene;
};

#endif // MAINWINDOW_H
