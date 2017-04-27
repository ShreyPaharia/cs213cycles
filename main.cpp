#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <vector>
#include <fstream>
#include <termios.h>
#include <unistd.h>
//#include "cycles.h"
#include "cycles.cpp"
//#include "users.h"
#include "users.cpp"

using namespace std;

vector<users> u;
vector<cycles> c;

void get_userData() 
{
	ifstream userfile ("users.txt") ;
	string line ;
	string temp ;
	int letter_iter , word_iter ;
	string user_name ,user_hostelNo ;
	size_t password;
	int user_id , amountDue , cycleOwnedId ,blacklisted ;
	bool is_Blacklisted ;

	if(userfile.is_open()) {
		while(getline(userfile,line)){
			  letter_iter=0,word_iter=0 ;
			
			for(int letter_iter=0 ; letter_iter<line.length() ; letter_iter++) {
				temp.clear() ;
					while(line[letter_iter]!='\t' and letter_iter<line.length()){
						temp.push_back(line[letter_iter]) ;
						letter_iter++;	
					}
				
				if(word_iter==0){
					user_name = temp ;
				}
				else if(word_iter==1){
					user_id = stoi(temp) ;
				}
				else if(word_iter==2)
				{
					stringstream sstream(temp);
					size_t result;
					sstream >> result;
					password = result;
				}
				else if(word_iter==3){
					amountDue = stoi(temp) ;
				}
				else if(word_iter==4){
					cycleOwnedId = stoi(temp) ;
				}
				else if(word_iter==5){
					user_hostelNo = temp;
				}
				else if(word_iter==6){
					blacklisted = stoi(temp) ;
					is_Blacklisted = blacklisted;
				}
				word_iter++ ;	
			}
			users u1(user_name,user_id,password,user_hostelNo,amountDue,cycleOwnedId,is_Blacklisted) ;
			u.push_back(u1) ;
		}	
	}	 
}

void get_cycleData() 
{
	ifstream cyclefile ("cycles.txt") ;
	string line ;
	string temp ;
	int letter_iter , word_iter ;
	string owner,user,location ;
	int cycle_id, latestTimeByWhichCycleHasToBeReturned;
	date time_taken,time_returned ;

	if(cyclefile.is_open())
	{
		while(getline(cyclefile,line))
		{
			  letter_iter=0,word_iter=0 ;
			
			for(int letter_iter=0 ; letter_iter<line.length() ; letter_iter++)
			{
				temp.clear() ;
					while(line[letter_iter]!='\t' and letter_iter<line.length())
					{
						temp.push_back(line[letter_iter]) ;
						letter_iter++;
						
					}
				
				if(word_iter==0){
					owner = temp ;
				}
				else if(word_iter==1){
					cycle_id = stoi(temp) ;
				}
				else if(word_iter==2){
					user = temp ;
				}
				else if(word_iter==3){
					location = temp ;
				}
				else if(word_iter==4){
					latestTimeByWhichCycleHasToBeReturned = stoi(temp) ;
				}
				else if(word_iter==5){
					time_taken.hour = stoi(temp) ;
				}
				else if(word_iter==6){
					time_taken.day = stoi(temp);
				}
				else if(word_iter==7){
					time_taken.month = stoi(temp) ;
				}
				else if(word_iter==8){
					time_taken.year = stoi(temp) ;
				}
				else if(word_iter==9){
					time_returned.hour = stoi(temp) ;
				}
				else if(word_iter==10){
					time_returned.day = stoi(temp) ;
				}
				else if(word_iter==11){
					time_returned.month = stoi(temp) ;
				}
				else if(word_iter==12){
					time_returned.year = stoi(temp);
				}
				
				word_iter++;	
			}

			cycles c1(owner,cycle_id,location,user,latestTimeByWhichCycleHasToBeReturned,time_taken,time_returned) ;
				c.push_back(c1) ;
		}	
	}	 
}

