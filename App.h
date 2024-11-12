#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	Music musicStart;
	Music musicMenu;
	Music musicMap;
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

	bool loadTextures(Texture& texture, string systemPath);
	bool loadMusic(Music& music, string systemPath);

	void createMenu();
	void loadMap();
	void seeAllRoutes();
	void editMenu(Route& route, int clickX, int clickY);
	void runApp();

	bool isButtonPressed(Event& event, int x1, int x2, int y1, int y2);
	Color randomColor();
	void drawCircles();
	string writeName(string windowTitle, string message);
	string nameOfRoute();
	string nameOfPlace();
	void loadFontAndText(RenderWindow& window, Font font, Text text, PlaceNodo* nodo);
	void drawLines(RenderWindow& window, int x1, int y1, int x2, int y2, Color color);
	void changeColor(Event& event);
	void drawLineCurve(RenderWindow& window, Vector2f p0, Vector2f p1, Vector2f p2, Vector2f p3, Color color);

	void saveRoutesToFile();
	void loadFromFile();
};

