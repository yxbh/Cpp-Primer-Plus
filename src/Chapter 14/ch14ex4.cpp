#include "Person.h"



void ch14ex4(void)
{
	PokerPlayer pp;
	//PokerPlayer pp("","");
	pp.Show();
	for (int i = 0; i < 2000; i++)
	{
		cout << pp.Cdraw() << endl;;
	}

}