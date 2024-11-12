#include "Route.h"

Route::Route()
{
	head = nullptr;
}

Route::~Route()
{
}

void Route::setName(string name)
{
	this->name = name;
}

string Route::getName()
{
	return name;
}

void Route::setHead(PlaceNodo* head)
{
	this->head = head;
}

PlaceNodo* Route::getHead()
{
	return head;
}

void Route::setColor(Color color)
{
	this->color = color;
}

Color Route::getColor()
{
	return color;
}

void Route::addNewUbication(int x, int y, string name)
{
	Color color = Color(rand() % 256, rand() % 256, rand() % 256);
	PlaceNodo* newNodo = new PlaceNodo(x, y, name, color);
	if (!head)
	{
		head = newNodo;
		head->setNext(nullptr);
		head->setPrev(nullptr);
	}
	else {
		PlaceNodo* current = head;
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNodo);
		newNodo->setPrev(current);
	}
}

void Route::addUbicationsFrom(Route& otherRoute)
{
	PlaceNodo* current = otherRoute.getHead();
	while (current != nullptr)
	{
		addNewUbication(current->getX(), current->getY(), current->getName());
		current = current->getNext();
	}
}

void Route::clearUbications()
{
	PlaceNodo* current = head;
	while (current != nullptr)
	{
		PlaceNodo* temp = current;
		current = current->getNext();
		delete temp;
	}
	head = nullptr;
}

void Route::removeUbication(string name)
{
	PlaceNodo* current = head;
	PlaceNodo* prev = nullptr;

	while (current != nullptr) {
		if (current->getName() == name) {
			if (prev != nullptr) {
				prev->setNext(current->getNext());
			}
			else {
				head = current->getNext();
			}
			delete current;
			cout << "Ubicacion " << name << " eliminada." << endl;
			return;
		}
		prev = current;
		current = current->getNext();
	}


}

void Route::clearRoute()
{
	PlaceNodo* current = head;
	while (current != nullptr)
	{
		PlaceNodo* nextNode = current->getNext();
		delete current;
		current = nextNode;
	}
	head = nullptr;
}
