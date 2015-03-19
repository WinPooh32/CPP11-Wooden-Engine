/*
 * Animation.cpp
 *
 *  Created on: 22 июля 2014 г.
 *      Author: snickers
 */

#include "Animation.h"

Animation::Animation() {
    frame_rate = 100; // 100ms
    max_frame = 0;
    frame_inc = 1;
    current_frame = 0;
    begin_frame = 0;
    old_time = 0;
}

Animation::~Animation() {
    // TODO Auto-generated destructor stub
}

void Animation::SetCurrentFrame(short int frame) {
    if (frame > 0 && frame <= max_frame) {
        current_frame = frame;
    }
}

void Animation::SetFrameRate(short int rate) {
    if (rate > 0) {
        frame_rate = rate;
    }
}

short int Animation::GetCurrentFrame() {
    return current_frame;
}

void Animation::SetBeginFrame(short int frame) {
    begin_frame = frame;
}

void Animation::SetMaxFrame(short int frame) {
    max_frame = frame;
}

const short int & Animation::GetMaxFrame() {
    return max_frame;
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
