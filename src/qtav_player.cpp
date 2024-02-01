#include "qtav_player.h"

qtav_player::qtav_player(QWidget* parent)
    : QMainWindow(parent)
{
    resize(800,600);
    player_ = new av_player(this);
    create_layout();
    init_connect();
}

qtav_player::~qtav_player()
{
    if (player_)
    {
        delete player_;
        player_ = nullptr;
    }
}

void qtav_player::run() 
{
    player_->play("D:/work/ffmpeg_rtsp/build/second.mp4");
}

void qtav_player::create_layout()
{
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    // 创建一个布局
    vb_layout_ = new QVBoxLayout(centralWidget);
    hb_layout_ = new QHBoxLayout(this);
    play_btn_ = new QPushButton("play", this);
    play_pause_btn_ = new QPushButton("play/pause", this);
    stop_btn_ = new QPushButton("stop", this);
    forward_btn_ = new QPushButton("forward", this);;
    backward_btn_ = new QPushButton("backward", this);;
    capture_btn_ = new QPushButton("capture", this);;

    vb_layout_->addWidget(player_->out_widget_);
    vb_layout_->addLayout(hb_layout_);
    hb_layout_->addWidget(play_btn_);
    hb_layout_->addWidget(play_pause_btn_);
    hb_layout_->addWidget(stop_btn_);
    hb_layout_->addWidget(forward_btn_);
    hb_layout_->addWidget(backward_btn_);
    hb_layout_->addWidget(capture_btn_);
}

void qtav_player::init_connect()
{
    connect(play_btn_, &QPushButton::clicked, [=](){
        pthread_ = new std::thread(std::bind(&qtav_player::run, this));
    });

    connect(stop_btn_, &QPushButton::clicked, [=](){
       player_->stop();
    });

    connect(play_pause_btn_, &QPushButton::clicked, [=](){
        player_->play_pause();
    });

    connect(forward_btn_, &QPushButton::clicked, [=](){
        player_->seek_forward();
    });

    connect(backward_btn_, &QPushButton::clicked, [=](){
        player_->seek_backward();
    });

    connect(capture_btn_, &QPushButton::clicked, [=](){

    });
}