#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QImage>
#include <QPixmap>
#include <QLabel>
class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void SubSolt();
signals:
    /*信号必须有signals关键字来表明
      信号没有返回值，但可以有参数
      信号就是函数的申明，只需申明无需定义
      使用方法:emit mySignal();
      信号可以重载
    */
    void subSignal();
    void subSignal(int,QString);
private:
    QPushButton *b4;
    QImage *image;
    QLabel *label;
};

#endif // SUBWIDGET_H
