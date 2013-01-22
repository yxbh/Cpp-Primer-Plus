#include "workermi.h"
#include "QueueTp.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

static const int SIZE = 5;

void ch14ex3(void)
{
	QueueTp<Worker *> myQueue(SIZE);
	// cout << "Size of my queue: " << myQueue.size() << endl;

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
		case 'w':   myQueue[ct] = new Waiter;
			break;
		case 's':   myQueue[ct] = new Singer;
			break;
		case 't':   myQueue[ct] = new SingingWaiter;
			break;
		default:
			break;
		}
		cin.get();
        myQueue[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        myQueue[i]->Show();
    }

    cout << "Bye.\n";
	cin.get();

}