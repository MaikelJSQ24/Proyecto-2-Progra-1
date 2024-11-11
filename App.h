#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Route.h"
#include "RouteList.h"
#include <fstream>
#include <string>
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
	Texture textureMapOfRoutes;
	Texture textureMenu;
	Texture textureEdit;
	Sprite sprite;
	Sprite spriteMenu;
	Sprite spriteMap;
	Sprite spriteMapOfRoutes;
	Sprite spriteEdit;
	Event event;
	Route ubications;
	RouteList routesList;
public:
	App();

	void createMenu();
	void loadWindows(Event& event);
	void loadMap();
	void seeAllRoutes();
	void editMenu(Route& route, int clickX, int clickY);
	void runApp();

	bool isButtonPressed(Event& event, float x1, float x2, float y1, float y2);
	void seeClicks(Event& event);
	Color randomColor();
	void drawCircles();
	string namePlace();
	void loadFontAndText(Font font, Text text, PlaceNodo* nodo);
	void drawLines(RenderWindow& window, int x1, int y1, int x2, int y2, Color color);
	void changeColor(Event& event);
	void drawLineCurve(RenderWindow& window, Vector2f p0, Vector2f p1, Vector2f p2, Vector2f p3, Color color);

	void saveRoutesToFile();
	void loadFromFile();
};

