##  Camera battle transitions

### Introduction

This research projet has been done by [Alejandro Martín Ortega](https://github.com/Alejandromo125) in the "Project II" subject in the videogame development and design in UPC.

In this project research the main objectives where the following:
- Do a research about how camera battle transitions are done in videogames and how this problem could be solved with our base code and our knowledge 
- Develop a program to create camera battle transitions as simple as possible for future inplementation in other projects
### Why are camera battle transitions important?
Transitions in videogames are important because of the following reasons
- Nowadays games are fast and do not freeze as much as they used to but in the past not having a transition for the battle mode could give the impression that the game had frozen or it had crashed out.
- It is always important for us as developers to tell the player that our game is working. It is indeed a necesity for the player [UX](https://en.wikipedia.org/wiki/User_experience), and that's because if a game does not give a response when the player is doing something such as entering a menu, selecting an item from the inventory or in this case transitioning to a battle scene, it can be considered to be a bad user experience, the player does not need to know everything but having a respose is satisfactory for the player and this could develop a good response for the player and a desire to keep playing. If the UX of the player is in general tearms a bad experience, the player won't feel as motivated to play as before, and he might drop the game and stop buying games from that franchise.

### Market aproach

Camera battle transitions are something that has been commonly used in [rpgs](https://en.wikipedia.org/wiki/Role-playing_video_game). Here I will list a few examples of transitions and the logic behind them.

1. Usage of shaders:
- Shaders are commonly used for transitons as they allow a more complex transition. Shader trasitions follow the next logic.First you design the pattern you want the transition to have creating the drawing and painting it in grayscale, it is important to know that this type of transition starts getting drawn onto the screen from the darkest pixel to the whithest one, meaning that it has an order of drawing. Here we have some exaples of shaders being used in transitions for videogames.
![Shader Image used](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/Shader_Waves.png)
![Shader in action](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/Waves_Shader.gif)
2. Distortion of textures
- This distortion of textures is created with the use of filters into the image shown onto the screen. Here we have some examples of distrotion transitions in videogames

![Distortion](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/Distortion.gif)

4. Geometrical transitions
- This transitions are the easiest ones to apply, here we have transitions such as fades to colour, rectangles wiping the screen or different geometrical forms wiping the screen too. Here we have some examples in videogames of this types of transitions.
![FadeToBlack](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/FadeToBlack.gif)
![HorizontalBars](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/HorizontalBars.gif)

### Selected aproach
As for the selected aproach for this project I have developed some easy transitions such as wipe of screen, rectangles coming from the sides and blinking fades.
This are easy transition to implement that work perfectly and that will be used as a basis for future projects and that could be modified for each project respectively.
All transitions are done with the use of easings:
#### Easings
- Easings consist on mathematical formulas that help developers assigns certain speeds to animations and could be used for example to calculate the aproximmate possition in time of objects that could follow the same path the easing is showing.
1. Linear
-   Straight forward line, simple linear interpolation.
![LinearEasings](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/LINEAR_EASE.gif)
2. Ease in Quad
-   A line that starts slow from the beggining and speeds up as time goes on
![EaseIn](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/EASE_IN_CURVE.gif)
3. Ease out Quad
-   Line that starts fast but decreasses it's acceleration as time goes on
![EaseOut](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/EASE_OUT_CURVE.gif)
4. Ease in out Quad
-   Line that starts slowly and ends slowly, reaching it's maximum speed in the middle of the function
![EaseInOut](https://github.com/Alejandromo125/BattleTransitions/tree/main/Documentation/EASE_IN_OUT_CURVE.gif)

We have a lot of different easings functions, see documentation to check more easings functions.

#### Wipe screen implementation
```c++
void Transitions::DrawTransition1()
{

	SDL_Rect Rect1;
	
	Rect1.x = 0;
	Rect1.y = 0;
	Rect1.h = win_height;
	Rect1.w = 0;
	
	if(currentStep == Fade_Step::TRANSTITION) Rect1.w = EaseLinearInOut(timer_in_transition / 8, win_width / 64, win_width, 240); 
	if (currentStep == Fade_Step::FROM_TRANSITION) Rect1.w = EaseLinearInOut(timer_out_transition / 8, win_width / 64, win_width, 240);
	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);

}
```
#### Horizontal lines implementation
```c++
void Transitions::DrawTransition2()
{
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

	if (currentStep == Fade_Step::TRANSTITION)
	{
		Rect1.w = EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect2.w = -EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect3.w = EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect4.w = -EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
	}
	if (currentStep == Fade_Step::FROM_TRANSITION)
	{
		Rect1.w = EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect2.w = -EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect3.w = EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect4.w = -EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
	}

	app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
	app->render->DrawRectangle(Rect2, 0, 255, 0, 255);
	app->render->DrawRectangle(Rect3, 0, 0, 255, 255);
	app->render->DrawRectangle(Rect4, 123, 0, 122, 255);

	
}
```
#### Horizontal lines with textures added
```c++
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
	if (currentStep == Fade_Step::TRANSTITION)
	{
		Rect1.w = EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect2.w = -EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect3.w = EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect4.w = -EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);
		Rect5.w = EaseLinearIn(timer_in_transition / 8, win_width / 64, win_width, 240);

		app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect2, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect3, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect4, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect5, 255, 0, 0, 255);

		app->render->DrawTexture(pokeball, (Rect1.x + Rect1.w - 120), (Rect1.y - 10), NULL, 0, EaseLinearIn(timer_in_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect2.x + Rect2.w - 120), (Rect2.y - 10), NULL, 0, EaseLinearIn(timer_in_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect3.x + Rect3.w - 120), (Rect3.y - 10), NULL, 0, EaseLinearIn(timer_in_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect4.x + Rect4.w - 120), (Rect4.y - 10), NULL, 0, EaseLinearIn(timer_in_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect5.x + Rect5.w - 120), (Rect5.y - 10), NULL, 0, EaseLinearIn(timer_in_transition / 24, win_width / 64, win_width, 240));
	}
	if (currentStep == Fade_Step::FROM_TRANSITION)
	{
		Rect1.w = EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect2.w = -EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect3.w = EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect4.w = -EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);
		Rect5.w = EaseLinearIn(timer_out_transition / 8, win_width / 64, win_width, 240);

		app->render->DrawRectangle(Rect1, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect2, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect3, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect4, 255, 0, 0, 255);
		app->render->DrawRectangle(Rect5, 255, 0, 0, 255);

		app->render->DrawTexture(pokeball, (Rect1.x + Rect1.w - 120), (Rect1.y - 10), NULL, 0, EaseLinearIn(timer_out_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect2.x + Rect2.w - 120), (Rect2.y - 10), NULL, 0, EaseLinearIn(timer_out_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect3.x + Rect3.w - 120), (Rect3.y - 10), NULL, 0, EaseLinearIn(timer_out_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect4.x + Rect4.w - 120), (Rect4.y - 10), NULL, 0, EaseLinearIn(timer_out_transition / 24, win_width / 64, win_width, 240));
		app->render->DrawTexture(pokeball, (Rect5.x + Rect5.w - 120), (Rect5.y - 10), NULL, 0, EaseLinearIn(timer_out_transition / 24, win_width / 64, win_width, 240));
	}

}
```
#### Fade to colour implementation
```c++
void Transitions::DrawTransition4()
{
	SDL_Rect Rect1;
	Rect1.x = 0;
	Rect1.y = 0;
	Rect1.w = win_width;
	Rect1.h = win_height;
	
	if (currentStep == Fade_Step::TRANSTITION) app->render->DrawRectangle(Rect1, timer_in_transition/10, 0, 0, 255); cout << timer_in_transition << endl;
	if (currentStep == Fade_Step::FROM_TRANSITION) app->render->DrawRectangle(Rect1, timer_out_transition/10, 0, 0, 255); cout << timer_out_transition << endl;

}
```
### Possible improvements
One possible improvement that I have found is that shaders can be also implented with the usage of SDL2. Here we have a link to a repo on github that has this type of transitions implemented [transitions with shaders](https://github.com/Slynchy/SDL-AlphaMaskWipes). As I could not come up with the code to develop it myself I decided to at least show that it is possible to do with SDL, eventhough it is easier to apply in unity.

### Documentation
- [Shaders case study pokemon](https://www.youtube.com/watch?v=LnAoD7hgDxw)
- [Easings information](https://easings.net/)


