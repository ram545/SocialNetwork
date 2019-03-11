#include<iostream>
#include<map>
#include<iterator>
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
		static recordCounter=0;
	public:
		User(string name,int age,bool gender,int height,vector<string> hobbies);
		~User();
		bool addAge();
		bool addGender();
		bool addHeight();
		bool generateId();
		bool addHobbies();
		void display();
};
 
class SocialNetwork
{
public:
	void addUser(User obj);
	void deleteUser(/*fill in*/);
	//*fill in*/ searchUserByName(/*fill in*/);
	//*fill in*/ searchUserByAge(/*fill in*/);
	//*fill in*/ searchUserByHobbies(/*fill in*/);
	//*fill in*/ getFriendsOfUser(/*fill in*/);
	
private:
	std::unordered_map<int, person> &dict;
};