#define _CRT_SECURE_NO_WARNINGS
#include "Cd.h"
#include <cstring>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//================================================
// Cd constructors
//================================================

Cd::Cd(){}

Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
	strncpy(performers, s1, 50);
	strncpy(label, s2, 20);
	selections = n;
	playtime = x;
}

//================================================
//	Class Cd copy constructor
//================================================
Cd::Cd(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

//================================================
//	Class Cd: report all Cd data
//================================================
void Cd::Report(void) const
{
	cout << performers << ", " << label << ", " << selections << ", " << playtime << endl;
}

//================================================
//	Class Cd: overload op=
//================================================
Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

//================================================
//	Class ClassicCd: constructor
//================================================
ClassicCd::ClassicCd(const char * s3,	// primary work
		const char * s1,		// performers
		const char * s2,		// label
		const int n, 
		const double x
		) : Cd(s1, s2, n, x)
{
	strncpy(primarywork, s3, 50);
}

//================================================
//	Class ClassicCd: copy constructor
//================================================
ClassicCd::ClassicCd(const ClassicCd & cc) : Cd(cc)
{
	strcpy(primarywork, cc.primarywork);
}

//================================================
//	Class ClassicCd: report all Cd data
//================================================
void ClassicCd::Report(void) const
{
	Cd::Report();
	cout << primarywork << endl;
}

//================================================
//	Class ClassicCd: overload op=
//================================================
ClassicCd & ClassicCd::operator=(const ClassicCd & cc)
{
	if (this == &cc)
		return *this;
	Cd::operator=(cc);
	strcpy(primarywork, cc.primarywork);
	return *this;
}