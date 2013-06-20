/*
bh_util

Ben Huang utility/utilities

author: YANXIANG (BEN) HUANG
version: 22/12/2012   v0.0.7

*/
#include "bh_util.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstring>


namespace bh_lib {namespace console_util
{
	// FLAG
	bool valid_choice_flag = true;


	/*
	prints error msg to cerr then calls EXIT_FAILURE.
	*/
	void bh_unexpected_error(const std::string & function_name)
	{
		std::cerr << "ERROR: unexpected error calling '" << function_name << "'..." << std::endl;
		std::cerr << "Press Enter to exit..." << std::endl;
		pbe();
		exit(EXIT_FAILURE);
	}


	bool valid_choice(const char input, const std::string opt_list)
	{
		if (opt_list.find(input) == std::string::npos){ // npos = failed search
			valid_choice_flag = false;
			return false;
		}
		return true;
	}

	bool valid_choice(const std::string input, const std::string opt_list)
	{
		if (opt_list.find(input) == std::string::npos){ // npos = failed search
			valid_choice_flag = false;
			return false;
		}
		return true;
	}

	bool valid_choice(const std::string input, std::vector<std::string> opt_list)
	{
		std::vector<std::string>::iterator it = std::find(opt_list.begin(), opt_list.end(), input);
		if (it == opt_list.end()){
			valid_choice_flag = false;
			return false;
		}
		return true;
	}


	void reset_valid_choice_flag(void)
	{
		valid_choice_flag = true;
	}

	/*
	Flushes new line char in the input stream. Does not work properly(requires 2 enter/s) in the case where there's been no input before calling this function
	*/
	void pbe(void) //pause before exit
	{
		std::cin.ignore(INT_MAX, '\n'); // All char up to the next '\n' are ignored
		std::cin.clear();
	}

	/*
	Sleep for long milli_sec amount of time.
	*/
	void bh_sleep(const long milli_sec)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milli_sec));
	}


	// clears the console screen
	void bh_clear_console_screen(void)
	{
		//remember to include <cstdlib> 
#if defined(WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64) || defined(__WINDOWS__)
		std::system ( "CLS" );
#else
		// Assume POSIX
		std::system ( "clear" );  // not tested
#endif
	}


	// flush cin stream
	// this is used in a cin >> non-string-variable situation
	const std::string bh_flush_cin(std::istream & os)
	{
		if (!os) {
			os.clear();
			std::string buffer;
			os >> buffer;
			os.get();
			return buffer;
		}
		return NULL;
	}


	// return a string containing the current time and date
	const std::string bh_current_time_date(void)
	{
#if defined(WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64) || defined(__WINDOWS__)
#pragma warning (push)
#pragma warning (disable: 4996) // MSCV warning for localtime()
		// current date/time based on current system
		time_t now = time(0);		// seconds since the 'linux date'
		tm *ltm = localtime(&now);	// create the tm struct for time data

		std::string current_time_date;
		current_time_date = std::to_string(ltm->tm_hour) + ":";		// hour
		current_time_date += std::to_string(ltm->tm_min) + ":";		// minute
		current_time_date += std::to_string(ltm->tm_sec) + "-";		// second
		current_time_date += std::to_string(ltm->tm_mday) + "/";	// day
		current_time_date += std::to_string(1+ ltm->tm_mon) + "/";	// month
		current_time_date += std::to_string(1900 + ltm->tm_year);	// year

		return current_time_date;
#pragma warning (pop)
#endif
	}

} // end of bh::console_util

namespace util
{
	const std::string int_to_binary(int x)
	{
		std::string binary_str = "";
		while (x > 0)
		{
			switch(x % 2)
			{
			case 0:
				binary_str = '0' + binary_str;
				break;
			case 1:
				binary_str = '1' + binary_str;
				break;
			}
			x /= 2;
		}
		return binary_str;
	}

	const int binary_to_int(const string & str)
	{
		int return_val = 0;
		unsigned step = 1;
		unsigned len = str.size();
		for (int i = len-1; i >= 0; i--)
		{
			switch(str[i])
			{
			case '0':
				return_val += step * 0;
				break;
			case '1':
				return_val += step * 1;
				break;
			}
			step *= 2;
		}
		return return_val;
	}




} // end of bh_lib::util


} 