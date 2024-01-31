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

    void play(QString media_name);                      // 播放视频
    void seek_forward(int64_t step_ms = SEEKMS);        // 快进10s
    void seek_backward(int64_t step_ms = SEEKMS);       // 快退10s 
    void play_pause();                                  // 开始或暂停
    void set_frame_rate(double fsp);                    // 设置播放帧数
    double forced_frame_rate();                         // 当前帧数    
    void seek(int value);                               // 拖拽进度条
    void seek();                                        // 点击进度条
    void stop();                                        // 结束播放

public:
    QWidget* out_widget_;

private:
    std::shared_ptr<QtAV::VideoOutput> video_output_;   // 视频渲染
    std::shared_ptr<QtAV::AVPlayer> av_player_;         // 播放器接口实例

signals:

};

#endif // AV_PLAYER_H