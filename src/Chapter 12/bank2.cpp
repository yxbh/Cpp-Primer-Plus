#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
namespace ch12 {
	const int MIN_PER_HR = 60;
	const double ATM = 1;

	static bool newcustomer(double x); // is there a new customer?

	void bank2()
	{
		using std::cin;
		using std::cout;
		using std::endl;
		using std::clog;
		using std::ios_base;
		// setting things up
		std::srand((unsigned)std::time(0));    //  random initializing of rand()

		cout << "Case Study: Bank of Heather Automatic Teller\n";
		cout << "Enter maximum size of queue: ";
		int qs;
		cin >> qs;
		Queue line1(qs);        // line queue holds up to qs people
		Queue line2(qs);		// second queue

		cout << "Enter the number of simulation hours: ";
		int hours;              //  hours of simulation
		cin >> hours;
		// simulation will run 1 cycle per minute
		long cyclelimit = MIN_PER_HR * hours; // # of cycles

		cout << "Enter the average number of customers per hour: ";
		double perhour;         //  average # of arrival per hour
		cin >> perhour;
		double min_per_cust;    //  average time between arrivals
		min_per_cust = MIN_PER_HR * ATM / perhour;

		Item temp;              //  new customer data
		long turnaways = 0;     //  turned away by full queue
		long customers = 0;     //  joined the queue
		long served = 0;        //  served during the simulation
		long sum_line = 0;      //  cumulative line length
		int wait_time = 0;      //  time until autoteller is free
		long line_wait = 0;     //  cumulative time in line

		enum cline {line_1, line_2, LINE_FULL, EOT};
		cline cur_line = EOT;
		// running the simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line1.isfull() && line2.isfull())
				{
					//clog << "Customer turned away" << endl;
					turnaways++;
				}
				else if (line2.isfull() && !line1.isfull())
				{
					//clog << "Customer joined line 1" << endl;
					cur_line = line_1;
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line1.enqueue(temp); // add newcomer to line
				}
				else if (line1.isfull() && !line2.isfull())
				{
					//clog << "Customer joined line 2" << endl;
					cur_line = line_2;
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line2.enqueue(temp); // add newcomer to line
				}
				else if (!line2.isfull() && 
					!line1.isfull() &&
					(line2.queuecount() >= line1.queuecount())
					)
				{
					//clog << "Customer joined line 1" << endl;
					cur_line = line_1;
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line1.enqueue(temp); // add newcomer to line
				}
				else if (!line2.isfull() && 
					!line1.isfull() &&
					(line2.queuecount() <= line1.queuecount())
					)
				{
					//clog << "Customer joined line 2" << endl;
					cur_line = line_2;
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line2.enqueue(temp); // add newcomer to line
				}
				else
					cur_line = LINE_FULL;
			}

			// handle line 1
			if (wait_time <= 0 && !line1.isempty())
			{
				line1.dequeue (temp);      // attend next customer
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line1.queuecount();
			// handle line 2
			if (wait_time <= 0 && !line2.isempty())
			{
				line2.dequeue (temp);      // attend next customer
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line2.queuecount();

			cur_line = EOT;
		}

		// reporting results
		if (customers > 0)
		{
			cout << "customers accepted: " << customers << endl;
			cout << "  customers served: " << served << endl;
			cout << "         turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double) sum_line / cyclelimit << endl;
			cout << " average wait time: "
				<< (double) line_wait / served << " minutes\n";
		}
		else
			cout << "No customers!\n";
		cout << "Done!\n";
		cin.get();
		return;
	}

	//  x = average time, in minutes, between customers
	//  return value is true if customer shows up this minute
	static bool newcustomer(double x)
	{
		return (std::rand() * x / RAND_MAX < 1); 
	}


}