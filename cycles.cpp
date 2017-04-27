#include "cycles.h"


int cycles::countLeapYears(date d)
{
    int years = d.year;
 
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.month <= 2)
        years--;
 
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}
int cycles::getDifference(date dt1, date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = dt1.year*365 + dt1.day;
 
    // Add days for months in given date
    for (int i=0; i<dt1.month - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
 
    long int n2 = dt2.year*365 + dt2.day;
    for (int i=0; i<dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}
int cycles::rentHours(date time_returned,date time_taken)
{
	long int n1 = getDifference(time_taken,time_returned)*24 + time_returned.hour - time_taken.hour;
}
int cycles::cycle_rent_hours()
{
	return rentHours(time_returned,time_taken);
}
date cycles::systemTime()
{
	date t;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	t.year = 1900 + ltm->tm_year;
	t.month = 1 + ltm->tm_mon;
	t.day = ltm->tm_mday;
	t.hour = ltm->tm_hour;
	return t;
}

string cycles::get_owner()
{
	return owner;
}
void cycles::set_owner(string given_owner)
{
	owner = given_owner;
}
int cycles::get_cycle_id()
{
	return id;
}
void cycles::set_cycle_id(int given_id)
{
	id = given_id;
}
string cycles::get_user()
{
	return user;
}
void cycles::set_user(string given_user)
{
	user = given_user;
}
string cycles::get_cycle_location()
{
	return location;
}
void cycles::set_cycle_location(string given_location)
{
	location = given_location;
}
int cycles::get_latestTimeByWhichCycleIsToBeReturned()
{
	return latestTimeByWhichCycleIsToBeReturned;
}
void cycles::set_latestTimeByWhichCycleIsToBeReturned(int given_latestTimeByWhichCycleIsToBeReturned)
{
	latestTimeByWhichCycleIsToBeReturned = given_latestTimeByWhichCycleIsToBeReturned;
}

void cycles::set_time_taken()
{
	time_taken = systemTime();
}
void cycles::set_time_returned()
{
	time_returned = systemTime();
}
date cycles::get_time_returned()
{
	return time_returned;
}
date cycles::get_time_taken()
{
	return time_taken;
}
int cycles::availableTime()
{
	date t = systemTime();
	return latestTimeByWhichCycleIsToBeReturned - rentHours(time_returned,t);
}