// ========= Alicia McEwen =========
// ASSIGNMENT 2 QUESTION 1 - Input and Sort
// ADS103, 2021


#include <iostream>
#include <string>
#include <chrono> // Clock for Millisecond timing
#include <fstream> // File reading/writing library
#include <vector> // For array storage

using namespace std;

// Partition for Quicksort.
int partition(vector<int>& array, int start, int end, int order) {
	int pivot = end; // last element is taken as the pivot 
	int j = start;
	if (order == 0) { // ascending order
		for (int i = start; i < end; i++) {
			if (array[i] < array[pivot]) {

				swap(array[i], array[j]);
				j++;
			}
		}
	}
	else if (order == 1) { // descedning order
		for (int i = start; i < end; i++) {
			if (array[i] > array[pivot]) {

				swap(array[i], array[j]);
				j++;
			}
		}
	}
	swap(array[j], array[pivot]);

	return j;
}
// Quicksort Function.
void quickSort(vector<int>& array, int start, int end, int order) {

	if (start < end) {

		int p = partition(array, start, end, order);
		quickSort(array, start, p - 1, order);
		quickSort(array, p + 1, end, order);
	}
}

int main() {

	// Reading + Opening the Files!

	ifstream Q1InputTXT;
	fstream Q1OutputTXT;


	Q1InputTXT.open("input-a1q1.txt");
	{
		// ====================== INPUT 
		// Opening up input file, reading it.

		// Int and string to hold data input of the .txt file
		int firstLineIn;
		int secondLineIn;
		string arrNumb;
		vector<int> arr;
		int numberOfNumbersArray;

		// Begin displaying data, this way when the application opens, the individual can read their original input.
			if (Q1InputTXT.is_open()){
				cout << "====================================" << endl;
				cout << "| DISPLAYING INPUT DATA FROM FILE. |" << endl;
				cout << "====================================" << endl;
				cout << endl;

				Q1InputTXT >> firstLineIn;
				cout << firstLineIn << endl;

				Q1InputTXT >> secondLineIn;
				cout << secondLineIn << endl;

				Q1InputTXT >> numberOfNumbersArray;
				cout << numberOfNumbersArray << endl;

				for (int i = 0; i < numberOfNumbersArray; i++) {
				int temp;
				Q1InputTXT >> temp;
				arr.push_back(temp);
			}
				for (int i = 0; i < arr.size(); i++) {
				cout << arr[i] << " ";
			}
				cout << endl;
				cout << endl;
				cout << "================================================================" << endl;
				cout << endl;
				cout << "| Organising the code... Please check output file for results. |" << endl;
				cout << endl;
				cout << "================================================================" << endl;
				cout << endl;


		// ====================== OUTPUT
		// IF the input has been given, the OUTPUT can be created.
				Q1OutputTXT.open("output-a1q1.txt");
				{
				// Begin sorting, and move according to the input.
					
					if (firstLineIn == 0)
					{
						if (secondLineIn == 0)
						{
							// Begin clock.
							std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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

							// Output the clock timer.
							std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
							Q1OutputTXT << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

							// Outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";
						}
						if (secondLineIn == 1)
						{
							std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

							// QUICK SORT - ASCENDING
							quickSort(arr, 0, arr.size() - 1, firstLineIn);

							// Output the clock timer
							std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
							Q1OutputTXT << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

							// Outputting the sorted array
							for (int i = 0; i < arr.size(); i++)
							Q1OutputTXT << arr[i] << " ";
						}

						// Error checking against anything except a 0 or 1
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
							// Begin clock.
							std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
							// BUBBLE DESCENDING ORDER
							bool sorted = false;
							while (!sorted)
							{
								sorted = true;
								for (int i = 0; i < arr.size() - 1; i++)
								{
									if (arr[i] < arr[i + 1])
									{
										// If smaller, swap
										swap(arr[i], arr[i + 1]);
										// Assume still unsorted.
										sorted = false;
									}
								}
							}

							// Output the clock timer
							std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
							Q1OutputTXT << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

							// Outputting the sorted array
							for (int i = 0; i < arr.size() - 1; i++)
							Q1OutputTXT << arr[i] << " ";

						}

						if (secondLineIn == 1)
						{
							// Begin clock.
							std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

							// QUICK SORT - DESCENDING
							quickSort(arr, 0, arr.size() - 1, firstLineIn);

							// output the clock timer
							std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
							Q1OutputTXT << "Milliseconds = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

							// outputting the sorted array
							for (int i = 0; i < arr.size(); i++)
							Q1OutputTXT << arr[i] << " ";
						}
						// Error checking.
						else if (secondLineIn != 0 && secondLineIn != 1)
						{
							cout << "Please recheck your second line. This accepts 0 for ascending order, or 1 for descending, and no other numbers." << endl;
							exit(1);
						}
					}

					// Error checking against anything except a 0 or 1
					else if (firstLineIn != 0 && firstLineIn != 1)
					{
						cout << "Please recheck your second line. This accepts 0 for ascending order, or 1 for descending, and no other numbers." << endl;
						exit(1);
					}
					
				}
			}
		
		// If file cannot be open, show error. (Thank you Matt <3)
			else if (!Q1InputTXT.is_open())
			{
			cout << "Error, file not found." << endl;
			char errmsg[128];
			strerror_s(errmsg, 128, errno);
			printf("Error: %s\n", errmsg);
			}
	}

	// Close the files afterward.
	Q1InputTXT.close();
	Q1OutputTXT.close();
}
