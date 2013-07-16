#include "chapter18_exercises.h"

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info *pi;
public:
	Cpmv(void)
	{
		pi = nullptr;
	}

	Cpmv(std::string q, std::string z)
	{
		pi = new Info();
		pi->qcode = q; pi->zcode = z;
	}

	Cpmv(const Cpmv & cp)
	{
		pi = new Info();
		pi->qcode = cp.pi->qcode; pi->zcode = cp.pi->zcode;
	}

	Cpmv(Cpmv && mv)
	{
		pi = mv.pi;
		mv.pi = nullptr;
	}

	~Cpmv(void)
	{
		delete pi;
	}

	Cpmv & operator=(const Cpmv & cp)
	{
		delete pi;
		pi = new Info();
		pi->qcode = cp.pi->qcode; pi->zcode = cp.pi->zcode;
	}

	Cpmv & operator=(Cpmv && mv)
	{
		delete pi;
		pi = mv.pi;
		mv.pi = nullptr;
	}

	Cpmv operator+(const Cpmv & obj) const
	{
		return Cpmv(this->pi->qcode+obj.pi->qcode, this->pi->zcode+obj.pi->zcode);
	}

	void Display(void) const
	{
		std::cout << "qcode: " << pi->qcode << '\n' << "zcode: " << pi->zcode << '\n';
	}

};


void ch18ex2(void)
{

}
