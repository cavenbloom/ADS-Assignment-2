#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:

	//data
	int numb;

	//pointer to next node 
	Node* next;

	//construtors - function that belongs to the class that gets called once
	// and the creation of the class. it gets called automatically
	Node();
	Node(int numb); // function overloading 

};