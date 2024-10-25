#include "Route.h"

Route::Route()
{
	head = nullptr;
}

Route::~Route()
{
}

Place* Route::getHead()
{
	return head;
}

void Route::addNewUbication(int x, int y, string name)
{
	
	Place* newNodo = new Place(x, y, name);
	if (!head)
	{
		head = newNodo;
		head->setNext(nullptr);
		head->setPrev(nullptr);
	}
	else {
		Place* current = head;
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNodo);
		current->setPrev(current);
	}
}

void Route::addUbicationsFrom(Route& otherRoute)
{
	Place* current = otherRoute.getHead();
	while (current != nullptr)
	{
		addNewUbication(current->getX(), current->getY(), current->getName());
		current = current->getNext();
	}
}

void Route::clearUbications()
{
	Place* current = head;
	while (current != nullptr)
	{
		Place* temp = current;
		current = current->getNext();
		delete temp;
	}
	head = nullptr;
}
