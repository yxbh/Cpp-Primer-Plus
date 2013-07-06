#include "chapter17_exercises.h"

void ch17ex3(void)
{
	std::string filepath_i(""), filepath_o("");
	std::cout << "Enter input filename: ";
	getline(std::cin, filepath_i);
	std::cout << "Enter output filename: ";
	getline(std::cin, filepath_o);
	std::fstream fin, fout;
	fin.open(filepath_i, std::ios::in | std::ios::binary);
	fout.open(filepath_o, std::ios::out | std::ios::binary);
	
	char buf(0);
	while (fin.good() && fout.good())
	{
		fin.read(&buf, sizeof buf); fout.write(&buf, sizeof buf);
	}

	std::cout << "Done" << std::endl;
}
