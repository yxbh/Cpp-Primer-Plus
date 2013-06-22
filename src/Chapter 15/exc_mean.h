// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>
#include <string>

class base_exception : public std::logic_error
{
private:
	double v1;
	double v2;
public:
	base_exception(double a = 0, double b = 0) : logic_error(""), v1(a), v2(b){}
	virtual const char* what(void) const = 0;
};


class bad_hmean : public base_exception
{
private:
    double v1;
    double v2;
public:
    bad_hmean(double a = 0, double b = 0) : base_exception(a,b) {}
    const char* what(void) const override;
	void mesg();
};

 const char* bad_hmean::what(void) const
 {
	 std::string str(("hmean(" + std::to_string(v1) + ", " + std::to_string(v2) +"): "
              + "invalid arguments: a = -b\n"));
	 return str.c_str();
 }


inline void bad_hmean::mesg()
{   
    std::cout << "hmean(" << v1 << ", " << v2 <<"): "
              << "invalid arguments: a = -b\n";
}

class bad_gmean : public base_exception
{
public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0) : base_exception(a,b) {}
	const char* what(void) const override;
    const char * mesg();
};

 const char* bad_gmean::what(void) const
 {
	 return "gmean() arguments should be >= 0\n";
 }

inline const char * bad_gmean::mesg()
{  
    return "gmean() arguments should be >= 0\n";
}
