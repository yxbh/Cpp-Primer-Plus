#ifndef _GOLF_H_
#define _GOLF_H_
#include <string>
using std::string;

class Golf
{
private:
	std::string fullname;
	int handicap;
public:
	Golf(const std::string fname, const int hc);
	~Golf();
	void showgolf(void) const;
	const int setgolf(void);
};


#endif


