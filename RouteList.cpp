#include "RouteList.h"

RouteList::~RouteList()
{
	RouteNodo* current = routeHead;
	while (current != nullptr)
	{
		RouteNodo* nextNodo = current->getNext();
		delete current;
		current = nextNodo;
	}
}

void RouteList::addRoute(Route routes)
{
	RouteNodo* newRouteNodo = new RouteNodo(routes);

	if (!routeHead)
	{
		routeHead = newRouteNodo;
		return;
	}
	RouteNodo* current = routeHead;
	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	current->setNext(newRouteNodo);
	current->setPrev(current);
}

RouteNodo* RouteList::getHeadRoute()
{
	return routeHead;
}
