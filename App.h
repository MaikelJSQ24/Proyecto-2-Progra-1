#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class App
{
private:
	RenderWindow window;
	RenderWindow windowMenu;
	RenderWindow windowMap;
	Texture textureStart;
	Texture textureMap;
	Texture textureMenu;
	Sprite sprite;
	Sprite spriteMenu;
	Sprite spriteMap;
	Event event;
public:
	App();
	bool isButtonPressed(Event& event, int x1, int x2, int y1, int y2);
	void createMenu();
	void seeClicks(Event& event);
	void loadWindows(Event& event);
	void loadMap();
	void runApp();
};

