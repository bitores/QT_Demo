#ifndef PARTICLEWIDGET_H
#define PARTICLEWIDGET_H

#include <QWidget>

namespace Ui {
class ParticleWidget;
}

class ParticleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParticleWidget(QWidget *parent = 0);
    ~ParticleWidget();

private:
    Ui::ParticleWidget *ui;
};

#endif // PARTICLEWIDGET_H
