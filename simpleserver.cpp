// simpleserver.cpp
#include "simpleServer.h"
#include <QDateTime>
#include <QDataStream>

Server::Server(QObject* parent): QObject(parent)
{
    server = new QTcpServer;
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    server->listen(QHostAddress::Any, 8888);
    Index = -1;
}

Server::~Server()
{
    server->close();
    server->deleteLater();
}

void Server::acceptConnection()
{
    Index++;
    qDebug() << "New Connection with" << Index;
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

    qDebug() << "Received data from client:" << Index;
    qDebug() << mytext;
    if (!clients.isEmpty()) {
        sendMessageToClient(Index, "Hello Client!");
    }

    int pos = mytext.indexOf('/');
    QString resultr = mytext.mid(pos + 1);
    int poS = mytext.indexOf('/');
    QString resultl = mytext.left(poS);

    if(resultr == "neustart"){
        Neustart(resultl.toInt(&ok));
    }

}

void Server::sendToClient(QTcpSocket *socket, const QString &message) {
   // QDataStream out(socket);
//    out << (message.toUtf8());

    socket->write(message.toUtf8());

}

void Server::sendMessageToClient(int clientIndex, const QString &message) {
        if (clientIndex >= 0 && clientIndex < clients.size()) {
        QTcpSocket *clientSocket = clients.at(clientIndex);
            sendToClient(clientSocket, message);
        }
        else{
            qDebug() << "Ungültiger Client-Index";
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
