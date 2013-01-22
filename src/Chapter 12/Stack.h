// stack.h -- class variation definition for chapter 12 exercise 4
#ifndef _STACK_H_
#define _STACK_H_
namespace ch12{ // had to use a namespace to resolve some linker problem

	typedef unsigned long Item;

	class Stack
	{
	private:
		enum {MAX = 10};    // constant specific to class
		Item * pitems;		// holds stack items
		int size;			// number of elements in stack
		int top;            // index for top stack item
	public:
		Stack(int n = MAX);		// creates stack with n elements
		Stack(const Stack & st);
		~Stack(){ delete [] pitems; }
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
		bool push(const Item & item);   // add item to stack
		// pop() returns false if stack already is empty, true otherwise
		bool pop(Item & item);          // pop top into item
		Stack & operator=(const Stack& st);
	};
}
#endif

