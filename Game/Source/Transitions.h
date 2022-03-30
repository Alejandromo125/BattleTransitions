#ifndef __TRANSITIONS_H__
#define __TRANSITIONS_H__

#include "Module.h"
#include "Render.h"
#include "SDL/include/SDL_rect.h"

class Transitions : public Module
{
public:

	// Constructor
	Transitions();

	// Destructor
	virtual ~Transitions();

	// Called before the first frame
	bool Start();


	bool PostUpdate();
	//TODO 1: CREATE FUNCTIONS TO DRAW THE TRANSITIONS
	//CREATE X DIFERENTS FUNCTIONS THAT WILL BE ACCESSED TO DRAW DIFFERENT TRANSITIONS
	void DrawTransition1();

public:
	int animationSelected;
	bool active_transition = false;
	int timer_transition = 0;
	uint win_width;
	uint win_height;

	// The rectangles of the screen, used to render the animation
	SDL_Rect transit1;
	SDL_Rect transit2;
    SDL_Rect transit3;
    SDL_Rect transit4;
	

};

#endif // __WINDOW_H__