#ifndef _CD_H_
#define _CD_H_

class Cd	// represents a CD disk
{
private:
	char performers[50];
	char label[20];
	int selections;		// number of selections
	double playtime;	// playing time in minutes
public:
	// constructors
	Cd();
	Cd(const char * s1, const char * s2, const int n, const double x);
	Cd(const Cd & d);
	virtual ~Cd() {}
	// methods
	virtual void Report(void) const;	// reports all CD data
	// operator overload
	Cd & operator=(const Cd & d);
};

// derived class
class ClassicCd : public Cd
{
private:
	char primarywork[50];
public:
	// constructors
	ClassicCd() {}
	ClassicCd(const char * s3,	// primary work
		const char * s1,		// performers
		const char * s2,		// label
		const int n, 
		const double x);
	ClassicCd(const ClassicCd & cc);
	// methods
	virtual ~ClassicCd() { Cd::~Cd(); }
	virtual void Report(void) const;	// reports all CD data
	ClassicCd & operator=(const ClassicCd & cc);

};





#endif

