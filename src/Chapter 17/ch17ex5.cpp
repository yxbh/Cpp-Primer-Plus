#include "chapter17_exercises.h"
#include <set>
#include <vector>
#include <algorithm>

void ch17ex5(void)
{
	std::string filepath_i1("mat.dat"), filepath_i2("pat.dat");
	std::fstream fin1, fin2;
	fin1.open(filepath_i1, std::ios::in);
	fin2.open(filepath_i2, std::ios::in);
	if (fin1 && fin2)
		std::cout << "files opened.\n";
	else
		exit(EXIT_FAILURE);

	std::set<std::string> mat;
	std::move(std::istream_iterator<std::string>(fin1), std::istream_iterator<std::string>(), std::insert_iterator<std::set<std::string>>(mat, mat.end()));
	std::set<std::string> pat;
	std::move(std::istream_iterator<std::string>(fin2), std::istream_iterator<std::string>(), std::insert_iterator<std::set<std::string>>(pat, pat.end()));

	std::cout << "Mat's friends:\n";
	for ( auto f : mat)
	{
		std::cout.width(20);
		std::cout << std::right << f << std::endl;
	}

	std::cout << "Pat's friends:\n";
	for ( auto f : pat)
	{
		std::cout.width(20);
		std::cout << std::right << f << std::endl;
	}

	std::cout << "Union:\n";
	std::set<std::string> unionf;
	std::set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), std::insert_iterator<std::set<std::string>>(unionf, unionf.begin()));
	for ( auto f : unionf)
	{
		std::cout.width(20);
		std::cout << std::right << f << std::endl;
	}

}
