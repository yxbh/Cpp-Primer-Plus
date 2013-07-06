#include "chapter17_exercises.h"
#include <set>
#include <sstream>

void ch17ex4(void)
{
	std::string filepath_i1(""), filepath_i2(""), filepath_o("");
	std::cout << "Enter input filename1: ";
	getline(std::cin, filepath_i1);
	std::cout << "Enter input filename2: ";
	getline(std::cin, filepath_i2);
	std::cout << "Enter output filename: ";
	getline(std::cin, filepath_o);
	std::fstream fin1, fin2, fout;
	fin1.open(filepath_i1, std::ios::in);
	fin2.open(filepath_i2, std::ios::in);
	fout.open(filepath_o, std::ios::out);
	
	std::istringstream ss;
	std::string buffer("");
	while ( (fin1.good() || fin2.good()) && fout.good())
	{
		std::set<std::string> wordSet;

		getline(fin1, buffer);
		ss = std::istringstream(buffer);
		std::move(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::insert_iterator<std::set<std::string>>(wordSet, wordSet.begin()));
		getline(fin2, buffer);
		ss = std::istringstream(buffer);
		std::move(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::insert_iterator<std::set<std::string>>(wordSet, wordSet.begin()));
		
		std::move(wordSet.begin(), wordSet.end(), std::ostream_iterator<std::string>(fout, " "));
		fout << std::endl;
	}

}
