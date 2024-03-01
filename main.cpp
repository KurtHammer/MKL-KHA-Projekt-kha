#include <QApplication>
#include "simpleClient.h"
#include "simpleclient.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChessboardWidget chessboardwidget;
    chessboardwidget.show();

    Client client(&chessboardwidget); // Hier wird der Client mit dem ChessboardWidget initialisiert
    client.start("127.0.0.1", 8888);
    return a.exec();


}
