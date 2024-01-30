#include "qtav_player.h"
#include "playerwindow.h"
#include  "QtAVWidgets/QtAVWidgets.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     qtav_player w;
//     w.show();
//     return a.exec();
// }

int main(int argc, char *argv[])
{
    QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);
    PlayerWindow player;
    player.show();
    player.resize(800, 600);
    return a.exec();
}