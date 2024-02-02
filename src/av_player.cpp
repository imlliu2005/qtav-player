#include "av_player.h"
#include <QMessageBox>

namespace medex {
    
av_player::av_player(QWidget *parent) : QWidget(parent)
{
    player_ = std::make_shared<QtAV::AVPlayer>(this);
    video_output_ = std::make_shared<QtAV::VideoOutput>(this);
    if (!video_output_->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    player_->setRenderer(video_output_.get());
    video_widget_ = video_output_->widget();
    video_capture_ = player_->videoCapture();
    init_av_player_signals();
}

av_player::~av_player()
{
    if(video_capture_) 
    {
        delete video_capture_;
        video_capture_ = nullptr;
    }

     if(video_widget_) 
    {
        delete video_widget_;
        video_widget_ = nullptr;
    }
}

QWidget* av_player::video_widget()
{
    return video_widget_;
}

void av_player::play(QString media_name)
{
    player_->play(media_name);
}

void av_player::seek_forward(int64_t step_ms)
{
    player_->seek(player_->position() + step_ms);
}

void av_player::seek_backward(int64_t step_ms)
{
    player_->seek(player_->position() - step_ms);
}

void av_player::play_pause()
{
    if (!player_->isPlaying()) {
        player_->play();
        return;
    }
    player_->pause(!player_->isPaused());
}

void av_player::seek(int value)
{
    player_->setSeekType(QtAV::AccurateSeek);
    player_->seek((qint64)value);
}

void av_player::stop()
{
    player_->stop();
}

void av_player::set_speed(double v)
{
    if (!player_)
    {
        return;
    }
    player_->setSpeed(v);
}

void av_player::capture()
{
    video_capture_->capture();
}

void av_player::set_original_format(bool value)
{
    video_capture_->setOriginalFormat(value);
}

void av_player::set_save_format(const QString& format)
{
    video_capture_->setSaveFormat(format);
}

void av_player::set_capture_dir(const QString& value)
{
    video_capture_->setCaptureDir(value);
}

void av_player::set_capture_name(const QString& value)
{
    video_capture_->setCaptureName(value);
}

void av_player::set_quality(int value)
{
    video_capture_->setQuality(value);
}

int64_t av_player::duration()
{
    return player_->duration();
}

int64_t av_player::position()
{
    return player_->position();
}

int av_player::notify_interval()
{
    return player_->notifyInterval();
}

int64_t av_player::media_start_position()
{
    return player_->mediaStartPosition();
}

int64_t av_player::media_stop_position()
{
    return player_->mediaStopPosition();
}

void av_player::init_av_player_signals()
{
    connect(player_.get(), &QtAV::AVPlayer::positionChanged, this, &av_player::position_changed_signal);
    connect(player_.get(), &QtAV::AVPlayer::started, this, &av_player::start_signal);
    connect(player_.get(), &QtAV::AVPlayer::notifyIntervalChanged, this, &av_player::notify_interval_changed_signal);
    connect(player_.get(), &QtAV::AVPlayer::seekFinished, this, &av_player::seek_finished_signal);
    connect(player_.get(), &QtAV::AVPlayer::mediaStatusChanged, this, &av_player::media_status_changed_signal);
    connect(player_.get(), &QtAV::AVPlayer::bufferProgressChanged, this, &av_player::buffer_progress_changed_signal);
    connect(player_.get(), &QtAV::AVPlayer::error, this, &av_player::error_signal);
    connect(player_.get(), &QtAV::AVPlayer::stopped, this, &av_player::stop_signal);
    connect(player_.get(), &QtAV::AVPlayer::paused, this, &av_player::paused_signal);
    connect(player_.get(), &QtAV::AVPlayer::speedChanged, this, &av_player::speed_changed_signal);
}
} // medex