#include "qtav_player.h"
#include "player_window.h"
// #include  "QtAVWidgets/QtAVWidgets.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    // QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);
    qtav_player player;
    // PlayerWindow player;
    player.show();
    return a.exec();
}