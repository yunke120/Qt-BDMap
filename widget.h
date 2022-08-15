#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineHistory>
#include <QWebEngineHistoryItem>
#include <QWebEnginePage>
#include <QWebEngineView>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

#include "tinteractobj.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:


    void on_pushButton_2_clicked();

signals:

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
