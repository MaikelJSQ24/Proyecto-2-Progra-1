#include "Place.h"

PlaceNodo::PlaceNodo()
{
	x = 0;
	y = 0;
	next = nullptr;
	prev = nullptr;
	nameOfPlace = " ";

}

PlaceNodo::PlaceNodo(int x, int y, string nameOfPlace,Color color)
{
	this->x = x;
	this->y = y;
	this->nameOfPlace = nameOfPlace;
	this->color = color;
}

PlaceNodo::~PlaceNodo()
{
}

void PlaceNodo::setNext(PlaceNodo* next)
{
	this->next = next;
}

PlaceNodo* PlaceNodo::getNext()
{
	return next;
}

void PlaceNodo::setPrev(PlaceNodo* prev)
{
	this->prev = prev;
}

PlaceNodo* PlaceNodo::getPrev()
{
	return prev;
}

int PlaceNodo::getX()
{
	return x;
}

int PlaceNodo::getY()
{
	return y;
}

string PlaceNodo::getName()
{
	return nameOfPlace;
}

Color PlaceNodo::getColor()
{
	return color;
}



