#include "tinteractobj.h"
#include <QDebug>

TInteractObj::TInteractObj(QObject *parent) : QObject(parent)
{

}
void TInteractObj::JSSendMessage(QString strParameter)
{
    qDebug() << __FUNCTION__;
    emit SigReceivedMessFromJS(strParameter);
}
