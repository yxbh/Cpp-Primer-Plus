#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of 
// an array of student structures and an int representing the 
// number of elements of the array. The function solicits and 
// stores data about students. It terminates input upon filling 
// the array or upon encountering a blank line for the student 
// name. The function returns the actual number of array elements 
// filled. 
static int getinfo(student pa[], int n); 
// display1() takes a student structure as an argument 
// and displays its contents 
static void display1(student st); 
// display2() takes the address of student structure as an 
// argument and displays the structure's contents 
static void display2(const student * ps); 
// display3() takes the address of the first element of an array 
// of student structures and the number of array elements as 
// arguments and displays the contents of the structures 
static void display3(const student pa[], int n);


void ch7ex9()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n') 
		continue;
	student * ptr_stu = new student[class_size];     
	int entered = getinfo(ptr_stu, class_size);     
	for (int i = 0; i < entered; i++) { 
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}     
	display3(ptr_stu, entered);     
	delete [] ptr_stu;     
	cout << "Done\n";


}

static int getinfo(student pa[], int n)
{
	int count = 0;
	while (count < n) {
		cout << "Enter information for student " << count + 1 << endl;

		cout << "Name: ";
		char ch, str_buf[SLEN];
		int i = 0;
		while ((i < SLEN) && (cin.get(ch)) && (ch != '\n'))
		{
			str_buf[i] = ch;
			++i;
		}
		str_buf[i] = '\0';
		if (str_buf[0] == '\n')
			break;
		//strncpy(pa[count].fullname, str_buf, SLEN);
		strncpy_s(pa[count].fullname, str_buf, SLEN);  // not portable

		cout << "Hobby: ";
		i = 0;
		while ((i < SLEN) && cin.get(ch) && (ch != '\n'))
		{
			str_buf[i] = ch;
			++i;
		}
		str_buf[i] = '\0';
		//strncpy(pa[count].hobby, str_buf, SLEN);
		strncpy_s(pa[count].hobby, str_buf, SLEN);  // not portable

		cout << "ooplevel: ";
		cin >> pa[count].ooplevel;
		cin.get();
		++count;
	}
	return count; 
}

static void display1(student st)
{
	cout << st.fullname << endl;
	cout << "  Hobby: " << st.fullname << endl;
	cout << " ooplevel: " << st.ooplevel << endl;
}

static void display2(const student * ps)
{
	cout << ps->fullname << endl;
	cout << "  Hobby: " << ps->fullname << endl;
	cout << " ooplevel: " << ps->ooplevel << endl;
}

static void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << pa[i].fullname << endl;
		cout << "  Hobby: " << pa[i].fullname << endl;
		cout << " ooplevel: " << pa[i].ooplevel << endl;
	}
}