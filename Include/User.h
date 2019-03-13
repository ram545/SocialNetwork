#include<iostream>
#include<unordered_map>
#include<map>
#include<iterator>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;

class User
{
	private:
		string name;
		int age;
		string gender;
		int height;
		int id;
		vector<string> hobbies;
		static int idCounter;
		static multimap<int,int> friends;
	public:
		User(string name,int age,string gender,int height,vector<string> hobbies);
		User(string name);
		~User();
		User(const User& obj);
		void addAge(int age);
		void addGender(string gender);
		void addHeight(int height);
		int generateId();
		int getId();
		string getName();
		int getAge();
		void addHobbies(vector<string> hobbies);
		void display();
		void addFriend(int id);
		void getFriend();
		void deleteFriend(int id);
};
 
class SocialNetwork
{
public:
	int addUser();
	void deleteUser(int id);
	void displayData();
	void addFriends();
	void getFriendsOfUser();
	void searchUserByName();
	void searchUserByAge();
	void searchUserByHobbies();
	
private:
	unordered_multimap<int,int> agehash;
	unordered_multimap<string,int> namehash;
	unordered_map<int, User> dict;
};