void set_cycleData(vector<cycles> c) {

	ofstream cyclefile ;
	cyclefile.open("cycles.txt") ;

	for(int i=0 ; i<c.size() ; i++){
			string owner = c[i].get_owner();
			int cycle_id = c[i].get_cycle_id();
			string user = c[i].get_user();
			string location = c[i].get_cycle_location() ;
			int latestTimeToReturn = c[i].get_latestTimeByWhichCycleIsToBeReturned();
			date time_taken = c[i].get_time_taken();
			date time_returned = c[i].get_time_returned();

			cyclefile << owner <<'\t'<< cycle_id << '\t' << user << '\t'<<location<<'\t' << latestTimeToReturn << '\t' << time_taken.hour<<'\t'<< time_taken.day<<'\t'<< time_taken.month<<'\t'<< time_taken.year<<'\t'<< time_returned.hour<<'\t'<< time_returned.day<<'\t'<< time_returned.month<<'\t'<< time_returned.year<<'\t'<<'\n' ;
	}
	cyclefile.close() ;
}

void set_userData(vector<users> u) {

	ofstream userfile ;
	userfile.open("users.txt") ;

	for(int i=0 ; i<u.size() ; i++){
			string user_name = u[i].get_user_name();
			int user_id = u[i].get_user_id();
			size_t password = u[i].get_password();
			int amountDue = u[i].get_amountDue();
			int cycleOwnedId = u[i].get_cycleOwnedId();
			string hostelNo = u[i].get_hostelNo();
			bool is_Blacklisted = u[i].get_isBlackListed();

			userfile << user_name <<'\t'<< user_id << '\t' << password << '\t' << amountDue << '\t' << cycleOwnedId <<'\t' << hostelNo <<'\t'<<is_Blacklisted<<'\n' ;
	}
	userfile.close() ;
}
int take_intInput(){
	int int_entry ;
	cin>>int_entry;
		while(std::cin.fail()) {
			        cout << "Invalid Entry! Please enter a valid entry ." << endl;
			        cin.clear();
			        cin.ignore(256,'\n');
			        cin >> int_entry;
			    }
	return int_entry ;
}

string inputPassword()
{
	termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    cin>>s;
    cout<<endl;
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return s;
}
void signUp()
{
	string name;
	int id;
	string password,confirm_password;
	string location;
	cout<<"Enter your name \n";
	cin>>name;
	cout<<"Enter your location \n";
	cin>>location;
	
	while(1)
	{
		cout<<"Enter Password \n";
		password=inputPassword();
		cout<<"Confirm Password\n";
		confirm_password = inputPassword();
		if(confirm_password==password)
		{
			id=u.size();
			cout<<"Your ID is "<<id<<"\n";
			break;
		}
		else
		{
			cout<<"Password does not match. Please try again \n";
		}
	}
	hash <string> pass_hash;
	size_t passwordhash = pass_hash(password);
	users new_user(name,id,passwordhash,location);
	new_user.set_cycleOwnedId(-1);
	u.push_back(new_user);
	cout<<"You have been successfully added to the Cycle Rental Portal. If you own a cycle then add one after Signing In \n";
}

void selectCycle(int user_id,string location) {
	for (int i=0 ; i<c.size() ; i++) {
		if(c[i].get_cycle_location()==location && c[i].get_user().empty() && c[i].get_cycle_id()!=-1 && c[i].get_owner() != "Shop")
			cout<<c[i].get_cycle_id()<<'\t'<<c[i].availableTime()<<'\t'<<rent_per_hour;
		else if(c[i].get_cycle_location()==location && c[i].get_user().empty() && c[i].get_cycle_id()!=-1 && c[i].get_owner() == "Shop")
			cout<<c[i].get_cycle_id()<<'\t'<<"24"<<'\t'<<rent_per_hour ;
	}
	int cycleid ;
	cout<<"Enter the cycle id of the cycle which you want to take.\n" ;
	cin>>cycleid ;
	c[cycleid].set_time_taken();
	c[cycleid].set_user(u[user_id].get_user_name());
	cout<<"You have successfully rented the cycle with id "<<cycleid<<"\nKindly return it in "<<c[cycleid].availableTime()<<" hours"<<endl;
}

