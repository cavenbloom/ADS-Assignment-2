#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class List
{
public:
	Node* head = NULL;

	void insertAtFront(int numb);
	void insertAtEnd(int numb);
	void deleteAtFront();
	void deleteAtEnd();

};

