##  Camera battle transitions

### Introduction

This research projet has been done by [Alejandro Martín Ortega](https://github.com/Alejandromo125) in the "Project II" subject in the videogame development and design in UPC.

In this project research the main objectives where the following:
- Do a research about how camera battle transitions are done in videogames and how this problem could be solved with our base code and our knowledge 
- Develop a program to create camera battle transitions as simple as possible for future inplementation in other projects
#### Why are camera battle transitions important?
Transitions in videogames are important because of the following reasons
- Nowadays games are fast and do not freeze as much as they used to but in the past not having a transition for the battle mode could give the impression that the game had frozen or it had crashed out.
- It is always important for us as developers to tell the player that our game is working. It is indeed a necesity for the player [UX](https://en.wikipedia.org/wiki/User_experience), and that's because if a game does not give a response when the player is doing something such as entering a menu, selecting an item from the inventory or in this case transitioning to a battle scene, it can be considered to be a bad user experience, the player does not need to know everything but having a respose is satisfactory for the player and this could develop a good response for the player and a desire to keep playing. If the UX of the player is in general tearms a bad experience, the player won't feel as motivated to play as before, and he might drop the game and stop buying games from that franchise.

### Market aproach

Camera battle transitions are something that has been commonly used in [rpgs](https://en.wikipedia.org/wiki/Role-playing_video_game). Here I will list a few examples of transitions and the logic behind them.

1. Usage of shaders:
- Shaders are commonly used for transitons as they allow a more complex transition. Shader trasitions follow the next logic.First you design the pattern you want the transition to have creating the drawing and painting it in grayscale, it is important to know that this type of transition starts getting drawn onto the screen from the darkest pixel to the whithest one, meaning that it has an order of drawing. Here we have some exaples of shaders being used in transitions for videogames.
2. Distortion of textures
- This distortion of textures is created with the use of filters into the image shown onto the screen. Here we have some examples of distrotion transitions in videogames.
4. Geometrical transitions
- This transitions are the easiest ones to apply, here we have transitions such as fades to colour, rectangles wiping the screen or different geometrical forms wiping the screen too. Here we have some examples in videogames of this types of transitions.

### Selected aproach
As for the selected aproach for this project I have developed some easy transitions such as wipe of screen, rectangles coming from the sides and blinking fades.
This are easy transition to implement that work perfectly and that will be used as a basis for future projects and that could be modified for each project respectively.
All transitions are done with the use of easings:
#### Easings
- Easings consist on mathematical formulas that help developers assigns certain speeds to animations and could be used for example to calculate the aproximmate possition in time of objects that could follow the same path the easing is showing.
- PONER AQUI INFORMACION DE LOS EASINGS CON FOTOS Y CODIGO DE EJEMPLO
-Wipe Screen Implementation
#### AQUI PONER EL CODIGO Y UN GIF
```c++
//CODE GOES HERE ALONGISDE IMAGE
```
### Possible improvements
One possible improvement that I have found is that shaders can be also implented with the usage of SDL2. Here we have a link to a repo on github that has this type of transitions implemented [transitions with shaders](). As I could not come up with the code to develop it myself I decided to at least show that it is possible to do with SDL, eventhough it is easier to apply in unity.

### Documentation
-[Shaders case study pokemon](https://www.youtube.com/watch?v=LnAoD7hgDxw)
- Poner mas links y cosas
Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

