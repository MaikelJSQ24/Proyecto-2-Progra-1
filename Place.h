#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class PlaceNodo
{
private:
	int x;
	int y;
	Color color;
	PlaceNodo* next;
	PlaceNodo* prev;
	string nameOfPlace;
public:
	PlaceNodo();
	PlaceNodo(int x, int y, string nameOfPlace, Color color);
	~PlaceNodo();

	void setNext(PlaceNodo* next);
	PlaceNodo* getNext();
	void setPrev(PlaceNodo* prev);
	PlaceNodo* getPrev();
	int getX();
	int getY();
	string getName();
	Color getColor();
};

