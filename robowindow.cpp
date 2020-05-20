#include "robowindow.h"
#include "mywidget.h"
RoboWindow::RoboWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,500);
  //菜单栏
    Qbar = menuBar();
  //工具栏
    Qtool = addToolBar("toolbar");
  //菜单内容
    //核心空间
    MyWidget *car = new MyWidget(this);
    setCentralWidget(car);

    /*底盘内容*/
    Qcar_menu = Qbar->addMenu("底盘");
    QAction *Qcar_where = Qcar_menu->addAction("底盘位置");
    connect(Qcar_where,&QAction::triggered,
            [=](){
                    qDebug() << "底盘位置";
                    car->show();
                 }
            );
    Qtool->addAction(Qcar_where);
    Qtool->addSeparator();
    /*机械臂内容*/
    Qhand_menu = Qbar->addMenu("机械臂");
    QAction *Qhand_where = Qhand_menu->addAction("机械臂位置");
    connect(Qhand_where,&QAction::triggered,
            [=](){
            qDebug() << "机械臂位置";
            car->hide();
            }
            );
    Qtool->addAction(Qhand_where);
    Qtool->addSeparator();
    /*摄像头内容*/
    Qcamera_menu = Qbar->addMenu("摄像头");
    QAction *Qcamera_show = Qcamera_menu->addAction("实时图像");
    connect(Qcamera_show,&QAction::triggered,
            [=](){
            qDebug() << "实时图像";
            car->hide();
            }
            );
    Qtool->addAction(Qcamera_show);
    //工具栏
    //状态栏
    QStatusBar *status = new QStatusBar(this);
    status->move(0,470);
    QLabel *label = new QLabel(this);
    label->setText("地图");
    status->addWidget(label);


}

RoboWindow::~RoboWindow()
{
}

