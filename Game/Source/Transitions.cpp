#include "Transitions.h"
#include "App.h"
#include "Render.h"
#include "easings.h"
#include "Window.h"
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
	SDL_SetRenderDrawBlendMode(app->render->renderer, SDL_BLENDMODE_BLEND);

	app->win->GetWindowSize(win_width, win_height);

	return true;
}

bool Transitions::PostUpdate()
{
	bool ret = true;

	if (active_transition)
	{
		timer_transition++;


		if (animationSelected == 1)
		{
			DrawTransition1();
		}
		
	}
	else if (!active_transition)
	{
		timer_transition = 0;
	}
	
	
	return ret;

}


void Transitions::DrawTransition1()
{

	transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(timer_transition, win_width / 64, win_width, 150);
	transit1.w = EaseBounceInOut(timer_transition, win_width / 64, win_height, 150);
	app->render->DrawRectangle(transit1, 255, 0, 0, 255);
	cout << timer_transition << endl;
	if (timer_transition >= 1300)
	{
		active_transition = false;
	}
}
/*
void Transitions::DrawTransition2()
{
	// BARRAS DESDE EL CENTRO HASTA LOS LADOS
	transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(timer_transition, win_width / 64, win_width, 150);
	transit1.w = EaseBounceInOut(timer_transition, win_width / 64, win_height, 150);
	app->render->DrawRectangle(transit1, 255, 0, 0, 255);
	cout << timer_transition << endl;
	if (timer_transition >= 1300)
	{
		active_transition = false;
	}
}
void Transitions::DrawTransition3()
{
	// QUIZAS CIRCULO COMPLETANDOSE TENGO QUE MIRARLO
	transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(timer_transition, win_width / 64, win_width, 150);
	transit1.w = EaseBounceInOut(timer_transition, win_width / 64, win_height, 150);
	app->render->DrawRectangle(transit1, 255, 0, 0, 255);
	cout << timer_transition << endl;
	if (timer_transition >= 1300)
	{
		active_transition = false;
	}
}
void Transitions::DrawTransition4()
{
	//INTENTO DE COMO LO HACEN EN POKEMON BLANCO Y NEGRO
	transit1.x = 0;
	transit1.y = 0;
	transit1.h = EaseBounceInOut(timer_transition, win_width / 64, win_width, 150);
	transit1.w = EaseBounceInOut(timer_transition, win_width / 64, win_height, 150);
	app->render->DrawRectangle(transit1, 255, 0, 0, 255);
	cout << timer_transition << endl;
	if (timer_transition >= 1300)
	{
		active_transition = false;
	}
}
*/