int rent_cycle(int user_id , string location) 
{
	int cycleOwnedId = u[user_id].get_cycleOwnedId() ;
	bool blacklisted = u[user_id].get_isBlackListed() ;
	bool yes ;
	if( cycleOwnedId != -1 ){ 
		if(c[cycleOwnedId].get_user().empty() && c[cycleOwnedId].get_cycle_location() == location){                  // if user id not owner then cycleOwnedId = -1
			cout << "Your cycle is available you can take it.\n" ;
			return 0;
		}
		else if(!blacklisted){
			cout << "Your cycle is not available right now, but you can rent a cycle.\nWould you like to avail the services?\nEnter 1 if Yes and 0 if No.\n" ;
			cin >> yes;
			if(yes) {
				selectCycle(user_id,location);
				return 0 ;
			}
			else
				return 0 ;
		}
		else
			cout << "Your cycle is not available and you have been blacklisted because of large amount of unpaid payment.\nPlease pay the due amount if you want to avail the renting services.\n" ;
			return -1 ;
	}
	else if(!blacklisted){
		selectCycle(user_id,location);
		return 0 ;
	}
	else{
		cout << "You have been blacklisted because of large amount of unpaid payment.\nPlease pay the due amount if you want to avail the renting services.\n" ;
		return -1 ;
	}
}

int get_cycleIdOfUser(int user_id)
{
	int i =0;
	while(1)
	{
		if(u[user_id].get_user_name() == c[i].get_user())
			break;
		i++;
	}
	return c[i].get_cycle_id();
}

void update(int user_id, int cycle_id,string location)
{
	c[cycle_id].set_time_returned();
	int t = c[cycle_id].cycle_rent_hours();
	c[cycle_id].set_cycle_location(location);
	int amount = fixed_rent + t*rent_per_hour;
	int amountDue = u[user_id].get_amountDue();
	amountDue += amount;
	u[user_id].set_amountDue(amountDue);
	c[cycle_id].set_latestTimeByWhichCycleIsToBeReturned(c[cycle_id].availableTime());
}
void return_cycle(int user_id,string location)
{
	int cycle_id = get_cycleIdOfUser(user_id);
	if (u[user_id].get_cycleOwnedId() != -1)				//user == owner
	{
		if(u[user_id].get_cycleOwnedId() == cycle_id)
		{
			c[cycle_id].set_cycle_location(location);
			int t;
			cout<<"Please specify the time after which you need the cycle back.";
			cin>>t;
			c[cycle_id].set_latestTimeByWhichCycleIsToBeReturned(t);
		}
		else
			update(user_id,cycle_id,location);
	}
	else
		update(user_id,cycle_id,location);
}

void add_cycle(int user_id)
{
	string owner = u[user_id].get_user_name();
	string location=u[user_id].get_hostelNo();
	cout<<"Enter latest time in hours by which the cycle is to be returned\n";
	int latestTimeByWhichCycleIsToBeReturned;
	cin >> latestTimeByWhichCycleIsToBeReturned;
	int k=0;
	for(int i=0;i<c.size();i++){
		if(c[i].get_cycle_id()==-1){
			u[user_id].set_cycleOwnedId(i);
			cycles newCycle(owner,i,location);
			newCycle.set_latestTimeByWhichCycleIsToBeReturned(latestTimeByWhichCycleIsToBeReturned);
			c[i]=newCycle;
			k=1;
			cout<<"Your cycle has been successfully add to the cycle rental portal. Your cycle ID is"<<i<<endl;
			break;
		}
	}
	if(k==0){
	int cycle_id=c.size();
	cycles newCycle(owner,cycle_id,location);
	newCycle.set_latestTimeByWhichCycleIsToBeReturned(latestTimeByWhichCycleIsToBeReturned);
	c.push_back(newCycle);
	u[user_id].set_cycleOwnedId(cycle_id);
	cout<<"Your cycle has been successfully add to the cycle rental portal. Your cycle ID is "<<cycle_id<<endl;
	}
}

void remove_cycle(int user_id)
{
	int cycleOwnedId=u[user_id].get_cycleOwnedId();
	c[cycleOwnedId].set_cycle_id(-1);
	u[user_id].set_cycleOwnedId(-1);
}

void donate_cycle(int user_id)
{
	int cycle_id=u[user_id].get_cycleOwnedId();
	c[cycle_id].set_owner("Shop");
	c[cycle_id].set_latestTimeByWhichCycleIsToBeReturned(24);
	u[user_id].set_cycleOwnedId(-1);
}

void updateTime(int user_id)
{
	cout<<"After how much time do you want your cycle back (No. of hours)\n";
	int n;
	cin>>n;
	c[u[user_id].get_cycleOwnedId()].set_latestTimeByWhichCycleIsToBeReturned(n);
}

