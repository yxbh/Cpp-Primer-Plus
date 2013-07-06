#include "chapter17_exercises.h"

void ch17ex2(void)
{
	std::string filepath("");
	std::cout << "Enter filename: ";
	getline(std::cin, filepath);
	std::fstream fout;
	fout.open(filepath, std::ios::out);
	
	std::cout << "Start typing: " << std::endl;
	char buf = 0;
	while (std::cin.good())
	{
		std::cin.get(buf);
		fout << buf;
	}

}
