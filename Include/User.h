#include<iostream>
#include<unordered_map>
#include<iterator>
#include<vector>
#include<cstring>
using namespace std;

class User
{
	private:
		string name;
		int age;
		bool gender;
		int height;
		int id;
		vector<string> hobbies;
	public:
		static int idCounter;
		User(string name,int age=0,bool gender=false,int height=0,vector<string> hobbies);
		User(string name);
		~User();
		User(User&& obj);
		void addAge(int age);
		void addGender(bool gender);
		void addHeight(int height);
		int generateId();
		void addHobbies(vector<string> hobbies);
		void display();
};
 
class SocialNetwork
{
public:
	void addUser(User obj);
	void deleteUser(int id);
	//*fill in*/ searchUserByName(/*fill in*/);
	//*fill in*/ searchUserByAge(/*fill in*/);
	//*fill in*/ searchUserByHobbies(/*fill in*/);
	//*fill in*/ getFriendsOfUser(/*fill in*/);
	
private:
	unordered_map<int, User> &dict;
};