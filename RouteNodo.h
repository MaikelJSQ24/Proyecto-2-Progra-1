#pragma once
#include "Route.h"
class RouteNodo
{
private:
	Route routes;
	RouteNodo* next;
	RouteNodo* prev;
public:
	RouteNodo() : next(nullptr), prev(nullptr) {}
	RouteNodo(Route routes);
	~RouteNodo();

	void setNext(RouteNodo* next);
	RouteNodo* getNext();
	void setPrev(RouteNodo* prev);
	RouteNodo* getPrev();
	Route& getRoute();

};

