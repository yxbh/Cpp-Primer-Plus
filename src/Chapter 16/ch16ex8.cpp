#include "chapter16_exercises.h"

typedef std::vector<std::string> nameList;

static nameList GetNames(void);
static nameList Merge(nameList list1, nameList list2);

void ch16ex8(void)
{
	// get first name list
	nameList list1 = GetNames();
	// get second name list
	nameList list2 = GetNames();
	// merge the two and display
	auto final_namelist = Merge(list1, list2);
}

nameList GetNames(void)
{
	nameList list;
	std::string name("q");
	std::cout << "Enter name, \"q\" to finish: ";
	while (std::getline(std::cin, name) && name != "q")
	{
		list.push_back(name);
		std::cout << "Enter name, \"q\" to finish: ";
	}
	return list;
}

nameList Merge(nameList list1, nameList list2)
{
	std::set<std::string> combined_list;
	for ( auto name : list1) combined_list.insert(name);
	for ( auto name : list2) combined_list.insert(name);
	for ( auto name : combined_list) std::cout << name << " " << std::endl;
	return std::vector<std::string>(combined_list.begin(), combined_list.end());
}
