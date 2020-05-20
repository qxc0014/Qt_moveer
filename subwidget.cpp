#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(600,500);
    this->move(100,100);
    this->setWindowTitle("机器人位置");
    b4 = new QPushButton(this);
    b4->setParent(this);
    b4->setText("返回控制台");
    b4->move(500,450);
    connect(b4,&QPushButton::pressed,this,&SubWidget::SubSolt);

    QImage *image=new QImage("/home/esoman/guiji.png");

    QLabel *label=new QLabel(this);
    label->move(0,0);
    label->setGeometry(0,0,500,500);
    label->setPixmap(QPixmap::fromImage(*image));
    label->show();

}
void SubWidget::SubSolt()
{
    emit subSignal();
    emit subSignal(516,"my birthday");
}
