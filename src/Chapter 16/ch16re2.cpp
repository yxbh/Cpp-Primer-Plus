#include "chapter16_review.h"

void ch16re2(void)
{

	std::string str = "abcdefg";
	std::transform(str.begin(), str.end(), str.begin(), toupper);
	std::cout << str << std::endl;
	
}
