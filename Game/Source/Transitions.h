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
	void SelectTransition(int id);
	//NEED TO CREATE MORE DRAWTRANSITIONS
	void DrawTransition1();
	void DrawTransition2();
	void DrawTransition3();


public:

	int animationSelected;
	bool active_transition = false;
	int timer_transition = 0;
	uint win_width;
	uint win_height;

	// The rectangles of the screen, used to render the animation
	SDL_Rect Rect1;
	SDL_Rect Rect2;
    SDL_Rect Rect3;
    SDL_Rect Rect4;
	
	SDL_Texture* pokeball;
};

#endif // __WINDOW_H__