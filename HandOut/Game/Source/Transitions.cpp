#include "Transitions.h"
#include "App.h"
#include "Render.h"
#include "easings.h"
#include "Window.h"
#include "Textures.h"
#include <SDL_image/include/SDL_image.h>
#include <iostream>

using namespace std;



Transitions::Transitions() :Module()
{
	name.Create("BattleTransitions");
}

Transitions::~Transitions() {}

bool Transitions::Start()
{

	pokeball = app->tex->Load("Assets/textures/Pokeball.png");
	app->win->GetWindowSize(win_width, win_height);

	return true;
}
bool Transitions::Update()
{
	bool ret = true;

	
	return ret;
}
bool Transitions::PostUpdate()
{
	bool ret = true;
/*
TODO 1: Using the Enum "currentStep" create a switch that inside of the case TRANSITION will increase the variable "time_in_transition"
and depending on the animation selected it will call to the respective funciton. Do the same for the case FROM_TRANSITION but instead of increasing it's time
decrease the variable "time_out_transition"
*/

/*
TODO 2: Create an if statement to change from TRANSITION to FROM_TRANSITION and viceversa once the conditions are met
 - time_in_transition is bigger or equal than time_out_transition
 - time_out_transition is smaller or equal than 0
*/

	return ret;

}

void Transitions::SelectTransition(int id,int timer1,int timer2)
{
	//TODO 3: Complete this function so the integers given by the player are passed to the values of the class, take into account the steps of the transition

}

void Transitions::DrawTransition1()
{
	//TODO 4: Create a wiping transition using a Rect that will fill the whole screen and will move horizontally remember that it has to come back to it's starting point in a smooth way


}

void Transitions::DrawTransition2()
{
	//TODO 5: Create 4 rects that will interpolate directions and will act the same as the wiping transition from before

	
}

void Transitions::DrawTransition3()
{
	// TODO 6: Create a similar function to the TODO 5, but in this case you will create 5 interpolating rects that will have also a texture drawn 
	//on top and will update it's position alongside with the rect


}

void Transitions::DrawTransition4()
{
	//TODO 7: Create a rect that will Fade in and out 



}



