#pragma once

class Nodo
{
private:
	int x;
	int y;
	Nodo* next;
public:
	Nodo();
	Nodo(int x, int y);
	~Nodo();

	void setNext(Nodo* next);
	Nodo* getNext();
	int getX();
	int getY();
};

