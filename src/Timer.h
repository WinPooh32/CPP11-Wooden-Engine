/*
 * Timer.h
 *
 *  Created on: 07 сент. 2014 г.
 *      Author: snickers
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <SDL2/SDL.h>

class Timer {
public:
	Timer();
	void Start();
	void Stop();
	void Pause(bool p);
	bool isPaused();
	Uint32 GetTime();

private:
	Uint32 begin_time;
	Uint32 paused_time;
	bool pause;
};

#endif /* TIMER_H_ */
