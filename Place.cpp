#include "Place.h"

Place::Place()
{
	x = 0;
	y = 0;
	next = nullptr;
	prev = nullptr;
	nameOfPlace = " ";

}

Place::Place(int x, int y, string nameOfPlace)
{
	this->x = x;
	this->y = y;
	this->nameOfPlace = nameOfPlace;
}

Place::~Place()
{
}

void Place::setNext(Place* next)
{
	this->next = next;
}

Place* Place::getNext()
{
	return next;
}

void Place::setPrev(Place* prev)
{
	this->prev = prev;
}

Place* Place::getPrev()
{
	return prev;
}

int Place::getX()
{
	return x;
}

int Place::getY()
{
	return y;
}

string Place::getName()
{
	return nameOfPlace;
}

Color Place::getColor()
{
	return color;
}



