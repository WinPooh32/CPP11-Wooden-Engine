/*
 * Animation.cpp
 *
 *  Created on: 22 июля 2014 г.
 *      Author: snickers
 */

#include "Animation.h"

Animation::Animation() :
    begin_frame(0),
    max_frame(0),
    current_frame(0),
    frame_rate(100),
    frame_inc(1),
    old_time(0)
{
//constructor
}

void Animation::SetCurrentFrame(Uint16 frame) {
    if (frame >= begin_frame && frame <= max_frame) {
        current_frame = frame;
    }else{
        frame = begin_frame;
    }
}

void Animation::SetFrameRate(Uint16 rate) {
    if (rate > 0) {
        frame_rate = rate;
    }
}


void Animation::SetBeginFrame(Uint16 frame) {
    begin_frame = frame;
}

void Animation::SetMaxFrame(Uint16 frame) {
    max_frame = frame;
}

Uint16 Animation::GetBeginFrame() const{
    return current_frame;
}

Uint16 Animation::GetMaxFrame() const{
    return max_frame;
}

Uint16 Animation::GetCurrentFrame() const{
    return current_frame;
}

void Animation::OnAnimation() {
    if (old_time + frame_rate > SDL_GetTicks() || begin_frame == max_frame) {
        return;
    }

    old_time = SDL_GetTicks();

    current_frame += frame_inc;

    if (current_frame > max_frame) {
        current_frame = begin_frame;
    }
}
