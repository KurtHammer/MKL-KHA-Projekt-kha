#include "simpleclient.h"
#include "chessboardwidget.h"
#include <QSettings>
#include <QCoreApplication>

Client::Client(/*ChessboardWidget *widget,*/ QObject *parent): QObject(parent)/*, chessboardwidget(widget) */{

   client=new QTcpSocket;
   connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
   connect(chessboardwidget, &ChessboardWidget::buttonpressed, this, &Client::setneustart);
   connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
}

Client::~Client(){
  client->close();
  client->deleteLater();
}


void Client::start( QString address, quint16 port )
{
    QHostAddress addr( address );
    client->connectToHost( addr, port );

    // Nach dem Verbindungsaufbau startTransfer() aufrufen
    connect(client, &QTcpSocket::connected, this, &Client::startTransfer);

}

void Client::startTransfer(){
  sendData("hallo server");
  return;
}


void Client::startRead(){
    QTcpSocket *sender = qobject_cast<QTcpSocket*>(QObject::sender());
    QByteArray buffer = sender->readAll();

    // Empfangenen Daten zum Debuggen ausgeben
    qDebug() << "Received data from server:" << buffer;

    // Empfangene Daten auswerten
    // ToDo: Implementieren Sie die Logik, um die empfangenen Daten zu verarbeiten
}

void Client::setneustart(){
    qDebug() << "neustart in client";
    QString sui("neustart");
   /* if (client->state() == QAbstractSocket::ConnectedState) {
        client->write(sui.toUtf8());
    }*/
    sendData(sui);
}

void Client::sendData(const QString &data) {
    if (client->state() == QAbstractSocket::ConnectedState) {
        client->write(data.toUtf8());
    }
}

