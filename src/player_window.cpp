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

#include "player_window.h"
#include <QPushButton>
#include <QSlider>
#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>

using namespace QtAV;

PlayerWindow::PlayerWindow(QWidget *parent) : QWidget(parent)
{
    m_unit = 1000;
    setWindowTitle(QString::fromLatin1("QtAV simple player example"));
    m_player = new AVPlayer(this);
    QVBoxLayout *vl = new QVBoxLayout();
    setLayout(vl);
    m_vo = new VideoOutput(this);
    if (!m_vo->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    m_player->setRenderer(m_vo);
    vl->addWidget(m_vo->widget());
    m_slider = new QSlider();
    m_slider->setOrientation(Qt::Horizontal);
    connect(m_slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
    connect(m_slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(m_player, SIGNAL(started()), SLOT(updateSlider()));
    connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));

    vl->addWidget(m_slider);
    QHBoxLayout *hb = new QHBoxLayout();
    vl->addLayout(hb);
    m_openBtn = new QPushButton(tr("Open"));
    m_playBtn = new QPushButton(tr("Play/Pause"));
    m_stopBtn = new QPushButton(tr("Stop"));
    m_forwardBtn = new QPushButton(tr("forward10s"));
    m_backwardBtn = new QPushButton(tr("Back10s"));
    m_2SpeedBtn = new QPushButton(tr("2Speed"));
    m_02speedBtn = new QPushButton(tr("0.2Speed"));
    m_capture = new QPushButton(tr("Capture"));


    hb->addWidget(m_openBtn);
    hb->addWidget(m_playBtn);
    hb->addWidget(m_stopBtn);
    hb->addWidget(m_forwardBtn);
    hb->addWidget(m_backwardBtn);
    hb->addWidget(m_2SpeedBtn);
    hb->addWidget(m_02speedBtn);
    hb->addWidget(m_capture);

    connect(m_openBtn, SIGNAL(clicked()), SLOT(openMedia()));
    connect(m_playBtn, SIGNAL(clicked()), SLOT(playPause()));
    connect(m_stopBtn, SIGNAL(click/ed()), m_player, SLOT(stop()));
    connect(m_forwardBtn, SIGNAL(clicked()), SLOT(seekForward()));
    connect(m_backwardBtn, SIGNAL(clicked()), SLOT(seekBackward()));
    connect(m_2SpeedBtn, SIGNAL(clicked()), SLOT(setFrameRate2()));
    connect(m_02speedBtn, SIGNAL(clicked()), SLOT(setFrameRate02()));
}

void PlayerWindow::openMedia()
{
    QString file = QFileDialog::getOpenFileName(0, tr("Open a video"));
    if (file.isEmpty())
        return;
    m_player->play(file);
}

void PlayerWindow::seekBySlider(int value)
{
    if (!m_player->isPlaying())
        return;
    m_player->seek(qint64(value*m_unit));
}

void PlayerWindow::seekBySlider()
{
    seekBySlider(m_slider->value());
}

void PlayerWindow::playPause()
{
    if (!m_player->isPlaying()) {
        m_player->play();
        return;
    }
    m_player->pause(!m_player->isPaused());
}

void PlayerWindow::updateSlider(qint64 value)
{
    m_slider->setRange(0, int(m_player->duration()/m_unit));
    m_slider->setValue(int(value/m_unit));
}

void PlayerWindow::updateSlider()
{
    updateSlider(m_player->position());
}

void PlayerWindow::updateSliderUnit()
{
    m_unit = m_player->notifyInterval();
    updateSlider();
}

void PlayerWindow::setFrameRate(double speed)
{
    if (!m_player)
    {
        return;
    }
    m_player->setFrameRate(speed);
}

void PlayerWindow::setFrameRate02()
{
    if (!m_player)
    {
        return;
    }
    m_player->setFrameRate(0.0001);
}

void PlayerWindow::setFrameRate2()
{
    if (!m_player)
    {
        return;
    }
   double frame_ops = m_player->forcedFrameRate();
   QMessageBox::warning(0, QString::fromLatin1("QtAV error"), QString::number(frame_ops, 10, 4));
}

void PlayerWindow::seekForward(int64_t step_ms)
{
    m_player->seek(m_player->position() + step_ms);
}

void PlayerWindow::seekBackward(int64_t step_ms)
{
   m_player->seek(m_player->position() - step_ms);
}