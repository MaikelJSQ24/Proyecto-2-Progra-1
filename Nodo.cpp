#include "Nodo.h"

Nodo::Nodo()
{
	x = 0;
	y = 0;
	next = nullptr;
	prev = nullptr;
	nameOfPlace = " ";
}

Nodo::Nodo(int x, int y,string nameOfPlace)
{
	this->x = x;
	this->y = y;
	this->nameOfPlace = nameOfPlace;
}

Nodo::~Nodo()
{
}

void Nodo::setNext(Nodo* next)
{
	this->next = next;
}

Nodo* Nodo::getNext()
{
	return next;
}

void Nodo::setPrev(Nodo* prev)
{
	this->prev = prev;
}

Nodo* Nodo::getPrev()
{
	return prev;
}

int Nodo::getX()
{
	return x;
}

int Nodo::getY()
{
	return y;
}

string Nodo::getName()
{
	return nameOfPlace;
}
