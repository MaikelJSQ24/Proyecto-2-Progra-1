#pragma once
#include <iostream>
using namespace std;
class Nodo
{
private:
	int x;
	int y;
	Nodo* next;
	Nodo* prev;
	string nameOfPlace;
public:
	Nodo();
	Nodo(int x, int y, string nameOfPlace);
	~Nodo();

	void setNext(Nodo* next);
	Nodo* getNext();
	void setPrev(Nodo* prev);
	Nodo* getPrev();
	int getX();
	int getY();
	string getName();
};

