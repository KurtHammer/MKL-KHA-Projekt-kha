#include <QCoreApplication>
#include "simpleServer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;

    return a.exec();
}
