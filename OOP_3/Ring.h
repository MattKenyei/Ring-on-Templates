#pragma once
#include <iostream>
template <class T>
class Ring
{
	struct Element
	{
		T data;
		Element* next, * prev;
	};
	Element* current = NULL;
public:
	Ring() : current(NULL)
	{
		
	}
	~Ring()
	{
		clr();
	}
	int get_size(Ring& r)
	{
		int size = 0;
		for (Element* cur = current->next; cur != current; cur = cur->next)
			size++;
		return size;
	}
	Ring(const Ring& r)
	{
		int size = get_size(r);
		for (int i = 0; i < size; i++)
			push(r[i]);
	}
	void clr()
	{
		while (current)
		{
			pull();
		}
	}
	void push(T d)
	{
		Element* e = new Element;
		e->data = d;

		if (current == NULL)
		{
			current = e;
			e->next = e;
			e->prev = e;
			return;
		}

		e->next = current->next;
		e->prev = current;
		current->next->prev = e;
		current->next = e;
	}
	void find(T d)
	{
		if (current == NULL)
			return;
		bool flag = false;
		for (Element* cur = current->next; cur != current; cur = cur->next)
			if (cur->data == d)
			{
				printf("Element has been found\n");
				flag = true;
				current = cur;
				break;
			}
		if (!flag)
			printf("Element hasn't been found\n");
	}

	T pull()
	{
		if (current == NULL)
			return 0;
		T d = current->data;
		Element* e = current;
		if (current == current->next)
			current = NULL;
		else
		{
			current->prev->next = current->next;
			current->next->prev = current->prev;
			current = current->next;
		}
		delete e;
		return d;
	}

	void onRight()
	{
		if (current == NULL)
			return;
		current = current->next;
	}

	void onLeft()
	{
		if (current == NULL)
			return;
		current = current->prev;
	}

	void print()
	{
		if (current == NULL)
		{
			printf("Empty list\n");
			return;
		}
		std::cout << current->data;
		for (Element* cur = current->next; cur != current; cur = cur->next)
			std::cout << "<->" << cur->data;
		printf("\n");
	}
};