#include "qtav_player.h"
#include <QMessageBox>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__) // 定义new宏来替换new关键字
#endif

qtav_player::qtav_player(QWidget* parent)
    : QWidget(parent)
{
    widget_ = nullptr;
    resize(800,600);
    unit_step_ = 1000;
    av_player_ = new av_player("D:/test/qtav-player/build/second.mp4", this);
    create_layout();
    init_connect();
}

qtav_player::~qtav_player()
{
    if (av_player_)
    {   
        // av_player_->stop();
        delete av_player_;
        av_player_ = nullptr;
    }
}

void qtav_player::run() 
{
    av_player_->play();
}

void qtav_player::create_layout()
{
    // 创建一个布局
    vb_layout_ = new QVBoxLayout(this);
    hb_layout_ = new QHBoxLayout(this);
    label_current_time_ = new QLabel("00:00:00", this);
    label_end_time_ = new QLabel("00:00:00", this);
    play_btn_ = new QPushButton("play", this);
    play_pause_btn_ = new QPushButton("play/pause", this);
    stop_btn_ = new QPushButton("stop", this);
    forward_btn_ = new QPushButton("forward", this);
    backward_btn_ = new QPushButton("backward", this);
    capture_btn_ = new QPushButton("capture", this);
    speed2_btn_ = new QPushButton("2speed", this);
    speed05_btn_ = new QPushButton("0.5speed", this);
    end_btn_ = new QPushButton("", this);
    slider_ = new Slider(this);
    slider_->setDisabled(true);
    slider_->setTracking(true);
    slider_->setOrientation(Qt::Horizontal);
    slider_->setMinimum(0);
    
    widget_ = av_player_->video_widget();
    // widget_->setParent(this);

    vb_layout_->addWidget(widget_);
    vb_layout_->addWidget(slider_);
    vb_layout_->addLayout(hb_layout_);
    hb_layout_->addWidget(label_current_time_);
    hb_layout_->addWidget(play_btn_);
    hb_layout_->addWidget(play_pause_btn_);
    hb_layout_->addWidget(stop_btn_);
    hb_layout_->addWidget(forward_btn_);
    hb_layout_->addWidget(backward_btn_);
    hb_layout_->addWidget(capture_btn_);
    hb_layout_->addWidget(speed2_btn_);
    hb_layout_->addWidget(speed05_btn_);
    hb_layout_->addWidget(label_end_time_);
    hb_layout_->addWidget(end_btn_);
}

void qtav_player::init_connect()
{
    connect(play_btn_, &QPushButton::clicked, [=](){
        // pthread_ = new std::thread(std::bind(&qtav_player::run, this));
        static std::thread t(std::bind(&qtav_player::run, this));
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
    connect(slider_, &Slider::sliderMoved, [=](int get_position){
        av_player_->set_seek_type(QtAV::AccurateSeek);
        av_player_->seek((qint64)get_position);
    });
    
    connect(slider_, &Slider::sliderPressed, [=](){
        av_player_->seek(slider_->value());
    });

    // qtav 信号处理
    connect(av_player_, &av_player::start_signal, [=](){
        slider_->setMinimum(av_player_->media_start_position());
        slider_->setMaximum(av_player_->media_stop_position());
        slider_->setValue(0);
        slider_->setEnabled(av_player_->is_seek_able());
        label_end_time_->setText(QTime(0, 0, 0).addMSecs(av_player_->media_stop_position()).toString(QString::fromLatin1("HH:mm:ss")));
    });

    connect(av_player_, &av_player::stop_signal, [=](){
        slider_->setMinimum(0);
        slider_->setMaximum(0);
        slider_->setValue(0);
        slider_->setDisabled(true);
        label_current_time_->setText(QString::fromLatin1("00:00:00"));
        label_end_time_->setText(QString::fromLatin1("00:00:00"));
    });

    connect(av_player_, &av_player::position_changed_signal, [=](int64_t value){
        if (av_player_->is_seek_able())
        {
            slider_->setValue(value);
        } 
        label_current_time_->setText(QTime(0, 0, 0).addMSecs(value).toString(QString::fromLatin1("HH:mm:ss")));
    });

    connect(av_player_, &av_player::notify_interval_changed_signal, [=](){

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



