#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    QWebEngineView * pv = new QWebEngineView();
//        pv->setUrl(QUrl("http://www.baidu.com"));
//        pv->show();

    return a.exec();
}
