#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>

//时间刷新
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //翻页
    int n;
    int page;
    QStringList strlist;

private:
    //实时时间
    //QLabel *label_;
    QTimer *timer_;

private:
    Ui::Widget *ui;
private slots:
    //实时时间
    void SltUpdateTime();
    void on_l_button_clicked();
    void on_r_button_clicked();
};
#endif // WIDGET_H
