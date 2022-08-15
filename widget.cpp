// refer:
// https://forum.qt.io/topic/70968/qwebchannel-js-uncaught-referenceerror-qt-is-not-defined/14
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFile>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString htmlPath = QCoreApplication::applicationDirPath() + "/html/";
    QString htmlFile = htmlPath + "index.html";
    qDebug() << htmlFile;
    QFile file(htmlFile);
    if(!file.exists())
        qDebug() << "html file is not exist";
    QWebChannel *webChannel = new QWebChannel(ui->widget->page());
    ui->widget->page()->setWebChannel(webChannel);
    webChannel->registerObject(QString("JSInterface"), ui->widget);

    ui->widget->page()->load(QUrl("file:///" + htmlFile));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    QString lon = str.split(",")[0];
    QString lat = str.split(",")[1];
    QString cmd=QString("myMarker(%1,%2)").arg(lon).arg(lat);
    qDebug() << cmd;
    ui->widget->page()->runJavaScript(cmd);
}
