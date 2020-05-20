 #include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*设置主窗口参数*/
    this->resize(800,500);//窗口大小
    this->move(10,40);//窗口位置
    this->setWindowTitle("机器人控制台");

    /*设置机器人位置按钮*/
    b1.setParent(this);
    b1.setText("机器人位置");
    b1.move(10,15);
    sub1 = new SubWidget();

    /*显示子窗口，隐藏主窗口*/
    /*使用lambda表达式，可以不需要再用成员函数的形式写槽函数*/
    connect(&b1,&QPushButton::pressed,
            [=]()//[=]的意思是把局部变量、类中所有成员变量全部传入、[&b1]则只把b1传入
                 //[this]类中所有成员以值传递方式
                 //[&]把所有局部变量以以引用的方式传入
            {
                sub1->show();
                this->hide();
                qDebug() << "lambda表达式" ;
            }
            );
    connect(&b1,&QPushButton::pressed,this,&MyWidget::robolocate_on);
    /*显示主窗口，隐藏主窗口*/
    void (SubWidget::*subfunc1)() = &SubWidget::subSignal;//函数指针
    connect(sub1,subfunc1,this,&MyWidget::robolocate_off);

    void (SubWidget::*subfunc2)(int,QString) = &SubWidget::subSignal;//函数指针
    connect(sub1,subfunc2,this,&MyWidget::Debug);

    /*设置机器人状态按钮*/
    b2 = new QPushButton(this);
    b2->setText("机器人状态");
    b2->move(10,65);
    connect(b2,&QPushButton::pressed,
            [=](){
             QDialog *qdia = new QDialog(this);
             qdia->setWindowTitle("机器人状态");
             qdia->resize(500,300);
             qdia->exec();//模态窗口
            }
            );

    b3 = new QPushButton(this);
    b3->setText("关闭窗口");
    b3->move(710,420);
    connect(b3,&QPushButton::pressed,this,&MyWidget::close);
    //b3：信号发出者的指针
    //&QPushButton::pressed：信号发出的类型
    //this:信号接受者的指针
    //&MyWidget::close：槽函数
    QTextEdit *qtext = new QTextEdit(this);
    qtext->move(100,15);
    qtext->resize(500,30);

    b4 = new QPushButton(this);
    b4->setText("地图路径");
    b4->move(10,115);
    connect(b4,&QPushButton::pressed,
            [=](){
                  QMessageBox::about(this,"地图路径","请输入地图路径");//对话框
                }
            );
}

MyWidget::~MyWidget()
{
}

void MyWidget::robolocate_on(){
    sub1->show();
    this->hide();
}
void MyWidget::robolocate_off(){
    sub1->hide();
    this->show();
}
void MyWidget::Debug(int a, QString b){
    qDebug() << a << b;
}
