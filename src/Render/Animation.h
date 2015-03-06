/*
 * Animation.h
 *
 *  Created on: 22 июля 2014 г.
 *      Author: snickers
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SDL2/SDL.h>

class Animation {
public:
	Animation();
	virtual ~Animation();

public:


	void OnAnimation();
	void SetFrameRate(short int rate);
	void SetCurrentFrame(short int frame);
	short int GetCurrentFrame();
	void SetBeginFrame(short int frame);
	void SetMaxFrame(short int frame);
	const short int & GetMaxFrame();

private:
	short int max_frames;
	short int frame_rate;
	short int current_frame;
	short int begin_frame;
	short int frame_inc;
	unsigned long int old_time;
};

#endif /* ANIMATION_H_ */
