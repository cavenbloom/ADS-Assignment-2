// ========= Alicia McEwen =========
// ASSIGNMENT 2 QUESTION 2 - Input and Sort
// ADS103, 2021

#include <iostream>
#include <fstream> // For input output of files
#include <chrono> // For timing
#include "List.h" // For the list functions

using namespace std;

int main() 
{
	// =========== INTIALISING FUNCTIONS
		// Link list types (Input / Output)
	ifstream linkListInp;
	fstream linkListOutp;

	// Linklists.
	List linkList1;
	List linkList2;

	// Int values
	int numberOfElements;

	// Random numbers 
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber;

	// =========== START INPUT

	linkListInp.open("input-a1q2.txt");
	{
	if (linkListInp.is_open())
		{
		cout << "====================================" << endl;
		cout << "| DISPLAYING INPUT DATA FROM FILE. |" << endl;
		cout << "====================================" << endl;
		cout << endl;
		linkListInp >> numberOfElements;
		cout << "The number of elements read is... " << numberOfElements << endl;

	linkListOutp.open("output-a1q2.txt");
	{
		if (linkListOutp.is_open())
		{
			// =========== Fronts together ===========

			// ===========Insert at front
				// Start timer
			std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
			for (int i = 0; i < numberOfElements; i++)
			{
				// Forming a random number to add to the front of the list.
				randomNumber = (rand() % 250) + 1;
				linkList1.insertAtFront(randomNumber);
			}
			// Stop clock
			std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

			// =========== Delete at front
					// Start timer.
			std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
			for (int i = 0; i < numberOfElements; i++)
				linkList1.deleteAtFront();
			// Stop clock
			std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

			// =========== Ends together ===========

			// =========== Insert at end
				// Start timer
			std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
			for (int i = 0; i < numberOfElements; i++)
			{
				// Forming a random number to add to the front of the list.
				randomNumber = (rand() % 250) + 1;
				linkList2.insertAtEnd(randomNumber);
			}
			// Stop clock
			std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();

			// =========== Delete at end
				// Start timer
			std::chrono::steady_clock::time_point begin4 = std::chrono::steady_clock::now();
			for (int i = 0; i < numberOfElements; i++)
				linkList2.deleteAtEnd();
			// Stop clock
			std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();

			linkListOutp << "The time taken to insert at beginning in Milliseconds " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() << "[ms]" << std::endl;
			linkListOutp << "The time taken to delete at beginning in Milliseconds " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count() << "[ms]" << std::endl;
			linkListOutp << "The time taken to insert at end in Milliseconds " << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3).count() << "[ms]" << std::endl;
			linkListOutp << "The time taken to delete at end in Milliseconds " << std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4).count() << "[ms]" << std::endl;
		}

	}
		}
// If the input cannot be read, show a error message.
	else if (!linkListInp.is_open())
		{
		cout << "Error, file not found." << endl;
		char errmsg[128];
		strerror_s(errmsg, 128, errno);
		printf("Error: %s\n", errmsg);
		}

	}

}

