/*
 * @Description:
 * @Author: liuning
 * @LastEditors: liuning
 * @Date: 2023-12-29
 * @Copyright: 北京麦迪克斯科技有限公司
 * @LastEditTime: 2024-1-29
 * @FilePath: 
 */

#include "av_player.h"
#include <QMessageBox>

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__) // 定义new宏来替换new关键字
#endif

namespace medex {
    namespace av_player {
        av_player::av_player(QString media_path, QWidget *parent) : QWidget(parent), player_(nullptr)
        {
            player_ = new QtAV::AVPlayer(this);
            video_output_ = new QtAV::VideoOutput(this);
            if (!video_output_->widget()) {
                QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
                return;
            }
            media_path_ = media_path;
            player_->setRenderer(video_output_);
            video_widget_ = video_output_->widget();
            video_capture_ = player_->videoCapture();
            init_av_player_signals();
        }

        av_player::~av_player()
        {
            if (player_) {
                player_->stop();
                delete player_;
                player_ = nullptr;
            }

            if (video_output_) {
                delete video_output_;
                video_output_ = nullptr;
            }
        }

        QWidget* av_player::video_widget()
        {
            return video_widget_;
        }

        void av_player::play()
        {
            player_->play(media_path_);
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

        void av_player::pause(bool value)
        {
            player_->pause(value);
        }

        bool av_player::is_paused()
        {
            return player_->isPaused();
        }


        bool av_player::is_playing()
        {
            return player_->isPlaying();
        }


        void av_player::seek(int64_t value)
        {
            player_->setSeekType(QtAV::AccurateSeek);
            player_->seek(value);
        }

        void av_player::set_seek_type(QtAV::SeekType type)
        {
            player_->setSeekType(type);
        }

        bool av_player::is_seek_able()
        {
            return player_->isSeekable();
        }

        void av_player::stop()
        {
            player_->stop();
        }

        void av_player::set_speed(double value)
        {
            player_->setSpeed(value);
        }

        void av_player::set_midea_path(QString media_path)
        {
            media_path_ = media_path;
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

        int64_t av_player::get_duration()
        {
            return player_->duration();
        }

        int64_t av_player::get_position()
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
            connect(player_, &QtAV::AVPlayer::positionChanged, this, &av_player::position_changed_signal);
            connect(player_, &QtAV::AVPlayer::started, this, &av_player::start_signal);
            connect(player_, &QtAV::AVPlayer::notifyIntervalChanged, this, &av_player::notify_interval_changed_signal);
            connect(player_, &QtAV::AVPlayer::seekFinished, this, &av_player::seek_finished_signal);
            connect(player_, &QtAV::AVPlayer::mediaStatusChanged, this, &av_player::media_status_changed_signal);
            connect(player_, &QtAV::AVPlayer::bufferProgressChanged, this, &av_player::buffer_progress_changed_signal);
            connect(player_, &QtAV::AVPlayer::error, this, &av_player::error_signal);
            connect(player_, &QtAV::AVPlayer::stopped, this, &av_player::stop_signal);
            connect(player_, &QtAV::AVPlayer::paused, this, &av_player::paused_signal);
            connect(player_, &QtAV::AVPlayer::speedChanged, this, &av_player::speed_changed_signal);
        }   
    }
} // medex