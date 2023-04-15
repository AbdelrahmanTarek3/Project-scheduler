#pragma once
#include "Node.h"
#include <iostream>
// using namespace std;

template <typename T>
class LinkedList
{
private:
	int count = 0;
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		std::cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			std::cout << "[ " << p->getItem() << " ]";
			std::cout << "--->";
			p = p->getNext();
		}
		std::cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>;
		R->setItem(data);
		R->setNext(Head);
		Head = R;
		count++;
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}


	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data)
	{
		Node<T>* p = Head;
		Node<T>* R = new Node<T>(data);

		if (Head == NULL)
		{
			Head = R;
			return;
		}
		while (p->getNext() != NULL)
		{
			p = p->getNext();
		}
		p->setNext(R);
		R->setNext(NULL);
		count++;
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key)
	{
		if (Head == NULL)
		{
			return false;
		}
		Node<T>* p = Head;
		while (p != NULL)
		{
			if (p->getItem() == Key)
			{
				return true;
			}
			p = p->getNext();
		}
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value)
	{
		int count = 0;
		Node<T>* p = Head;
		if (Head == NULL)
			return 0;
		while (p != NULL)
		{
			if (p->getItem() == value)
			{
				count++;
			}
			p = p->getNext();

		}
		return count;
	}
	//[4] DeleteFirst

	void DeleteFirst()
	{
		if (Head == NULL)
		{
			return;
		}

		Node<T>* p = Head;
		Head = Head->getNext();
		delete p;
		count--;
	}


	//[5] DeleteLast

	void DeleteLast()
	{
		if (Head == NULL)
		{
			return;
		}

		Node<T>* p = Head;
		Node<T>* q = NULL;

		while (p->getNext() != NULL)
		{
			q = p;
			p = p->getNext();
		}

		if (q == NULL) //The list had only one node
		{
			Head = NULL;
		}
		else
		{
			q->setNext(NULL);
		}

		delete p;
		count--;
	}


	//[6] DeleteNode

	bool DeleteNode(const T& value)
	{
		if (Head == NULL)
		{
			return false;
		}

		Node<T>* p = Head;
		Node<T>* q = NULL;

		while (p != NULL && p->getItem() != value)
		{
			q = p;
			p = p->getNext();
		}

		if (p == NULL) //value not found
		{
			return false;
		}

		if (q == NULL) //The node to be deleted is the Head node
		{
			Head = p->getNext();
		}
		else
		{
			q->setNext(p->getNext());
		}

		delete p;
		return true;
	}


	//[7] DeleteNodes

	bool DeleteNodes(const T& value)
	{
		if (Head == NULL)
		{
			return false;
		}

		bool deleted = false;
		Node<T>* p = Head;
		Node<T>* q = NULL;

		while (p != NULL)
		{
			if (p->getItem() == value)
			{
				deleted = true;

				if (q == NULL) //The node to be deleted is the Head node
				{
					Head = p->getNext();
					delete p;
					p = Head;
				}
				else
				{
					q->setNext(p->getNext());
					delete p;
					p = q->getNext();
				}
			}
			else
			{
				q = p;
				p = p->getNext();
			}
		}

		return deleted;
	}


	//[8] Merge

	void Merge(const LinkedList& L)
	{
		if (L.Head == NULL)
		{
			return;
		}

		if (Head == NULL)
		{
			Head = L.Head;
		}
		else
		{
			Node<T>* p = Head;
			while (p->getNext() != NULL)
			{
				p = p->getNext();
			}

			p->setNext(L.Head);
		}
	}


	//[9] Reverse

	void Reverse()
	{
		Node<T>* prev = NULL;
		Node<T>* current = Head;
		Node<T>* next = NULL;

		while (current != NULL)
		{
			next = current->getNext();
			current->setNext(prev);
			prev = current;
			current = next;
		}

		Head = prev;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	bool peekFront(T& item)
	{
		if (isEmpty())
			return false;
		item = Head->getItem();
		return true;
	}


	int getCount()
	{
		return count;
	}
};
