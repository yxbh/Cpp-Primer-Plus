// stack.cpp -- Stack member functions
#include "Stack.h"
namespace ch12{

	Stack::Stack(int n)    // create an empty stack
	{
		pitems = new Item[n];
		size = 0;
		top = 0;
	}

	bool Stack::isempty() const
	{
		return top == 0;
	}

	bool Stack::isfull() const
	{
		return top == MAX;
	}

	bool Stack::push(const Item & item) 
	{
		if (top < MAX)
		{
			pitems[top++] = item;
			return true;
		}
		else
			return false;
	}

	bool Stack::pop(Item & item)
	{
		if (top > 0)
		{
			item = pitems[--top];
			return true;
		}
		else
			return false; 
	}

	Stack & Stack::operator=(const Stack& st)
	{
		if (pitems != nullptr)
			delete pitems;
		pitems = new Item[st.size];
		for (int i = 0; i < size; i++)
		{
			pitems[i] = st.pitems[i];
		}
		size = st.size;
		top = st.top;
		return *this;
	}

} // end of namespace