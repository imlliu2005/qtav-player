#pragma once
#include <QMainWindow>
#include "av_player.h"
#include <QPushButton>
#include <thread>

class qtav_player : public QMainWindow {
    Q_OBJECT

public:
    qtav_player(QWidget* parent = nullptr);
    ~qtav_player();

private:
    void run();

private: 
    av_player* my_player_;
    QPushButton* play_btn_;
    QPushButton* play_pause_btn_;
    QPushButton* stop_btn_;

    std::thread* pthread_;
};