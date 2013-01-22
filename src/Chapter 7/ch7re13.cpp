#include <iostream>
#include "chapter7_review.h"

void f1(applicant * a);
const char * f2(const applicant * a1, const applicant * a2);

typedef void (*p1)(applicant *);
typedef const char * (*p2)(const applicant *, const applicant *);



void ch7re13()
{
	
	p1 f1_pt_arr[5] = {f1, f1, f1, f1, f1};
	p2 f2_pt_arr[10] = {f2, f2, f2, f2, f2, f2, f2, f2, f2, f2};

	std::cout << f1_pt_arr << std::endl;
	std::cout << f2_pt_arr << std::endl;
}

void f1(applicant * a)
{
	std::cout << a->name << std::endl;
	return;
}

const char * f2(const applicant * a1, const applicant * a2)
{
	bool crap = true;
	if (crap)
		return &a2->name[0];
	return &a1->name[0];
}