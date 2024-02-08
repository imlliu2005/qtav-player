/*
 * @Description:
 * @Author: liuning
 * @LastEditors: liuning
 * @Date: 2023-12-29
 * @Copyright: 北京麦迪克斯科技有限公司
 * @LastEditTime: 2024-1-29
 * @FilePath: 
 */

#ifndef AV_PLAYER_H
#define AV_PLAYER_H

#include "QtAV/QtAV.h"
#include <QWidget>
#include <memory>

namespace medex {
    namespace av_player {
        static const int64_t SEEKMS = 10000;                   // 单位是毫秒
        class __declspec(dllexport) av_player : public QWidget
        {
            Q_OBJECT
        public:
            av_player(QString media_path, QWidget *parent = nullptr);
            ~av_player();

            // 播放控制
            void play();                                        // 播放视频
            void seek_forward(int64_t step_ms = SEEKMS);        // 快进10s
            void seek_backward(int64_t step_ms = SEEKMS);       // 快退10s 
            void play_pause();                                  // 开始或暂停
            void pause(bool value = true);                      // 是否暂停
            void set_speed(double value);                       // 设置播放速度 v[0.01, 20]
            void seek(int64_t value);                           // 定位播放进度条（进度条）
            void stop();                                        // 结束播放
            void set_midea_path(QString media_path);            // 设置媒体路径
            void set_seek_type(QtAV::SeekType type);
            bool is_seek_able();
            bool is_paused();
            bool is_playing();

            // 截屏相关暂时不需要
            void capture();                                     // 截屏
            void set_capture_dir(const QString& value);         // 截图保存路径
            void set_original_format(bool value = true);
            void set_save_format(const QString& format);
            void set_capture_name(const QString& value);
            void set_quality(int value);

            // qtav 视频属性
            int64_t get_position();                             // 当前位置
            int64_t get_duration();                             // 获取视频持续时长
            int notify_interval();                              // 获取播放步长ms
            int64_t media_start_position();                     // 媒体播放开始位置
            int64_t media_stop_position();                      // 媒体播放停止位置
            QWidget* video_widget();

        private:
            void init_av_player_signals();

        private:
            QWidget* video_widget_;                             // 视频播放窗口
            QtAV::VideoCapture* video_capture_;                 // 截图实例
            QtAV::AVPlayer* player_;            // 播放器接口实例
            QtAV::VideoOutput* video_output_;   // 视频渲染
            QString media_path_;

        signals:
            void start_signal();                                // 开始播放通知
            void notify_interval_changed_signal();              // 视频步长变化通知    
            void seek_finished_signal(int64_t value);           // 视频定位完成通知
            void media_status_changed_signal(QtAV::MediaStatus);// 媒体状态改变通知
            void buffer_progress_changed_signal(double value);  // 缓存内播放进度通知
            void error_signal(QtAV::AVError);                   // 错误通知
            void stop_signal();                                 // 停止播放通知
            void paused_signal(bool value);                     // 暂停播放通知   
            void speed_changed_signal(int64_t value);           // 播放速度改变通知
            void position_changed_signal(int64_t value);        // 播放位置改变通知
        };
    } // av_player
} // medex

#endif // AV_PLAYER_H