#pragma once
#include "RouteNodo.h"

class RouteList
{
private:
	RouteNodo* routeHead;
public:
	RouteList() : routeHead(nullptr) {}
	~RouteList();

	void addRoute(Route routes);
	RouteNodo* getHeadRoute();
};

