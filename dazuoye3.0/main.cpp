#include "mainscene.h"
#include "config.h"
#include <QApplication>
#include <QPainter>
#include "enemy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainScene w;

    w.show();


    return a.exec();
}
