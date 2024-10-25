#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Route.h"
#include "RouteList.h"
using namespace std;
using namespace sf;

class App
{
private:
	RenderWindow window;
	RenderWindow windowMenu;
	RenderWindow windowMap;
	RenderWindow windowOfRoutes;
	Texture textureStart;
	Texture textureMap;
	Texture textureMenu;
	Sprite sprite;
	Sprite spriteMenu;
	Sprite spriteMap;
	Event event;
	Route ubications;
	RouteList routesList;
public:
	App();
	bool isButtonPressed(Event& event, int x1, int x2, int y1, int y2);
	void createMenu();
	void seeClicks(Event& event);
	void loadWindows(Event& event);
	void loadMap();
	void seeAllRoutes();
	void runApp();

	Color randomColor();
	void drawCircles();
	string namePlace();
};

