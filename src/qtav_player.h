#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "slider.h"
#include <thread>
#include "av_player.h"

using namespace  medex::av_player;
class qtav_player : public QWidget {
    Q_OBJECT

public:
    qtav_player(QWidget* parent = nullptr);
    ~qtav_player();

private:
    void run();
    void create_layout();
    void init_connect();

private: 
    av_player* av_player_;
    QWidget* widget_;
    // std::thread* pthread_;
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
    Slider* slider_;
    QLabel* label_current_time_;
    QLabel* label_end_time_;
    QPushButton* end_btn_;
};