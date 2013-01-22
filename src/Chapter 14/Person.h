#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>

// abstract Person base class
class Person
{
private:
protected:
	string firstName;
	string lastName;
public:
	Person(string fn = "", string ln = "")
		: firstName(fn), lastName(ln)
	{}
	virtual ~Person(void) = 0
	{}

	// print details of obj
	virtual void Show(void) const = 0
	{
		cout << "Name: " << firstName << " " << lastName << endl;
	}
};

// Gunslinger class
class Gunslinger : virtual public Person
{
private:
	int drawTime;
public:
	Gunslinger(void)
		: Person()
	{}
	~Gunslinger(void)
	{}
	// return int, draw gun time
	const int Gdraw(void) const
	{
		return drawTime;
	}
	// print details of obj
	virtual void Show(void) const
	{
		Person::Show();
		cout << "Draw time: " << drawTime << endl;
	}
};

// PokerPlayer class
class PokerPlayer : virtual public Person
{
private:

public:
	PokerPlayer(void)
		: Person()
	{}
	PokerPlayer(string fn, string ln)
		: Person(fn, ln)
	{}
	~PokerPlayer(void)
	{}

	// return random card
	const int Cdraw(void) const
	{
		return rand() % 52 + 1;
	}

	// print details of obj
	virtual void Show(void) const
	{
		Person::Show();
		cout << "Next card draw: " << Cdraw() << endl;
	}
};


class BadDude : public Gunslinger, public PokerPlayer
{
private:

public:
	BadDude(void)
		: Person(), Gunslinger(), PokerPlayer()
	{}
	~BadDude(void)
	{}

	// print details of obj
	virtual void Show(void) const
	{
		Gunslinger::Show();
		cout << "Next card draw: " << Cdraw() << endl;
	}
};




#endif

