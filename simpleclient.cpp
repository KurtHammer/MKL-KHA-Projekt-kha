#include "simpleclient.h"
#include "chessboardwidget.h"
#include <iostream>
#include <QSettings>
#include <QCoreApplication>

Client::Client(ChessboardWidget *widget, QObject *parent): QObject(parent), Clientn(0), chessboardwidget(widget) {

   QSettings settings("MyCompany", "MyApp");
   Clientn = settings.value("ClientNumber", 0).toInt();
   ++Clientn; // Erhöhe den Wert von Clientn um eins
   settings.setValue("ClientNumber", Clientn);
   qDebug() << Clientn;
   client=new QTcpSocket;
   connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
   connect(chessboardwidget, &ChessboardWidget::buttonpressed, this, &Client::setneustart);
}

Client::~Client(){
  QSettings settings("MyCompany", "MyApp");
  client->close();
  client->deleteLater();
  Clientn = 0;
  settings.setValue("ClientNumber", Clientn);
  qDebug() << "Clientn im Destruktor: " << Clientn; // Debug-Ausgabe für Clientn im Destruktor
}


void Client::start( QString address, quint16 port )
{
    QHostAddress addr( address );
    client->connectToHost( addr, port );

    // Nach dem Verbindungsaufbau startTransfer() aufrufen
    connect(client, &QTcpSocket::connected, this, &Client::startTransfer);

}

void Client::startTransfer(){
  qDebug() << "verbindung"<< Clientn;
  sendData(NULL);
  return;
}


void Client::startRead(){

  char buffer[1024] = {0};
  QTcpSocket *sender = (QTcpSocket* ) QObject::sender();
  sender->read(buffer, sender->bytesAvailable());

  //Empfangenen String zum Debuggen ausgeben
  qDebug() << buffer;

  //Empfangenen String auswerten
  //ToDo
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
        QString combinedData = QString::number(Clientn) + "/" + data; // Kombiniere Clientn und data zu einem String
        client->write(combinedData.toUtf8());
    }
}