void payment(int user_id) 
{
	int amount = u[user_id].get_amountDue() ;
	u[user_id].set_amountDue(0) ;

	if(u[user_id].get_isBlackListed())
	{
		u[user_id].set_isBlackListed(false) ;
		cout<<"Thank You for using our services.\nYour payment of "<<amount<<" has been received and you are not blacklisted anymore.\n";
	}
	cout<<"Thank You for using our services.\nYour payment of "<<amount<<" has been received.\n";

}

void signIn()
{
	int userid;
	string hostelNo,password;
	size_t passhash;
	while(1)
	{
		cout<<"Enter your User ID \n";
		userid = take_intInput() ;
		if(userid >= u.size()){
		
			cout<<"Invalid User ID! \nPlease sign up if not already signed up!\n";
			return;
		}
		else 
		{
			cout<<"Enter your password \n";

			password= inputPassword();
			hash <string> pass_hash;
			passhash = pass_hash(password);
			if(!u[userid].passwordCheck(passhash))
			{
				cout<<"Incorrect Password! Please try again\n";
				continue;
			}
			else
			{
				break;
			}
		}
	}
		cout<<"Enter your Hostel number \n";
		cin>>hostelNo;
		u[userid].set_user_hostelNo(hostelNo);
	while(1)
	{
		cout<<"1.Rent a cycle \n2.Return a cycle\n3.Add Cycle\n4.Remove Cycle\n5.Donate Cycle\n6.Update time\t(only for owners)\n7.Payment\n8.Sign Out\n";
		int option;
		cin>>option;
		if (option == 1)	//Rent
		{
			int num = rent_cycle(userid,hostelNo);
			if (num == -1)
				continue;
			else
				break;
		}
		else if (option == 2)	//Return
		{
			return_cycle(userid,hostelNo);
			break;
		}
		else if (option == 3)	//Add
		{
			if(u[userid].get_cycleOwnedId() != -1)
			{
				cout<<"You already have one cycle added! \nYou can donate this cycle to add the new one\n";
				continue;
			}
			else
			{
				add_cycle(userid);
				break;
			}
		}
		else if (option == 4)	//Remove
		{
			if(u[userid].get_cycleOwnedId() == -1)
			{
				cout<<"You don't have a cycle!\n";
				continue;
			}
			else
			{
				remove_cycle(userid);
				break;
			}
		}
		else if (option == 5)	//Donate
		{
			if(u[userid].get_cycleOwnedId() == -1)
			{
				cout<<"You don't have a cycle!\n";
				continue;
			}
			else
			{
				donate_cycle(userid);
				break;
			}
		}
		else if (option == 6)	//UpdateTime
		{
			if(u[userid].get_cycleOwnedId() == -1)
			{
				cout<<"You don't have a cycle!\n";
				continue;
			}
			else
			{
				updateTime(userid);
				break;
			}
		}
		else if (option == 7)	//Payment
		{
			payment(userid);
		}
		else if (option == 8)	//Sign Out
		{
			return;
		}
		else
			return;
	}
}
/*int int_input()
{
	int n;
	cin>>n;
	return n;
}
void get_user_input()
{
	int n = int_input();
	if (n == 1) 
		{
			signIn();
		}
		else if (n == 2) 
		{
			signUp();
		}
}*/
/*void homeScreen()
{
	cout<<"Welcome to Cycle Shop \n Select an option \n Enter 1 to Sign-In \n Enter 2 to Sign-Up\n";
	int n;
	cin>>n;
	if (n == 1) 
	{
		signIn();
	}
	else if (n == 2) 
	{
		signUp();
	}
}*/
int main()
{
	get_userData();
	get_cycleData();
	int n;
	cout<<"Welcome to Cycle Shop \n Select an option \n Enter 1 to Sign-In \n Enter 2 to Sign-Up\n";
	while(cin>>n)
	{
		
		
		//cin>>n;
		if (n == 1) 
		{
			signIn();
			set_userData(u);
			set_cycleData(c);
		}
		else if (n == 2) 
		{
			signUp();
			set_userData(u);
			set_cycleData(c);
		}
		//get_user_input();
		cout<<"Welcome to Cycle Shop \n Select an option \n Enter 1 to Sign-In \n Enter 2 to Sign-Up\n";
		int n;
	}
}
