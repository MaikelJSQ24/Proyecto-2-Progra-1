#include "RouteNodo.h"

RouteNodo::RouteNodo(Route routes)
{
	this->routes = routes;
	this->next = next;
	this->prev = prev;
}

RouteNodo::~RouteNodo()
{
}

void RouteNodo::setNext(RouteNodo* next)
{
	this->next = next;
}

RouteNodo* RouteNodo::getNext()
{
	return next;
}

void RouteNodo::setPrev(RouteNodo* prev)
{
	this->prev = prev;
}

RouteNodo* RouteNodo::getPrev()
{
	return prev;
}

Route& RouteNodo::getRoute()
{
	return routes;
}