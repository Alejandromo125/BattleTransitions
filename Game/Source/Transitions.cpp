#include "Transitions.h"
#include "App.h"
#include "Render.h"
#include "easings.h"
#include <iostream>

using namespace std;
//https://github.com/enricmc19/BattleScene-Transitions


Transitions::Transitions() :Module()
{
	name.Create("BattleTransitions");
}

Transitions::~Transitions() {}

bool Transitions::Start()
{
	transit1 = { 0,0,0,0 };
	
	return true;
}

bool Transitions::PostUpdate()
{
	bool ret = true;

	if (active_transition != false)
	{
		timer_transition++;
	}

	return ret;

}


void Transitions::DrawTransition1()
{
	
		SDL_SetRenderDrawColor(app->render->renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(app->render->renderer, &transit1);
		transit1.x = 0;
		transit1.y = 0;
		transit1.h = EaseBounceInOut(timer_transition/1000, 1080 / 8, 1080, 45);
		transit1.w = EaseBounceInOut(timer_transition/1000, 1080 / 8, 1920, 45);



		cout << transit1.h << endl;
		cout << transit1.w << endl;
	

}


