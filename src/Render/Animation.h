/*
 * Animation.h
 *
 *  Created on: 22 июля 2014 г.
 *      Author: snickers
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SDL2/SDL.h>
#include <Core/Vec2.h>

class Animation {
public:
    Animation();

public:
	void OnAnimation();
	void SetFrameSize(const Vec2& fsize);
	void SetFrameRate(Uint16 rate);
	void SetCurrentFrame(Uint16 frame);
	void SetBeginFrame(Uint16 frame);
	void SetMaxFrame(Uint16 frame);

	Uint16 GetMaxFrame();
    Uint16 GetCurrentFrame();

private:
	Uint16 begin_frame;
	Uint16 max_frame;
	Uint16 current_frame;
	Uint16 frame_rate;
	Uint16 frame_inc;
	Uint64 old_time;
};

#endif /* ANIMATION_H_ */
