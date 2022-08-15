#include "widget.h"
#include "ui_widget.h"
#include <QStringLiteral>
#include <QMap>

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


void Widget::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();
    QString lon1 = str.split(",")[0];
    QString lat1 = str.split(",")[1];
    QString lon2 = str.split(",")[2];
    QString lat2 = str.split(",")[3];
    QString cmd=QString("drawLine(%1,%2,%3,%4)").arg(lon1).arg(lat1).arg(lon2).arg(lat2);
//    qDebug() << cmd;
    ui->widget->page()->runJavaScript(cmd);
}
