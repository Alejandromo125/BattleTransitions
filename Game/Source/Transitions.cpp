#include "Transitions.h"
#include "App.h"
#include "Render.h"
#include "easings.h"
#include "Window.h"
#include "Textures.h"

//https://github.com/enricmc19/BattleScene-Transitions


Transitions::Transitions() :Module()
{
	name.Create("BattleTransitions");
}

Transitions::~Transitions() {}

bool Transitions::Start()
{
	pokeball = app->tex->Load("Assets/textures/")
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
		if (animationSelected == 2)
		{
			DrawTransition2();
		}
		if (animationSelected == 3)
		{
			DrawTransition3();
		}
		
	}
	else if (!active_transition)
	{
		timer_transition = 0;
	}
	
	
	return ret;

}

void Transitions::SelectTransition(int id)
{
	if (!active_transition)
	{
		active_transition = true;
		animationSelected = id;
	}
}

void Transitions::DrawTransition1()
{
	//RECTANGULO SE HACE MAS GRANDE DESDE ESQUINA IZQUIERDA ARRIBA HASTA COMPLETAR LA TRANSICION

	Rect1.x = 0;
	Rect1.y = 0;
	Rect1.h = EaseLinearIn(timer_transition/4, win_height / 64, win_height, 240);
	Rect1.w = EaseLinearIn(timer_transition/4, win_width / 64, win_width, 240);
	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);

	if (timer_transition >= 2600)
	{
		active_transition = false;
	}
}

void Transitions::DrawTransition2()
{
	// BARRAS DESDE LA DERECHA A LOS LADOS

	Rect1.x = 0;  Rect2.x = win_width;  Rect3.x = 0; Rect4.x = win_width;
	Rect1.y = 0;
	Rect2.y = win_height / 4;
	Rect3.y = (win_height / 4) * 2;
	Rect4.y = (win_height / 4) * 3;
	Rect1.h = win_height / 4; Rect2.h = win_height / 4; Rect3.h = win_height / 4; Rect4.h = win_height / 4;

	Rect1.w = EaseLinearIn(timer_transition / 4, win_width / 64, win_width, 240);
	Rect2.w = -EaseLinearIn(timer_transition / 4, win_width / 64, win_width, 240);
	Rect3.w = EaseLinearIn(timer_transition / 4, win_width / 64, win_width, 240);
	Rect4.w = -EaseLinearIn(timer_transition / 4, win_width / 64, win_width, 240);

	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect2, 0, 255, 0, 255);
	app->render->DrawRectangle(Rect3, 0, 0, 255, 255);
	app->render->DrawRectangle(Rect4, 123, 0, 122, 255);

	
	if (timer_transition >= 2600)
	{
		active_transition = false;
	}
}

void Transitions::DrawTransition3()
{
	// QUIZAS CIRCULO COMPLETANDOSE TENGO QUE MIRARLO
	app->render->DrawTexture(pokeball, 10, 10, NULL, 0, 0);
	app->render->DrawCircle(win_width / 2, win_height / 2, EaseLinearIn(timer_transition / 4, win_width / 64, win_width, 240) , 255, 0, 0, 255);
	if (timer_transition >= 1300)
	{
		active_transition = false;
	}
}
/*
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


