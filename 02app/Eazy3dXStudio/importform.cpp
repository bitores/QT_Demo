#include "importform.h"
#include "ui_importform.h"

#include <QMessageBox>

ImportForm::ImportForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportForm),
    sm_cfg(NULL)
{
    ui->setupUi(this);

//配置相关
   sm_cfg = CCfg::Instance();
   int ret = sm_cfg->readIni();
   outdir = sm_cfg->m_client.getProOutDir();
   importScriptdir = sm_cfg->m_client.getImportDir();

   ui->scriptPath->setText(importScriptdir);
   ui->projectPath->setText(outdir);

   connect(&cmd,SIGNAL(readyRead()),this,SLOT(pythonDebug()));
}

ImportForm::~ImportForm()
{
    delete ui;
}

void ImportForm::on_sourceCfg_clicked()
{

}

void ImportForm::on_projectCfg_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     outdir,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setProOutDir(path);
    outdir = path;
    ui->projectPath->setText(path);
    sm_cfg->writeIni();
}

void ImportForm::on_scriptCfg_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Directory"),
                                                     importScriptdir,tr("Python files (*.py)"));
    if(path.isEmpty())
        return;
    sm_cfg->m_client.setImportDir(path);
    importScriptdir = path;
    ui->scriptPath->setText(path);
    sm_cfg->writeIni();
}

void ImportForm::on_importBtn_clicked()
{
    QString sourcePath = ui->sourcePath->text();

    if(sourcePath.isEmpty() || outdir.isEmpty() || importScriptdir.isEmpty())
    {
        QMessageBox::information(this,"Error","参数不能为空...",QMessageBox::Ok);
        return;
    }
    QStringList arguments;
    arguments<<importScriptdir<<sourcePath<<outdir;
    cmd.execute("python",arguments);
}

void ImportForm::pythonDebug()
{
    trcDebug(cmd.readAll());
}
