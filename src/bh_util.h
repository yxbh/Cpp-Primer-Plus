#ifndef _BH_UTIL_H_
#define _BH_UTIL_H_

#include <string>
#include <vector>
#include <iostream>

namespace bh {namespace console_util
{
	extern void pbe(void);
	extern void bh_unexpected_error(const std::string &);


	extern bool valid_choice(const char, const std::string);
	extern bool valid_choice(const std::string, const std::string);
	extern bool valid_choice(const std::string, std::vector<std::string>);
	extern void reset_valid_choice_flag(void);

	// utility functions
	extern void bh_sleep(const long);
	extern void bh_clear_console_screen(void);
	extern const std::string bh_flush_cin(std::istream &);
	extern const std::string bh_current_time_date(void); 

	// FLAG
	extern bool valid_choice_flag;

}} // end of bh::console_util

#endif