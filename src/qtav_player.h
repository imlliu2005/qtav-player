#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <thread>
#include "av_player.h"

class qtav_player : public QMainWindow {
    Q_OBJECT

public:
    qtav_player(QWidget* parent = nullptr);
    ~qtav_player();

private:
    void run();
    void create_layout();
    void init_connect();

private: 
    av_player* player_;
    std::thread* pthread_;

    QPushButton* play_btn_;
    QPushButton* play_pause_btn_;
    QPushButton* stop_btn_;
    QPushButton* forward_btn_;
    QPushButton* backward_btn_;
    QPushButton* capture_btn_;

    QVBoxLayout *vb_layout_;
    QHBoxLayout *hb_layout_;
    
};