/*
 * Animation.cpp
 *
 *  Created on: 22 июля 2014 г.
 *      Author: snickers
 */

#include "Animation.h"

Animation::Animation() {
	frame_rate = 100; // 100ms
	max_frames = 0;
	frame_inc = 1;
	current_frame = 0;
	old_time = 0;
}

Animation::~Animation() {
	// TODO Auto-generated destructor stub
}

void Animation::SetCurrentFrame(short int frame) {
	if (frame > 0 && frame <= max_frames) {
		frame_rate = frame;
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

void Animation::OnAnimation() {
	if (old_time + frame_rate > SDL_GetTicks()) {
		return;
	}

	old_time = SDL_GetTicks();

	current_frame += frame_inc;

	if (current_frame >= max_frames) {
		current_frame = 0;
	}
}
