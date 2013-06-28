#include "chapter16_exercises.h"

static bool IsPalindrome(const std::string & p_String);

void ch16ex2(void)
{
	std::cout << IsPalindrome("Ab,,,,,a") << std::endl;
}

bool IsPalindrome(const std::string & p_String)
{
	std::string chars;
	std::copy_if(p_String.begin(), p_String.end(), std::back_insert_iterator<std::string>(chars), isalpha);
	std::transform(chars.begin(),  chars.end(), chars.begin(), tolower);
	std::string reversed_string(" ", chars.length());
	std::copy(chars.rbegin(), chars.rend(), reversed_string.begin());
	return chars == reversed_string;
}

