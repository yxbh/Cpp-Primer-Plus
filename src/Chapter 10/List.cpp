#include "List.h"
#include <iostream>
using std::cout;
using std::endl;

List::List()
{
	size = 0;
	begin = list;
	end = list + MAX;
}

const bool List::isFull(void) const
{
	if (size == MAX)
		return true;
	return false;
}

const bool List::isEmpty(void) const
{
	if (size == 0)
		return true;
	return false;
}

const bool List::add(data_type d)
{
	if (size < MAX) {
		*(list+size) = d;
		size++;
		return true;
	}
	return false;
}

void List::show(void) const
{
	for (uint i = 0; i < size; i++)
		cout << list[i] << " ";
	cout  << endl;
}



List::~List()
{}