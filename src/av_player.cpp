#include "av_player.h"
#include <QMessageBox>

av_player::av_player(QWidget *parent) : QWidget(parent)
{
    av_player_ = std::make_shared<QtAV::AVPlayer>(this);
    video_output_ = std::make_shared<QtAV::VideoOutput>(this);
    if (!video_output_->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    av_player_->setRenderer(video_output_.get());
}

av_player::~av_player()
{
}

void av_player::play(QString media_name)
{
    av_player_->play(media_name);
}

void av_player::seek_forward(int64_t step_ms)
{
    av_player_->seek(av_player_->position() + step_ms);
}

void av_player::seek_backward(int64_t step_ms)
{
    av_player_->seek(av_player_->position() - step_ms);
}

void av_player::play_pause()
{
    if (!av_player_->isPlaying()) {
        av_player_->play();
        return;
    }
    av_player_->pause(!av_player_->isPaused());
}

void av_player::set_frame_rate(double fsp)
{
    if (!av_player_)
    {
        return;
    }
    av_player_->setFrameRate(fsp);
}

double av_player::forced_frame_rate()
{
    return av_player_->forcedFrameRate();
}

void av_player::seek(int value)
{
    av_player_->setSeekType(QtAV::AccurateSeek);
    av_player_->seek((qint64)value);
}

void av_player::seek()
{
    // seek(mpTimeSlider->value());
}