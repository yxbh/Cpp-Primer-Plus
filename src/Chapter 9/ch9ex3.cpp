#if defined(_WIN32) || defined(_WIN64)
#define _CRT_SECURE_NO_WARNINGS // for strcpy()
#endif
#include <iostream>
#include <new>
#include <cstring> // for strcpy()
using namespace std;

namespace {
	struct chaff
	{
		char dross[20];
		int slag;
	};

	char mem_buf[500];  // memory buffer

	void show_chaff(chaff &);
}



void ch9ex3(void)
{
	chaff * chaff_arr = new(mem_buf) chaff[2];  // placement new to allocate the memory to my own buffer
	strcpy(chaff_arr[0].dross, "Boss");
	chaff_arr[0].slag = 123;
	show_chaff(chaff_arr[0]);

}

namespace {
	void show_chaff(chaff & c)
	{
		cout << c.dross << "  " << c.slag << endl;
	}
}