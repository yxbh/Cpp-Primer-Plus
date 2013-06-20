/*
*	documentation is in the implementation details
*/
#ifndef _BH_UTIL_H_
#define _BH_UTIL_H_
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using std::string;

namespace bh_lib {namespace console_util
{
	extern void pbe(void);
	
	extern void bh_unexpected_error(const string &);


	extern bool valid_choice(const char, const string);
	extern bool valid_choice(const string, const string);
	extern bool valid_choice(const string, std::vector<string>);
	extern void reset_valid_choice_flag(void);

	// utility functions
	extern void bh_sleep(const long);
	extern void bh_clear_console_screen(void);
	extern const string bh_flush_cin(std::istream &);
	extern const string bh_current_time_date(void); 

	// FLAG
	extern bool valid_choice_flag;

} // end of bh::console_util


namespace util
{
	extern const string int_to_binary(int);
	extern const int binary_to_int(const string &);


	template<class T> void safe_delete(const T * ptr)
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
	template<class T> void safe_delete_array(const T * ptr_arr)
	{
		if (ptr_arr != nullptr)
		{
			delete [] ptr_arr;
			ptr_arr = nullptr;
		}
	}

}// end of bh::util


} 

#endif