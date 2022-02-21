//
// Created by Brandon on 2/20/2022.
//
#ifndef LAB6_LINKEDLIST_SLLIST_H
#define LAB6_LINKEDLIST_SLLIST_H
#include <iostream>
#include <sstream>

using namespace std;

template<class T>
class SLList
{
private:
	struct Node
	{
		T value;
		Node* next;

		Node(T value) : value(value), next(nullptr)
		{}
	};

	Node* head;
	int _size;

public:
	SLList() : head(nullptr), _size(0)
	{}
	~SLList()
	{
		while(!isEmpty())
		{
			pop_front();
		}
	}

	int size() const
	{
		return _size;
	}

	bool isEmpty() const
	{
		return _size == 0;
	}

	T front() const
	{
		if (!isEmpty())
		{
			return head->value;
		}
		else
		{
			// 💀
			throw invalid_argument("The list is empty!");
		}
	}

	void pop_front()
	{
		if (!isEmpty())
		{
			// pop_front
			Node* oldHead = head;
			head = head->next;
			delete oldHead;

			_size--;
		}
		else
		{

		}

	}

	void push_back(T listItem)
	{
		Node* newNode = new Node(listItem);

		if (isEmpty())
		{
			head = newNode;
		}
		else
		{
			// head -> something -> newNode
			// of all the nodes in my chain, only one of them has no next (a nullptr): the tail.

//			for (Node* node = head; node != nullptr; node = node->next)
//			{
//				if (node->next == nullptr)
//				{
//					node->next = newNode;
//				}
//			}
			Node* node;
			for (node = head; node->next != nullptr; node = node->next)
			{}
			node->next = newNode;

			_size++;
		}
	}

	string toString() const
	{
		stringstream ss;

		for (Node* node = head; node != nullptr; node = node->next)
		{
			ss << node->value;
			if (node->next != nullptr)
			{
				ss << " ";
			}
		}

		return ss.str();
	}
};

#endif //LAB6_LINKEDLIST_SLLIST_H
