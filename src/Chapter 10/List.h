#ifndef _LIST_H_
#define _LIST_H_

typedef unsigned int uint;
typedef int data_type;

class List
{
private:
	static const int MAX = 8;
	uint size;
	data_type list[MAX];
	data_type *begin;
	data_type *end;
public:
	List();
	const bool isFull(void) const;
	const bool isEmpty(void) const;
	const bool add(data_type d);
	void show(void) const;			// only work for primitives?
	~List();
};



#endif

