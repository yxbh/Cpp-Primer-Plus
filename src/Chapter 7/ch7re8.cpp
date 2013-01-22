#include <iostream>
#include <cstring>

using namespace std;

static int replace(char * str, const char c1, const char c2);

void ch7re8()
{
	char str[255] = "Hello boss!";  // cannot use a pointer with a string literal as its not editable! must use a char array instead.
	cout << "String: " << str << endl << "Target char: 'l'" << endl << "Replacement char: 'e'" << endl << endl;

	int count = replace(str, 'l', 'e');
	cout << "Resulting string: " << str << endl << "Number of char replaced: " << count << endl;

}

static int replace(char * str, const char c1, const char c2)
{
	int replacement_count = 0;
	while(*str)
	{
		if ((*str) == c1){
			(*str) = c2;
			replacement_count++;
		}
		str++;
	}
	return replacement_count;
}