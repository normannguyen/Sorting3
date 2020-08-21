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
		cout << "\n6. List Sort";
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
			case 7:
			{
				List.Insert(18);
				List.Insert(82);
				List.Insert(100);
				List.Insert(22);
				List.Insert(33);
				List.Insert(44);
				List.Insert(1);
				List.Insert(2);
				List.Insert(44);
				List.Insert(3);
				List.Insert(15);
				List.Insert(66);
				List.Insert(3);
				List.Insert(22);
				List.Insert(44);
				List.Insert(30);
				List.Insert(555);
				List.Insert(98);
				break;
			}
		}
	}
	//While choosing five.
	while (choice != 8);
	system("pause");
	return 0;
}
