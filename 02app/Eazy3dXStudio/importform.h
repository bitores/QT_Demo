#ifndef IMPORTFORM_H
#define IMPORTFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QProcess>


#include "../../01public/config/ccfig.h"
#include "../../01public/logout/log.h"

namespace Ui {
class ImportForm;
}

class ImportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImportForm(QWidget *parent = 0);
    ~ImportForm();

private slots:
    void on_sourceCfg_clicked();
    void on_projectCfg_clicked();
    void on_scriptCfg_clicked();
    void on_importBtn_clicked();

    void pythonDebug();

private:
    Ui::ImportForm *ui;
    QProcess cmd;

    CCfg* sm_cfg ;
    QString outdir;
    QString importScriptdir;
    QString releasedir;
};

#endif // IMPORTFORM_H
