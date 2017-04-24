#include<iostream>
using namespace std;
 
// A date has day 'd', month 'm' and year 'y'
struct Time
{
    int h, d, m, y;
};
 
// To store number of days in all months from January to Dec.
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
 
// This function counts number of leap years before the
// given date
int countLeapYears(Time d)
{
    int years = d.y;
 
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.m <= 2)
        years--;
 
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}
 
// This function returns number of days between two given
// dates
int getDifference(Time dt1, Time dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = dt1.y*365 + dt1.d;
 
    // Add days for months in given date
    for (int i=0; i<dt1.m - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
 
    long int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}

int getHours(Time dt1, Time dt2)
{
    long int n1 = getDifference(dt1,dt2)*24 + dt2.h - dt1.h;
}
// Driver program
int main()
{
    Time dt1 = {23, 28, 2, 2016};     // HH,DD,MM,YYYY
    Time dt2 = {2, 1, 3, 2016};
 
    cout << "No. of hours " << getHours(dt1, dt2) << "\n";
 
    return 0;
}