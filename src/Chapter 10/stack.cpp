// stack.cpp -- Stack member functions
#include "stack.h"
namespace ch10{
Stack::Stack()    // create an empty stack
{
    top = 0;
	running_total = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const customer & cus) 
{
    if (top < MAX)
    {
        items[top++] = cus;
        return true;
    }
    else
        return false;
}

bool Stack::pop(customer & cus)
{
    if (top > 0)
    {
        cus = items[--top];
		running_total += cus.payment;
        return true;
    }
    else
        return false; 
}

double Stack::get_runningTotal(void) const
{
	return running_total;
}

}