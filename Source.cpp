// ADS103 - Assignment 2 - Alicia McEwen
// Q1 Input -> Order -> Output from .txt file
// Q2 linked list

#include <iostream>
#include <string>
#include <ctime> // timer
#include <fstream> // file reading/writing library
#include <vector> //for storage

using namespace std;

void displayArray(int arr[], int arraySize)
{

	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}

int main() {

	// Reading the Files.

	ifstream Q1InputTXT;
	fstream Q1OutputTXT;


	Q1InputTXT.open("input-a1q1.txt");
	{
		// ============= INPUT 
		// Opening up input file.
		int firstLineIn;
		int secondLineIn;
		string arrNumb;
		vector<int> arr;
		int numberOfNumbersArray;
		// int and string to hold data input of the .txt file
			if (Q1InputTXT.is_open()){
			// Begin displaying data.
				cout << "DISPLAYING INPUT DATA FROM FILE." << endl;
				cout << "===============================" << endl;
				cout << endl;

				Q1InputTXT >> firstLineIn;
				cout << firstLineIn << endl;

				Q1InputTXT >> secondLineIn;
				cout << secondLineIn << endl;

				Q1InputTXT >> numberOfNumbersArray;

				for (int i = 0; i < numberOfNumbersArray; i++) {
				int temp;
				Q1InputTXT >> temp;
				arr.push_back(temp);
			}
				for (int i = 0; i < arr.size(); i++) {
				cout << arr[i] << " ";
			}

				cout << endl;
			// ============= OUTPUT
			// IF the input has been given, the OUTPUT can be created.
				Q1OutputTXT.open("output-a1q1.txt");
				{
				// Begin sorting, and move according to the input.
					
					if (firstLineIn == 0)
					{
						if (secondLineIn == 0)
						{
							// BUBBLE SORT - ASCENDING ORDER
							bool sorted = false;
							while (!sorted)
							{
								sorted = true;
								for (int i = 0; i < arr.size() - 1; i++)
								{
									if (arr[i] > arr[i + 1])
									{
										swap(arr[i], arr[i + 1]);
										sorted = false;
									}
								}
							}
							// outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";
						}
						if (secondLineIn == 1)
						{
							// QUICK SORT - ASCENDING
							quickSort(arr, 0, arr.size() - 1, firstLineIn);
							// outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";
						}
						// Error checking.
						else if (secondLineIn != 0 && secondLineIn != 1)
						{
							cout << "Please recheck your second line. This accepts 0 for ascending order, or 1 for descending, and no other numbers." << endl;
							exit(1);
						}
					}
					if (firstLineIn == 1)
					{
						if (secondLineIn == 0)
						{
							// BUBBLE DESCENDING ORDER
							bool sorted = false;
							while (!sorted)
							{
								sorted = true;
								for (int i = 0; i < arr.size() - 1; i++)
								{
									if (arr[i] < arr[i + 1])
									{
										// if smaller, swap
										swap(arr[i], arr[i + 1]);
										// assume still unsorted.
										sorted = false;
									}
								}
							}
							// outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";

						}

						if (secondLineIn == 1)
						{
							// QUICK SORT - DESCENDING
							quickSort(arr, 0, arr.size() - 1, firstLineIn);
							// outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";
						}
						// Error checking.
						else if (secondLineIn != 0 && secondLineIn != 1)
						{
							cout << "Please recheck your second line. This accepts 0 for ascending order, or 1 for descending, and no other numbers." << endl;
							exit(1);
						}
					}
			// Error checking.
					else if (secondLineIn != 0 && secondLineIn != 1)
					{
						cout << "Please recheck your second line. This accepts 0 for ascending order, or 1 for descending, and no other numbers." << endl;
						exit(1);
					}
					
				}
			}
		
		// If file cannot be open, show error.
			else if (!Q1InputTXT.is_open())
		{
			cout << "Error, file not found." << endl;
			char errmsg[128];
			strerror_s(errmsg, 128, errno);
			printf("Error: %s\n", errmsg);
		}
	}


	Q1InputTXT.close();
}


int partition(vector<int>& array, int start, int end, int ascDesc)
{
	int pivot = end; 
	// last element = end
	int j = start;
	if (ascDesc == 0) // ascending
	{
		for (int i = start; i < end; i++)
		{
			if (array[i] < array[pivot])
			{
				swap(array[i], array[j]);
				j++;
			}
		}
	}
	if (ascDesc == 1) //descending
		for (int i = start; i < end; i++)
		{
			if (array[i] > array[pivot])
			{
				swap(array[i], array[j]);
				j++;
			}

		}

	return j;
}

void quickSort(vector<int>& array, int start, int end, int ascDesc)
{
	if (start < end)
	{
		int partitionIndex = partition(array, start, end, ascDesc);
		quickSort(array, end, partitionIndex, ascDesc);
		quickSort(array, partitionIndex + 1, start, ascDesc);
	}
}