#ifndef ROBOWINDOW_H
#define ROBOWINDOW_H

#include <QMainWindow>
#include <QMenuBar>//菜单栏
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
class RoboWindow : public QMainWindow
{
    Q_OBJECT

public:
    RoboWindow(QWidget *parent = nullptr);
    ~RoboWindow();
private:
    //QWidget *Qcar_wid;
    QMenuBar *Qbar;
    QMenu *Qcar_menu;
    QMenu *Qhand_menu;
    QMenu *Qcamera_menu;
    QToolBar *Qtool;
};
#endif // ROBOWINDOW_H
