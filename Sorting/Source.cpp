#include <iostream>
#include "DoublyLinkedList.h"
#include "DLLFunctions.h"
#include <time.h>
#include <fstream>

//Standard Library
using namespace std;

//Main Function is where everything is listed here.
int main()
{
	srand(time(nullptr));
	//Initial is choice 
	int choice = 0;
	int value = 0;
	DoublyLinkedList<int> List = DoublyLinkedList<int>();
	do
	{
		//Brief Commands listed for you.
		cout << "\n**************\n";
		cout << "\n1. Find";
		cout << "\n2. Insert";
		cout << "\n3. Delete";
		cout << "\n4. Display";
		cout << "\n5. Bubble Sort";
		cout << "\n6. Quick Sort";
		cout << "\n7. Preloaded Insert";
		cout << "\n8. Exit";
		cout << "\n\nPlease enter the # listed above: ";
		//Cin of choosing what program/number to choose.
		cin >> choice;
		//Switch Statement of commands.
		switch (choice)
		{
			//Find function
			case 1:
			{
				cout << "Enter the value you wanted to find: ";
				cin >> value;
				List.Find(value);
				break;
			}
			//Insert function
			case 2:
			{
				cout << "Enter the value you wanted to add: ";
				cin >> value;
				List.Insert(value);
				Node <int>* temp = List.head;
				while (temp != nullptr)
				{
					cout << temp->data << " ,";
					temp = temp->next;
				}
				break;
			}
			//Delete function
			case 3:
			{
				cout << "Enter the value you wanted to delete: ";
				cin >> value;
				List.Delete(value);
				Node <int>* temp = List.head;
				break;
			}
			//Display function
			case 4:
			{
				List.Display();
				break;
			}
			//Bubble Sort
			case 5:
			{
				//Double variable to store time.
				double duration;
				//Use the Bubble Sort Function
				List.bubbleSort();
				//Start time
				clock_t start = clock();
				List.Display();
				//Calculates time.
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				//Display the time duration.
				cout << "\n\nThis took: " << duration << " seconds to complete" << endl;
				break;
			}
			//Quick Sort
			case 6:
			{
				//Double variable to store time.
				double duration;
				List.quickSort(List.head);
				//Start time
				clock_t start = clock();
				List.Display();
				//Calculates time.
				duration = (clock()-start) / (double)CLOCKS_PER_SEC;
				//Display the time duration.
				cout << "\n\nThis took: " << duration << " seconds to complete" << endl;
				break;
			}
			//RNG
			case 7:
			{
				for (int i = 0; i < 100; i++)
				{
					List.Insert(rand() % 1000 + 1);
				}
				break;
			}
		}
	}
	//While choosing eight.
	while (choice != 8);
	system("pause");
	return 0;
}
