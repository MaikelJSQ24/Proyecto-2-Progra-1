#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class App
{
private:
	RenderWindow window;
	Texture textureStart;
	Texture textureMap;
	Texture textureMenu;
	Sprite sprite;
	Sprite spriteMap;
	RectangleShape rectangleOption, rectangleCreate, rectangleDelete, rectangleExit;
	Font font;
	Text textOfOption, textOfCreate,textOfDelete,textOfExit;
	Event event;
	bool isMapLoad;
public:
	App();
	bool clicks(Event& event);
	void createMenu();
	void loadMap(Event& event, Sprite& sprite);
	void runApp();
	void seeClicks(Event& event);
};

