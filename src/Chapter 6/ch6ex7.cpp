#include <iostream>
#include <string>

using namespace std;

void ch6ex7()
{
	cout << " - Chapter 6 Exercise 7 - " << endl << endl;

	int vowel_count, consonant_count, other;
	vowel_count = consonant_count = other = 0;

	string input;
	cout << "Enter words (q to quit):" << endl << "== ";
	cin >> input;
	while(input != "q")
	{
		if (isalpha(input[0])) {
			switch(input[0]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++vowel_count;
				break;
			default:
				++consonant_count;
				break;
			}
		} else {
			++other;
		}
		
		cin >> input;
	}

	if (input == "q" && (vowel_count == 0 && consonant_count == 0 && other == 0)) {
		cout << "Press Enter to exit..." << endl;
		return;
	}

	cout << vowel_count << " words beginning with vowels" << endl;
	cout << consonant_count << " words beginning with consonants" << endl;
	cout << other << " others";
}