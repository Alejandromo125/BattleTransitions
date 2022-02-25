#ifndef __TRANSITIONS_H__
#define __TRANSITIONS_H__

#include "Module.h"


class Transitions : public Module
{
public:

	// Constructor
	Transitions();

	// Destructor
	virtual ~Transitions();

	// Called before the first frame
	bool Start();

	bool Update(float dt);

	//TODO 1: CREATE FUNCTIONS TO DRAW THE TRANSITIONS
	//CREATE X DIFERENTS FUNCTIONS THAT WILL BE ACCESSED TO DRAW DIFFERENT TRANSITIONS
	void DrawTransition1();

public:
};

#endif // __WINDOW_H__