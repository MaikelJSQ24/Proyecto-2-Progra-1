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

void List::addNewUbication(int x, int y)
{
	Nodo* newNodo = new Nodo(x, y);
	if (!head)
	{
		head = newNodo;
	}
	else {
		Nodo* current = head;
		while (current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNodo);
	}
}
