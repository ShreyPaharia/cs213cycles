#include "users.h"

string users::get_user_name()
{
	return name;
}
void users::set_user_name(string s)
{
	name = s;
}
int users::get_user_id()
{
	return id;
}
void users::set_user_id(int given_id)
{
	id =given_id;
}
size_t users::get_password()
{
	return password;
}
void users::set_password(size_t given_password)
{
	password = given_password;
}
int users::get_amountDue()
{
	return amountDue;
}
void users::set_amountDue(int a)
{
	amountDue = a;
}
int users::get_cycleOwnedId()
{
	return cycleOwnedId;
}
void users::set_cycleOwnedId(int n)
{
	cycleOwnedId = n;
}
string users::get_hostelNo()
{
	return hostelNo;
}
void users::set_user_hostelNo(string given_hostelNo)
{
	hostelNo = given_hostelNo;
}
bool users::get_isBlackListed()
{
	return isBlackListed;
}
void users::set_isBlackListed(bool val)
{
	isBlackListed = val;
}

bool users::passwordCheck(size_t given_password)
{
	return (password == given_password);
}