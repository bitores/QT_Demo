#include "particlewidget.h"
#include "ui_particlewidget.h"

ParticleWidget::ParticleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParticleWidget)
{
    ui->setupUi(this);
}

ParticleWidget::~ParticleWidget()
{
    delete ui;
}
