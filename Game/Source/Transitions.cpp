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
	pokeball = app->tex->Load("Assets/textures/Pokeball.png");
	app->win->GetWindowSize(win_width, win_height);

	return true;
}

bool Transitions::PostUpdate()
{
	bool ret = true;


	switch (currentStep)
	{
	case Transitions::NONE:
		timer_transition = 0;
		break;
	case Transitions::TRANSTITION:
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
		break;
	case Transitions::FROM_TRANSITION:
		timer_transition--;
		break;
	default:
		break;
	}
	
	
	
	return ret;

}

void Transitions::SelectTransition(int id)
{
	if (currentStep == Fade_Step::NONE)
	{
		currentStep = Fade_Step::TRANSTITION;
		animationSelected = id;
	}
}

void Transitions::DrawTransition1()
{
	//SLIDE TRANSITION

	SDL_Rect Rect1;
	
	Rect1.x = 0;
	Rect1.y = 0;
	Rect1.h = win_height;
	Rect1.w = 0;
	
	Rect1.w = EaseLinearInOut(timer_transition / 4, win_width / 64, win_width, 240); 
	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
	/*
	if (timer_transition >= 3500)
	{
		active_transition = false;
	}
	*/
	
}

void Transitions::DrawTransition2()
{
	// BARRAS DESDE LA DERECHA A LOS LADOS
	SDL_Rect Rect1;
	SDL_Rect Rect2;
	SDL_Rect Rect3;
	SDL_Rect Rect4;

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

	
}

void Transitions::DrawTransition3()
{
	// POKEMON TRANSITION
	SDL_Rect Rect1;
	SDL_Rect Rect2;
	SDL_Rect Rect3;
	SDL_Rect Rect4;
	SDL_Rect Rect5;

	Rect1.x = 0;  Rect2.x = win_width;  Rect3.x = 0; Rect4.x = win_width; Rect5.x = 0;
	Rect1.y = 0;
	Rect2.y = win_height / 5;
	Rect3.y = (win_height / 5) * 2;
	Rect4.y = (win_height / 5) * 3;
	Rect5.y = (win_height / 5) * 4;
	Rect1.h = win_height / 5; Rect2.h = win_height / 5; Rect3.h = win_height / 5; Rect4.h = win_height / 5; Rect5.h = win_height / 5;

	Rect1.w =  EaseLinearIn(timer_transition / 8, win_width / 64, win_width, 240);
	Rect2.w = -EaseLinearIn(timer_transition / 8, win_width / 64, win_width, 240);
	Rect3.w =  EaseLinearIn(timer_transition / 8, win_width / 64, win_width, 240);
	Rect4.w = -EaseLinearIn(timer_transition / 8, win_width / 64, win_width, 240);
	Rect5.w =  EaseLinearIn(timer_transition / 8, win_width / 64, win_width, 240);

	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect2, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect3, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect4, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect5, 255, 0, 0, 255);

	app->render->DrawTexture(pokeball, (Rect1.x + Rect1.w - 120), (Rect1.y - 10), NULL, 0, EaseLinearIn(timer_transition / 24, win_width / 64, win_width, 240));
	app->render->DrawTexture(pokeball, (Rect2.x + Rect2.w - 120), (Rect2.y - 10), NULL, 0, EaseLinearIn(timer_transition / 24, win_width / 64, win_width, 240));
	app->render->DrawTexture(pokeball, (Rect3.x + Rect3.w - 120), (Rect3.y - 10), NULL, 0, EaseLinearIn(timer_transition / 24, win_width / 64, win_width, 240));
	app->render->DrawTexture(pokeball, (Rect4.x + Rect4.w - 120), (Rect4.y - 10), NULL, 0, EaseLinearIn(timer_transition / 24, win_width / 64, win_width, 240));
	app->render->DrawTexture(pokeball, (Rect5.x + Rect5.w - 120), (Rect5.y - 10), NULL, 0, EaseLinearIn(timer_transition / 24, win_width / 64, win_width, 240));
	
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


