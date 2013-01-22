#ifndef _Cd2_H_
#define _Cd2_H_

class Cd2	// represents a Cd2 disk
{
private:
	char * performers;
	char * label;
	int selections;		// number of selections
	double playtime;	// playing time in minutes
public:
	// constructors
	Cd2();
	Cd2(const char * s1, const char * s2, const int n, const double x);
	Cd2(const Cd2 & d);
	virtual ~Cd2();
	// methods
	virtual void Report(void) const;	// reports all Cd2 data
	// operator overload
	Cd2 & operator=(const Cd2 & d);
};

// derived class
class ClassicCd2 : public Cd2
{
private:
	char * primarywork;
public:
	// constructors
	ClassicCd2();
	ClassicCd2(const char * s3,	// primary work
		const char * s1,		// performers
		const char * s2,		// label
		const int n, 
		const double x);
	ClassicCd2(const ClassicCd2 & cc);
	// destructor
	virtual ~ClassicCd2();
	// methods
	virtual void Report(void) const;	// reports all Cd2 data
	ClassicCd2 & operator=(const ClassicCd2 & cc);

};





#endif

