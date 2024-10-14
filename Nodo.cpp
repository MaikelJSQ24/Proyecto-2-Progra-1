#include "Nodo.h"

Nodo::Nodo()
{
	x = 0;
	y = 0;
	next = nullptr;
}

Nodo::Nodo(int x, int y)
{
	this->x = x;
	this->y = y;
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

int Nodo::getX()
{
	return x;
}

int Nodo::getY()
{
	return y;
}
