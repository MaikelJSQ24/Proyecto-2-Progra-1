#pragma once
#include <iostream>
#include "Place.h"

using namespace std;

class Route
{
private:
	Place* head;
public:
	Route();
	~Route();

	Place* getHead();
	void addNewUbication(int x, int y, string name);
	void addUbicationsFrom(Route& otherRoute);
	void clearUbications();
};

