#include "qtav_player.h"
#include <QVBoxLayout>

qtav_player::qtav_player(QWidget* parent)
    : QMainWindow(parent)
{
    resize(800,600);
    my_player_ = new av_player(this);
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    // 创建一个布局
    QVBoxLayout *vb_layout = new QVBoxLayout(centralWidget);
    vb_layout->addWidget(my_player_->out_widget_);
    QHBoxLayout *hb_layout = new QHBoxLayout(this);
    vb_layout->addLayout(hb_layout);
    play_btn_ = new QPushButton("play", this);
    play_pause_btn_ = new QPushButton("play/pause", this);
    stop_btn_ = new QPushButton("stop", this);

    hb_layout->addWidget(play_btn_);
    hb_layout->addWidget(play_pause_btn_);
    hb_layout->addWidget(stop_btn_);
    connect(play_btn_, &QPushButton::clicked, [=](){
        pthread_ = new std::thread(std::bind(&qtav_player::run, this));
    });
}

qtav_player::~qtav_player()
{
    if (my_player_)
    {
        delete my_player_;
        my_player_ = nullptr;
    }
}

void qtav_player::run() 
{
    my_player_->play("D:/work/ffmpeg_rtsp/build/second.mp4");
}