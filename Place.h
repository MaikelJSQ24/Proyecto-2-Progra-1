#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Place
{
private:
	int x;
	int y;
	Color color;
	Place* next;
	Place* prev;
	string nameOfPlace;
public:
	Place();
	Place(int x, int y, string nameOfPlace);
	~Place();

	void setNext(Place* next);
	Place* getNext();
	void setPrev(Place* prev);
	Place* getPrev();
	int getX();
	int getY();
	string getName();
	Color getColor();
};

