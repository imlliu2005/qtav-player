#include "qtav_player.h"
#include <QMessageBox>

qtav_player::qtav_player(QWidget* parent)
    : QMainWindow(parent)
{
    resize(800,600);
    unit_step_ = 1000;
    av_player_ = new av_player(this);
    create_layout();
    init_connect();
}

qtav_player::~qtav_player()
{
    if (av_player_)
    {
        delete av_player_;
        av_player_ = nullptr;
    }
}

void qtav_player::run() 
{
    av_player_->play("D:/work/ffmpeg_rtsp/build/second.mp4");
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
    forward_btn_ = new QPushButton("forward", this);
    backward_btn_ = new QPushButton("backward", this);
    capture_btn_ = new QPushButton("capture", this);
    speed2_btn_ = new QPushButton("2speed", this);
    speed05_btn_ = new QPushButton("0.5speed", this);
    slider_ = new QSlider(this);
    slider_->setOrientation(Qt::Horizontal);
    slider_->setMinimum(0);

    vb_layout_->addWidget(av_player_->video_widget());
    vb_layout_->addWidget(slider_);
    vb_layout_->addLayout(hb_layout_);
    hb_layout_->addWidget(play_btn_);
    hb_layout_->addWidget(play_pause_btn_);
    hb_layout_->addWidget(stop_btn_);
    hb_layout_->addWidget(forward_btn_);
    hb_layout_->addWidget(backward_btn_);
    hb_layout_->addWidget(capture_btn_);
    hb_layout_->addWidget(speed2_btn_);
    hb_layout_->addWidget(speed05_btn_);
}

void qtav_player::update_slider(int64_t value)
{
    slider_->setRange(0, int(av_player_->duration()/unit_step_));
    slider_->setValue(int(value/unit_step_));
}

void qtav_player::init_connect()
{
    connect(play_btn_, &QPushButton::clicked, [=](){
        pthread_ = new std::thread(std::bind(&qtav_player::run, this));
    });

    connect(stop_btn_, &QPushButton::clicked, [=](){
        av_player_->stop();
    });

    connect(play_pause_btn_, &QPushButton::clicked, [=](){
        av_player_->play_pause();
    });

    connect(forward_btn_, &QPushButton::clicked, [=](){
        av_player_->seek_forward();
    });

    connect(backward_btn_, &QPushButton::clicked, [=](){
        av_player_->seek_backward();
    });

    connect(capture_btn_, &QPushButton::clicked, [=](){
        av_player_->set_capture_dir("D:/");
        av_player_->capture();
    });

    connect(speed2_btn_, &QPushButton::clicked, [=](){
        av_player_->set_speed(2.0);
    });

    connect(speed05_btn_, &QPushButton::clicked, [=](){
        av_player_->set_speed(0.5);
    });

    // 进度条
    connect(slider_, &QSlider::sliderMoved, [=](int position){
        av_player_->seek(position);
    });
    
    connect(slider_, &QSlider::sliderPressed, [=](){
        av_player_->seek(slider_->value());
    });


    // qtav 信号处理
    connect(av_player_, &av_player::start_signal, [=](){
        update_slider(av_player_->position());
    });

    connect(av_player_, &av_player::position_changed_signal, [=](int64_t value){
        update_slider(value);
    });

    connect(av_player_, &av_player::notify_interval_changed_signal, [=](){
        unit_step_ = av_player_->notify_interval();
        update_slider(av_player_->position());
    });

    connect(av_player_, &av_player::seek_finished_signal, [=](int64_t value){
        
    });

    connect(av_player_, &av_player::media_status_changed_signal, [=](QtAV::MediaStatus value){
        
    });

    connect(av_player_, &av_player::buffer_progress_changed_signal, [=](double value){
        
    });

    connect(av_player_, &av_player::error_signal, [=](QtAV::AVError value){
        
    });

    connect(av_player_, &av_player::paused_signal, [=](bool value){
        
    });

    connect(av_player_, &av_player::speed_changed_signal, [=](int64_t value){
        
    });
}



