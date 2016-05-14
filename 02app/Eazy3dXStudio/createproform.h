#ifndef CREATEPROFORM_H
#define CREATEPROFORM_H

#include <QWidget>
#include <QFileDialog>
#include <QProcess>

#include "../../01public/config/ccfig.h"
#include "../../01public/logout/log.h"

namespace Ui {
class CreateProForm;
}

class CreateProForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateProForm(QWidget *parent = 0);
    ~CreateProForm();

private slots:
    void on_outPathCfg_clicked();
    void on_scriptPathCfg_clicked();
    void on_create_clicked();

    void pythonDebug();

private:
    Ui::CreateProForm *ui;
    QProcess cmd;

    CCfg* sm_cfg ;
    QString outdir;
    QString createScriptdir;
};

#endif // CREATEPROFORM_H
