#include "Transitions.h"
#include "App.h"
#include "Render.h"

Transitions::Transitions() :Module()
{
	name.Create("BattleTransitions");
}

Transitions::~Transitions() {}

bool Transitions::Start()
{
	return true;
}


bool Transitions::Update(float dt)
{
	return true;
}


void Transitions::DrawTransition1()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			app->render->DrawRectangle({x,y,100,100}, 255, 0, 0);
		}
	}
	
}


