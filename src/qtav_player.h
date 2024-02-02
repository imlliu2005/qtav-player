#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <thread>
#include "av_player.h"
using namespace medex;
class qtav_player : public QMainWindow {
    Q_OBJECT

public:
    qtav_player(QWidget* parent = nullptr);
    ~qtav_player();

private:
    void run();
    void create_layout();
    void init_connect();
    void update_slider(int64_t value);

private: 
    av_player* av_player_;
    std::thread* pthread_;
    int unit_step_;
    QPushButton* play_btn_;
    QPushButton* play_pause_btn_;
    QPushButton* stop_btn_;
    QPushButton* forward_btn_;
    QPushButton* backward_btn_;
    QPushButton* capture_btn_;
    QPushButton* speed2_btn_;
    QPushButton* speed05_btn_;
    QVBoxLayout *vb_layout_;
    QHBoxLayout *hb_layout_;
    QSlider* slider_;
};