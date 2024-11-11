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
	string name;
public:
	Route();
	~Route();

	void setName(string name);
	void setHead(PlaceNodo* head);
	PlaceNodo* getHead();
	void setColor(Color color);
	Color getColor();
	void addNewUbication(int x, int y, string name);
	void addUbicationsFrom(Route& otherRoute);
	void clearUbications();
	void removeUbication(string name);
	void clearRoute();
};

