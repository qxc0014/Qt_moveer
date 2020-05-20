#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <subwidget.h>
#include <QDebug>
#include <QTextEdit>//文本编辑器
#include <QDialog>//对话框
#include <QMessageBox>
class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    void robolocate_on();
    void robolocate_off();
    void Debug(int,QString);
    ~MyWidget();
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    SubWidget *sub1;
};
#endif // MYWIDGET_H
