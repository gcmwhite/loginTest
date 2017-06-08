#include "widget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("登录界面"));         //设置窗口名

    userNameLabel = new QLabel(tr("用户名："));     //创建用户名和密码的QLabel对象
    passWordLabel = new QLabel(tr("密  码："));

    userNameLineEdit = new QLineEdit;       //创建用户名和密码输入框的QLineEdit对象
    passWordLineEdit = new QLineEdit;
    passWordLineEdit->setEchoMode(QLineEdit::Password);     //设置单行文本框显示方式为密码

    login = new QPushButton(tr("登录"));      //创建“登录”按键

    QGridLayout *mainLayout = new QGridLayout(this);        //创建格子布局方式
    mainLayout->addWidget(userNameLabel,0,0);       //添加userNameLabel到第0行0列，下面同理
    mainLayout->addWidget(passWordLabel,1,0);
    mainLayout->addWidget(userNameLineEdit,0,1);
    mainLayout->addWidget(passWordLineEdit,1,1);

    QHBoxLayout *hBoxLayout = new QHBoxLayout;   //新建行布局方式
    mainLayout->addLayout(hBoxLayout,2,0,1,2);  //将行布局添加到格子里的第2行0列，并占用1行两列的格子
    hBoxLayout->addStretch();           //在行布局中添加一个弹簧控件，用于占空位
    hBoxLayout->addWidget(login);       //将“登录”按钮添加到行布局中
    //将“登录”按钮和槽函数slotLogin()连接
    connect(login,SIGNAL(clicked()),this,SLOT(slotLogin()));
    //将密码框回车与槽函数slotLogin()连接
    connect(passWordLineEdit,SIGNAL(returnPressed()),this,SLOT(slotLogin()));
}

Widget::~Widget()
{
}

void Widget::slotLogin()
{
    qDebug() << "输入用户名：" << userNameLineEdit->text();       //输出调试信息
    qDebug() << "输入密码：" << passWordLineEdit->text();

    if (userNameLineEdit->text().operator ==("user") &&
            passWordLineEdit->text().operator ==("1234567890"))
    {
        qDebug() << "登录成功！";
        QMessageBox::information(this,tr("登录提示"),tr("登录成功"));
    }
    else
    {
        qDebug() << "用户名或密码错误！";
        QMessageBox::information(this,tr("登录提示"),tr("用户名或密码错误！"));
    }
}

