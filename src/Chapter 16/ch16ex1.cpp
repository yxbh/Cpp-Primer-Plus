#include "chapter16_exercises.h"

static bool IsPalindrome(const std::string & p_String);

void ch16ex1(void)
{
	std::cout << IsPalindrome("abab") << std::endl;
}

bool IsPalindrome(const std::string & p_String)
{
	std::string reversed_string(" ", p_String.length());
	std::copy(p_String.rbegin(), p_String.rend(), reversed_string.begin());
	return p_String == reversed_string;
}
