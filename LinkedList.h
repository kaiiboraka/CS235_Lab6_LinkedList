//
// Created by Brandon on 2/20/2022.
//
#ifndef LAB6_LINKEDLIST_LINKEDLIST_H
#define LAB6_LINKEDLIST_LINKEDLIST_H

#include "LinkedListInterface.h"

#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
	struct Node
	{
		T value;
		Node* next;

		explicit Node(T value) : value(value), next(nullptr)
		{}
	};

	struct Position
	{
		Node* node = nullptr;
		bool exists = false;
		int index = 0;
	};

	Node* head;
	int _size;

public:
	LinkedList() : head(nullptr), _size(0)
	{

	}

	~LinkedList() override
	{
		clear();
	}

	void clear() override
	{
		for (int i = 0; i < size(); i++)
		{
			pop_front();
		}
		_size = 0;
	}

	T front() const
	{
		if (!isEmpty())
		{
			return head->value;
		}
		else
		{
			throw invalid_argument("The list is empty!");
		}
	}

	int size() override
	{
		return _size;
	}

	bool isEmpty() const
	{
		return (_size <= 0 || head == nullptr);
	}

	string toString() override
	{
		if(!isEmpty())
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
		else return "";
	}

	Position valExists(T value)
	{
		Position pos;
		for (pos.node = head; pos.node != nullptr; pos.node = pos.node->next)
		{
			if (pos.node->value == value)
			{
				pos.exists = true;

				return pos;
			}
			pos.index++;
		}
		return pos;
	}

	T at(int index) override
	{
		if (isEmpty() || index < 0 || index >= size())
		{
			throw out_of_range("index out of range");
		}
		else
		{
			if(index == 0)
			{
				return head->value;
			}

			Position pos;
			pos.node = head;
			pos.index = 0;
			// TODO: might be O.B.O.E.
			for (pos.index; pos.index < index; pos.index++)
			{
				pos.node = pos.node->next;
			}
			return pos.node->value;
		}
	}

	void insertHead(T value) override
	{
		Node* newHead = new Node(value);
		if (isEmpty())
		{
			head = newHead;
			_size++;
		}
		else if (!valExists(value).exists)
		{
			//newHead->"head"=oldHead->next
			newHead->next = head;

			//"head"=newHead->oldHead->next
			head = newHead;
			_size++;
		}
	}

	void insertAfter(T value, T insertionNode) override
	{
		auto pos = valExists(insertionNode);

		if (pos.exists && !valExists(value).exists)
		{
			auto newNode = new Node(value);

			// newNode->next == pos.node->next
			newNode->next = pos.node->next;

			//pos.node->newNode->next
			pos.node->next = newNode;
			_size++;
		}
	}

	void insertTail(T listItem) override
	{
		if (!valExists(listItem).exists)
		{
			push_back(listItem);
		}
	}

	void push_back(T listItem)
	{
		if (isEmpty())
		{
			insertHead(listItem);
		}
		else
		{
			Node* newNode = new Node(listItem);
			Node* node;
			for (node = head; node->next != nullptr; node = node->next)
			{
				// just move along
			}
			node->next = newNode;

			_size++;
		}
	}

	void remove(T value) override
	{
		// get Position of value
		auto posToRemove = valExists(value);
		if (posToRemove.exists)
		{
			auto index = posToRemove.index;
			if (index < 0)
			{
				throw out_of_range("index out of range");
			}
			else if(index == 0)
			{
				pop_front();
			}
			else
			{
				valExists(at(index - 1)).node->next = posToRemove.node->next;
				delete posToRemove.node;
				_size--;
			}
		}
	}

	void pop_front()
	{
		if (!isEmpty())
		{
			//pop_front
			// new pointer looks at same thing as old head
			Node* oldHead = head;
			// head now looks at first thing after, inc nullptr
			head = head->next;
			// delete oldHead
			delete oldHead;

			_size--;
		}
	}

};

#endif //LAB6_LINKEDLIST_LINKEDLIST_H
