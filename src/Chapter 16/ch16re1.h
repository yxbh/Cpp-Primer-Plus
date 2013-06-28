#ifndef _CH16REVIEW1_
#define _CH16REVIEW1_
#include <string>

class RQ1
{
private:
	std::string st;
public:
	RQ1() : st("") { }
	RQ1(const std::string & p_Str) : st(p_Str){ }
	RQ1(const RQ1 & p_RQ) : st(p_RQ.st) {}
	~RQ1() {}
	RQ1& operator=(const RQ1 & p_RQ);
	// more stuff
};


#endif