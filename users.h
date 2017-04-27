#include <iostream>
#include <string>

using namespace std;

class users
{
	private:
		string name;
		int id;
		size_t password;
		int amountDue;
		int cycleOwnedId;
		string hostelNo;
		bool isBlackListed;
		
	public:
	users(string given_name,int given_id,size_t given_password, string given_hostelNo){
		name=given_name;
		id=given_id;
		password=given_password;
		hostelNo=given_hostelNo;
		amountDue = 0 ;
		cycleOwnedId = -1 ;
		isBlackListed = 0 ;
	};
	users(string given_name,int given_id,size_t given_password, string given_hostelNo,int given_amountDue,int given_cycleOwnedId,bool given_isBlackListed)
	{
		name=given_name;
		id=given_id;
		password=given_password;
		hostelNo=given_hostelNo;
		amountDue=given_amountDue;
		cycleOwnedId=given_cycleOwnedId;
		isBlackListed=given_isBlackListed;
	};
	string get_user_name();
	void set_user_name(string s);
	int get_user_id();
	void set_user_id(int given_id);
	size_t get_password();
	void set_password(size_t given_password);
	int get_amountDue();
	void set_amountDue(int a);
	int get_cycleOwnedId();
	void set_cycleOwnedId(int n);
	string get_hostelNo();
	void set_user_hostelNo(string given_hostelNo);
	bool get_isBlackListed();
	void set_isBlackListed(bool val);

	bool passwordCheck(size_t password);
	
};