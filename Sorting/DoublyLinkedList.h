#pragma once

#include <iostream>

//Template
template <typename T>

//A node of the doubly linked list.
class Node
{
public:
	//Data stored in node
	T data;
	//Pointer to the next
	Node* next = nullptr;
	//Pointer to the previous
	Node* prev = nullptr;
	//Constructor for the Nodes
	Node(T newData)
	{
		data = newData;
		next = nullptr;
		prev = nullptr;
	}
};

//Template Class
template <typename T>

//Doubly Linked List Class
class DoublyLinkedList
{
public:
	//Beginning of the doubly linked list
	Node <T>* head;
	//End of the doubly linked list
	Node <T>* tail;
	//SIze of the linkSize of how many items stored on the doubly linked list
	int linkSize;
	//Constructor for the doubly linked list
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		//Set to zero on default.
		linkSize = 0;
	}

	//Find a specific node 
	Node<T>* Find(T newData);
	//Insert a node of the list
	void Insert(T newData);
	//Delete a node in the list
	void Delete(T deleteData);
	//Display the list of the nodes
	void Display();
	void merge();
	void mergeSort();
	void bubbleSort();

};