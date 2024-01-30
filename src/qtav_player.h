#pragma once
#include <QMainWindow>

class qtav_player : public QMainWindow {
    Q_OBJECT

public:
    qtav_player(QWidget* parent = nullptr);
    ~qtav_player();
};