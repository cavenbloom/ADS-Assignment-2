#include "List.h"

void List::insertAtFront(int numb) 
{
	Node* newNode = new Node(numb); 
	newNode->next = head; 
	head = newNode;
}

void List::insertAtEnd(int numb) 
	{
	if (head == NULL) {

		insertAtFront(numb);
		return; 
	}
	Node* newNode = new Node(numb);
	Node* iterator = head;

	while (iterator->next != NULL) 
	{
		iterator = iterator->next;
	}
	iterator->next = newNode;
}


void List::deleteAtFront() {
	if (head == NULL) {
		return;
	}
	Node* iterator = head;
	head = head->next;
	delete iterator;

}

void List::deleteAtEnd() {
	if (head == NULL)
		return;
	Node* iterator = head;
	Node* previous = head;

	while (iterator->next != NULL) 
	{
		previous = iterator;
		iterator = iterator->next;
	}
	previous->next = NULL; 
	delete iterator;
}
