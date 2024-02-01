/******************************************************************************
    Simple Player:  this file is part of QtAV examples
    Copyright (C) 2012-2016 Wang Bin <wbsecg1@gmail.com>

*   This file is part of QtAV

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QWidget>
#include "QtAV/QtAV.h"

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE
static const int64_t kSeekMS = 10000; // 单位是毫秒
class PlayerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerWindow(QWidget *parent = 0);
public Q_SLOTS:
    void openMedia();
    void seekBySlider(int value);
    void seekBySlider();
    void playPause();
private Q_SLOTS:
    void updateSlider(qint64 value);
    void updateSlider();
    void updateSliderUnit();
    void setFrameRate(double speed);    // 倍速播放
    void setFrameRate2();    // 倍速播放
    void setFrameRate02();    // 倍速播放
    void seekForward(int64_t step_ms = 10000);
    void seekBackward(int64_t step_ms = 10000);


private:
    QtAV::VideoOutput *m_vo;
    QtAV::AVPlayer *m_player;
    
    QSlider *m_slider;
    QPushButton *m_openBtn;
    QPushButton *m_playBtn;
    QPushButton *m_stopBtn;
    QPushButton *m_forwardBtn;
    QPushButton *m_backwardBtn;
    QPushButton *m_2SpeedBtn;
    QPushButton *m_02speedBtn;
    QPushButton *m_capture;
    int m_unit;
};

#endif // PLAYERWINDOW_H
