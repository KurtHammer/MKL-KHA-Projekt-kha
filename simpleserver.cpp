// simpleserver.cpp
#include "simpleServer.h"
#include <QDateTime>
#include <iostream>
#include <string>

Server::Server(QObject* parent): QObject(parent)
{
    server = new QTcpServer;
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    server->listen(QHostAddress::Any, 8888);
}

Server::~Server()
{
    server->close();
    server->deleteLater();
}

void Server::acceptConnection()
{
    qDebug() << "New Connection";
    clients.append(server->nextPendingConnection());
    connect(clients.last(),SIGNAL(readyRead()),this,SLOT(startRead()));
}

void Server::startRead()
{
    bool ok = true;
    QTcpSocket* readSocket = qobject_cast<QTcpSocket*>(sender());
    if (!readSocket)
        return;

    QByteArray buffer = readSocket->readAll();

    QString mytext = QString::fromUtf8(buffer);

    qDebug() << "Received data from client:" << mytext;

    int pos = mytext.indexOf('/');
    QString resultr = mytext.mid(pos + 1);
    int poS = mytext.indexOf('/');
    QString resultl = mytext.left(poS);

    if(resultr == "neustart"){
        Neustart(resultl.toInt(&ok));
    }

}

void Server::handlebuttonpress()
{
    // Aktion ausführen, wenn das Button-Druck-Signal empfangen wird
    qDebug() << "Button gedrückt!";
}

void Server::Neustart(int cl){
    qDebug() << "neustart gedrückt!" << cl;
}
