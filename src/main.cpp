
// #include  "QtAVWidgets/QtAVWidgets.h"

#include <QApplication>
#include "qtav_player.h"

#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    // QtAV::Widgets::registerRenderers();
    QApplication a(argc, argv);
    qtav_player player;
    player.show();
    return a.exec();
}