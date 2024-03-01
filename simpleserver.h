// simpleserver.h
#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server: public QObject
{
    Q_OBJECT
public:
    Server(QObject * parent = 0);
    ~Server();

public slots:
    void acceptConnection();
    void startRead();
    void handlebuttonpress();
    void Neustart(int cl);
private:
    QTcpServer *server;
    QTcpSocket* socket;
    QList<QTcpSocket*> clients;
};

#endif // SIMPLESERVER_H
