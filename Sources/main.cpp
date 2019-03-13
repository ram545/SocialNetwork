#include "../Include/User.h"

int showMenu();

int main(){
	int choice,id;
	SocialNetwork Users;
	vector<int> dataId;
	do{
		choice=showMenu();
		switch(choice){
			case 1 : id=Users.addUser(); 
					 cout << "Your account has been created and Id is " << id << endl;
					 dataId.push_back(id);
					 break;
			case 2 : Users.displayData();
					 break;
			case 3 : if(dataId.size()<=1)
						cout << "Add Users to continue" << endl;
					 else{
						cout << "The users available are: " << endl;
						for(int i=0;i<dataId.size();i++)
							cout << dataId[i] << "   ";
						cout << endl;
						Users.addFriends();
					 }
					 break;
			case 4 : Users.getFriendsOfUser();
					 break;
			case 5 : Users.searchUserByName();
					 break;
			case 6 : Users.searchUserByAge();
					 break;
			case 7 : Users.searchUserByHobbies();
					 break;
			default: cout << "Code Successfully executed" << endl;
		};
	}while(choice!=8);
	return 0;
}

int showMenu()
{
	int choice;
	cout << "\n<< Social Network >>" << endl;
	cout << "1) Add User" << endl;
	cout << "2) Delete User" << endl;
	cout << "3) Add Friends" << endl;
	cout << "4) Get Friends Of Users" << endl;
	cout << "5) Search User By Name" << endl;
	cout << "6) Search User By Age" << endl;
	cout << "7) Search User By Hobbies" << endl;
	cout << "8) Exit" << endl;
	cout << "Please Enter your choice" << endl;
	cin >> choice;
	cin.ignore(250,'\n');
	if(choice >= 1 && choice <= 8)
		return choice;
	else{
		cout << "Choose a value between 1 and 8" << endl;
		return showMenu();
	}
}