#include "List.h"

List::List()
{
	head = nullptr;
}

List::~List()
{
}

Nodo* List::getHead()
{
	return head;
}

void List::addNewUbication(int x, int y,string name)
{
	Nodo* newNodo = new Nodo(x, y, name);
	if (!head)
	{
		head = newNodo;
		head->setNext(nullptr);
		head->setPrev(nullptr);
	}
	else {
		Nodo* current = head;
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNodo);
		current->setPrev(current);
	}
}
