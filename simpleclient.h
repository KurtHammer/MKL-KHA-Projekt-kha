#ifndef SIMPLECLIENT_H
#define SIMPLECLIENT_H

#include "chessboardwidget.h"
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>

class Client: public QObject
{
    Q_OBJECT
    public:
      int Clientn;
      bool neustart;
      Client(ChessboardWidget *widget,QObject* parent = 0);
      ~Client();
      void start( QString address, quint16 port );
      void sendData(const QString &data);
    public slots:
      void startTransfer();
      void startRead();
      void setneustart();
    private:
      QTcpSocket *client;
      ChessboardWidget *chessboardwidget;
};

#endif // SIMPLECLIENT_H
