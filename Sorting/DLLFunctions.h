#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;
//Template Class set a generic class
template <class T>
//Find function where to find the number in the node.
Node <T>* DoublyLinkedList<T>::Find(T findData)
{
	//If the size is not 0
	if (linkSize != 0)
	{

		Node <T>* newPtr = head;
		//while loop to go to the next pointer
		while (newPtr != nullptr && newPtr->data != findData)
		{
			newPtr = newPtr->next;
		}
		//newPtr not set to null
		if (newPtr != nullptr)
		{
			cout << "Found: " << newPtr->data;
			return newPtr;
		}
		// If there's a node, but the exact number wasn't there.
		else
		{
			cout << "\nThat's not in the list\n";
		}
	}
	//Last else if virtually no nodes.
	else
	{
		cout << "\nThat's not in the list\n";
		return 0;
	}
}

//Template Class set a generic class
template <class T>

//Insert function 
void DoublyLinkedList<T>::Insert(T newData)
{
	Node <T>* newPtr = new Node <T>(newData);
	//If there's nothing in the list, it will insert the new element in both head and tail.
	if (linkSize == 0)
	{
		//Tail equals to newPtr
		tail = newPtr;
		//Head equals to newPtr
		head = newPtr;
		//Tail set next = NULL
		tail->next = nullptr;
		//Head set previous = null
		head->prev = nullptr;
	}
	//Else statement if there's a new element, a new pointer will be set in the list.
	else
	{
		//newPtr set previous equal to tail
		newPtr->prev = tail;
		//tail set to next equal to newPtr;
		tail->next = newPtr;
		//tail set to newPtr
		tail = newPtr;
		//tail set to next equal to nullPtr if the 
		tail->next = nullptr;
	}
	//Add size for the list
	linkSize++;
}

template <class T>
//Delete
void DoublyLinkedList<T>::Delete(T deleteData)
{
	
	Node <T>* newPtr = head;
	//Search
	while (newPtr->data != deleteData)
	{
		//newPtr equal to newPtr next of the node.
		newPtr = newPtr->next;
	}
	//This section focuses on deleting the node inside the node.
	if (newPtr == tail)
	{
		//Setting the new tail after it was deleted.
		tail = newPtr->prev;
		//Setting next to null because it's in the end of the list.
		tail->next = nullptr;
		//Setting its previous to the new previous node.
		tail->prev = newPtr->prev->prev;
		//Minimize the list size of the linked list.
		linkSize--;
	}
	//Head
	else if (newPtr == head)
	{
		//Setting the new head after the previous one deleted.
		head = newPtr->next;
		//Setting previous to null because it's at the beginning of the list.
		head->prev = nullptr;
		//Setting its next to the next node.
		head->next = newPtr->next->next;
		//Minimize the list size of the linked list.
		linkSize--;
	}
	//Delete nodes from the middle
	else
	{
		//Set the new pointer on the node next.
		newPtr->prev->next = newPtr->next;
		//Set the node to set it back up.
		newPtr->next->prev = newPtr->prev;
		//Minimize the list size of the linked list.
		linkSize--;
	}
	//Free memory from the occupied list.
	free(newPtr);
	return;
}

//Template Class
template <class T>
void DoublyLinkedList<T>::Display()
{
	//
	Node <T>* newPtr;

	//If head set null
	if (head != nullptr)
	{
		newPtr = head;
		//While loop to set the display of data on the linked list.
		while (newPtr != nullptr)
		{
			//Prints the list of the linked list.
			cout << newPtr->data << ", ";
			//Goes to the next node to print.
			newPtr = newPtr->next;
		}
	}
	//Else if nothing is there.
	else
	{
		cout << "\nThere's nothing there." << endl;
	}

}

//Bubble Sort Done
template<typename T>
void DoublyLinkedList<T>::bubbleSort()
{
	bool Sorted = false;

	while (!Sorted)
	{
		Sorted = true;
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			if (current->data > current->next->data)
			{
				T temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				Sorted = false;
			}
			current = current->next;
		}
	}

}
template<typename T>
void DoublyLinkedList<T>::quickSort(Node<T>* head)
{
	Node<T>* h = lastNode(head);
	_quickSort(head, h);
}

//Recursive
template<typename T>
void DoublyLinkedList<T>::_quickSort(Node<T>* head, Node<T>* tail)
{
	if (tail != NULL && head != tail && head != tail->next)
	{
		Node<T>* P = partition(head, tail);
		_quickSort(head, P->prev);
		_quickSort(P->next, tail);
	}


}

template<typename T>
Node<T>* DoublyLinkedList<T>::partition(Node<T>* head, Node<T>* tail)
{
	T x = tail->data;
	Node<T>* i = head->prev;
	for (Node<T>* j = head; j != tail; j = j->next)
	{
		if (j->data <= x)
		{
			i = (i == NULL) ? head : i->next;
			swap(i, j);
		}
	}
	i = (i == NULL) ? head : i->next;
	swap(i, tail);
	return i;
}

//Last Node
template<typename T>
Node<T>* DoublyLinkedList<T>::lastNode(Node<T>* root)
{
	while (root && root->next)
		root = root->next;
	return root;
}

template<typename T>
void DoublyLinkedList<T>::swap(Node<T>* a, Node<T>* b)
{
	T t = a->data;
	a->data = b->data;
	b->data = t;
}
