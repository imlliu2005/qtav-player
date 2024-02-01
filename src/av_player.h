#ifndef AV_PLAYER_H
#define AV_PLAYER_H

#include "QtAV/QtAV.h"
#include <QWidget>
#include <memory>

static const int64_t SEEKMS = 10000;                   // 单位是毫秒

class av_player : public QWidget
{
    Q_OBJECT
public:
    av_player(QWidget *parent = nullptr);
    ~av_player();

    // 播放控制
    void play(QString media_name);                      // 播放视频
    void seek_forward(int64_t step_ms = SEEKMS);        // 快进10s
    void seek_backward(int64_t step_ms = SEEKMS);       // 快退10s 
    void play_pause();                                  // 开始或暂停
    void set_speed(double v);                           // 设置播放速度 v[0.01, 20]
    void seek(int value);                               // 拖拽进度条
    void stop();                                        // 结束播放

    // 截屏相关暂时不需要
    void capture();                                     // 截屏
    void set_capture_dir(const QString& value);         // 截图保存路径
    void set_original_format(bool value = true);
    void set_save_format(const QString& format);
    void set_capture_name(const QString& value);
    void set_quality(int value);

    // qtav 视频属性
    int64_t position();
    int64_t duration();
    int notify_interval();
    QWidget* video_widget();

private:
    void init_av_player_signals();

private:
    QWidget* video_widget_;                             // 视频播放窗口
    QtAV::VideoCapture* video_capture_;                 // 截图实例
    std::shared_ptr<QtAV::AVPlayer> player_;            // 播放器接口实例
    std::shared_ptr<QtAV::VideoOutput> video_output_;   // 视频渲染

signals:
    void start_signal();
    void notify_interval_changed_signal();
    void seek_finished_signal(int64_t value);
    void media_status_changed_signal(QtAV::MediaStatus);
    void buffer_progress_changed_signal(double value);
    void error_signal(QtAV::AVError);
    void stop_signal();
    void paused_signal(bool value);
    void speed_changed_signal(int64_t value);
    void position_changed_signal(int64_t value);
};

#endif // AV_PLAYER_H