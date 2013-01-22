// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_
#include <string>
using std::string;

namespace ch10 {
struct customer {
	std::string fullname;
	double payment;
};

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    customer items[MAX];    // holds stack items
    int top;            // index for top stack item
	double running_total;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const customer & cus);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(customer & cus);          // pop top into item
	double get_runningTotal(void) const;
};

#endif
}