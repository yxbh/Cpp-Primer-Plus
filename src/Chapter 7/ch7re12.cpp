#include <iostream>
#include "chapter7_review.h"

using namespace std;


static void print_applicant_info(applicant);
static void print_applicant_info2(const applicant *);

void ch7re12()
{
	applicant ap = {"Bob", {123,32,12}};
	print_applicant_info(ap);
	print_applicant_info2(&ap);

}

static void print_applicant_info(applicant a)
{
	cout << a.name << endl;
	cout << "Credit ratings:" << endl;
	for (int i = 0; i < 3; i++)
		cout << "  " << a.credit_ratings[i] << endl;
}

static void print_applicant_info2(const applicant * a)
{
	cout << a->name << endl;
	cout << "Credit ratings:" << endl;
	for (int i = 0; i < 3; i++)
		cout << "  " << a->credit_ratings[i] << endl;
}