#ifndef TINTERACTOBJ_H
#define TINTERACTOBJ_H

#include <QObject>

class TInteractObj : public QObject
{
    Q_OBJECT
public:
    explicit TInteractObj(QObject *parent = nullptr);

    Q_INVOKABLE void JSSendMessage(QString strParameter);

signals:
    void SigReceivedMessFromJS(QString strParameter);
     //该信号名必须与js中接收函数同名
     void SigSendMessageToJS(QString strParameter);
public slots:
};

#endif // TINTERACTOBJ_H
