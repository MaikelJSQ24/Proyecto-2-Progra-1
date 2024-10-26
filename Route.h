#pragma once
#include <iostream>
#include "Place.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Route
{
private:
	PlaceNodo* head;
	Color color;
public:
	Route();
	~Route();

	PlaceNodo* getHead();
	void setColor(Color color);
	Color getColor();
	void addNewUbication(int x, int y, string name);
	void addUbicationsFrom(Route& otherRoute);
	void clearUbications();
};

