#ifndef _PLORG_H_
#define _PLORG_H_

class Plorg
{
private:
	static const int LEN = 20;
	char name[LEN];
	int ci;
public:
	Plorg(const char * name = "Plorga", int ci = 50);
	void change_ci(const int new_ci);
	void report(void) const;
	~Plorg(void);
};

#endif


