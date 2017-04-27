#include <iostream>
#include <string>
#include <ctime>

using namespace std;
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
const int rent_per_hour = 10;
const int fixed_rent = 10;
struct date		
{
	int hour, day, month ,year; 
};
class cycles
{
	private:
		string owner;
		int id;
		string user;
		string location;
		int latestTimeByWhichCycleIsToBeReturned;
		date time_taken;
		date time_returned;
		//string condition;
	public:
	cycles(string given_owner,int given_id, string given_location)
	{
		owner=given_owner;
		id=given_id;
		location=given_location;
		latestTimeByWhichCycleIsToBeReturned = 24;
		time_taken = systemTime();
		time_returned = systemTime();
	};
	cycles(string given_owner,int given_id, string given_location,string given_user,int given_latestTimeByWhichCycleIsToBeReturned,date given_time_taken,date given_time_returned)
	{
		owner=given_owner;
		id=given_id;
		location=given_location;
		user=given_user;
		latestTimeByWhichCycleIsToBeReturned=given_latestTimeByWhichCycleIsToBeReturned;
		time_taken=given_time_taken;
		time_returned=given_time_returned;
	};
	
    int countLeapYears(date d);
    int getDifference(date dt1, date dt2);
	int rentHours(date time_returned,date time_taken);		//return no. of hours

	string get_owner();
	void set_owner(string given_owner);
	int get_cycle_id();
	void set_cycle_id(int given_id);
	string get_user();
	void set_user(string given_user);
	string get_cycle_location();
	void set_cycle_location(string given_location);
	int get_latestTimeByWhichCycleIsToBeReturned();
	void set_latestTimeByWhichCycleIsToBeReturned(int given_latestTimeByWhichCycleIsToBeReturned);
	date get_time_taken();
	void set_time_taken();
	date get_time_returned();
	void set_time_returned();

	int cycle_rent_hours();
	
	int availableTime();
	date systemTime();
};