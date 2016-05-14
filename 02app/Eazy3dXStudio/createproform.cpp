#include "createproform.h"
#include "ui_createproform.h"

#include <QMessageBox>

CreateProForm::CreateProForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateProForm),
    sm_cfg(NULL)
{
    ui->setupUi(this);

    //配置相关
       sm_cfg = CCfg::Instance();
       int ret = sm_cfg->readIni();
       createScriptdir = sm_cfg->m_client.getSDKDir();
       outdir = sm_cfg->m_client.getProOutDir();
       ui->outPath->setText(outdir);
       ui->scriptPath->setText(createScriptdir);

       connect(&cmd,SIGNAL(readyRead()),this,SLOT(pythonDebug()));
}

CreateProForm::~CreateProForm()
{
    delete ui;
}

void CreateProForm::on_outPathCfg_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     outdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setProOutDir(path);
    outdir = path;
    ui->outPath->setText(path);
    sm_cfg->writeIni();
}

void CreateProForm::on_scriptPathCfg_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Directory"),
                                                     createScriptdir,tr("Python files (*.py)"));
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setSDKDir(path);
    createScriptdir = path;
    ui->scriptPath->setText(path);
    sm_cfg->writeIni();
}

void CreateProForm::on_create_clicked()
{
    QString projectName = ui->projectName->text();
    QString serialName = ui->serialName->text();

    if(projectName.isEmpty() || createScriptdir.isEmpty() || outdir.isEmpty())
    {
        QMessageBox::information(this,"Error","参数不能为空...",QMessageBox::Ok);
        return;
    }

    if(serialName.isEmpty())
    {
        QStringList arguments;
        arguments<<createScriptdir<<"LWP"<<"-"<<projectName<<outdir;
        cmd.execute("python",arguments);
    }else{
        QStringList arguments;
        arguments<<createScriptdir<<"LWP"<<serialName<<projectName<<outdir;
        cmd.execute("python",arguments);
    }

}

void CreateProForm::pythonDebug()
{
    trcDebug(cmd.readAll());
}
