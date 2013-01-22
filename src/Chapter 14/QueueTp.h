#ifndef _QUEUETP_H_
#define _QUEUETP_H_
#include <vector>
using std::vector;

template<class Type>
class QueueTp : public vector<Type>
{
private:
	int queue_size;
public:
	// create a Queue of size queue_size, default size = 0
	QueueTp(const int queue_size = 0): vector<Type>(queue_size) 
	{
		this->queue_size = queue_size;
	}

	// destructor
	~QueueTp() 
	{
		for (int i = 0; i < queue_size; i++)
		{
			delete (*this)[i];
		}
	}
};



#endif

