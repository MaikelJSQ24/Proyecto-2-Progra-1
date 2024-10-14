#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

class List
{
private:
	Nodo* head;

public:
	List();
	~List();

	Nodo* getHead();
	void addNewUbication(int x, int y);
};

