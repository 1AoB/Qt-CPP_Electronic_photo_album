#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置图标
    setWindowIcon(QIcon(":/img/1.jpg"));
    //设置名字
    setWindowTitle("电子相册");

    //实时时间
    //(0,400,800,80); // 位置和大小
    //label_ = new QLabel(this);
    //label_->setStyleSheet("color:red ; background-color:rgb(0,0,0,0);");//前景色(指文字)是红色,背景色是白色
    //label_->setAlignment(Qt::AlignCenter);
    //label_->setGeometry(0,400,800,80);

    timer_ = new QTimer(this);
    timer_->start(1000);

    connect(timer_,&QTimer::timeout,this,&Widget::SltUpdateTime);
    
    n = 6;
    page = 1;
    for (int i = 0; i < n ; i++) {
        QString str;
        str = ":/img/"+QString::number(i+1)+".jpg";
        strlist.append(str);
    }
    QPixmap pix(strlist[page-1]);//":/img/1.jpg"
    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SltUpdateTime(){
    QDateTime now = QDateTime::currentDateTime();
    QString time_str = now.toString("yyyy-MM-dd hh:mm:ss");
    ui->lcd->display(time_str);
}


void Widget::on_l_button_clicked()
{
    page--;
    if(page < 1)
    {
        page++;
        QMessageBox::information(this,"提示","已经是第一张了");
        qDebug()<<"已经是第一张了";
    }else
    {
        QPixmap pix(strlist[page-1]);
        ui->label->setPixmap(pix);
    }
    qDebug()<<page;
}

void Widget::on_r_button_clicked()
{
    page++;
    if(page > n)
    {
        page--;
        QMessageBox::information(this,"提示","已经是最后一张了");
        //QMessageBox::warning(this, "警告", "666", QMessageBox::Ok, QMessageBox::No);
        qDebug()<<"已经是最后一张了";
    }else
    {
        QPixmap pix(strlist[page-1]);
        ui->label->setPixmap(pix);
    }
    qDebug()<<page;
}
