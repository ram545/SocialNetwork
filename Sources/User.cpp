#include "../Include/User.h"


int User::idCounter=1;
multimap<int,int> User::friends;

User::User(string name,int age,string gender,int height,vector<string> hobbies){
	this->name=name;
	this->age=age;
	this->gender=gender;
	this->height=height;
	this->id=generateId();
	this->hobbies=hobbies;
}

User::User(string name){
	this->name=name;
	this->id=generateId();
	this->age=0;
	this->height=0;
	this->gender="";
	hobbies.clear();
}

User::~User(){
	name="";
	age=0;
	gender="";
	height=0;
	id=0;
	hobbies.clear();
}

User::User(const User& obj){
	if(this!=&obj){
		this->name=obj.name;
		this->age=obj.age;
		this->gender=obj.gender;
		this->height=obj.height;
		this->id=obj.id;
		this->hobbies=move(hobbies);
	}
}

/*
User& operator=(User&& obj){
	delete this;
	if(this!=&obj){
		this=move(obj);
	}
	return this;
}
*/

int User::getId(){
	return id;
}

void User::addAge(int age){
	this->age=age;
}
		
void User::addGender(string gender){
	this->gender=gender;
}

void User::addHeight(int height){
	this->height=height;
}
		
int User::generateId(){
	return idCounter++;
}

void User::addHobbies(vector<string> hobbies){
	int i;
	for(i=0;i<hobbies.size();i++){
		this->hobbies.push_back(hobbies[i]);
	}
}
		
void User::display(){
	cout << "Name                 : " << this->name << endl;
	if(this->age>0)
		cout << "Age                  : " << this->age << endl;
	if(this->gender.length()>0)
		cout << "Gender               : " << this->gender << endl;
	if(this->height>0)
		cout << "Height               : " << this->height << "cm" << endl;
	cout << "Id                   : " << this->id << endl;
	if(this->hobbies.size()>0){
		cout << "Hobbies              : " ;
		for(int i=0;i!=this->hobbies.size();i++)
			cout << this->hobbies[i] << " ";
		cout << endl;
	}
}


void User::addFriend(int id){
	friends.insert(make_pair(this->id,id));
	friends.insert(make_pair(id,this->id));
}

void User::getFriend(){
	typedef multimap<int,int>::iterator iterator;
	std::pair<iterator, iterator> iterpair = friends.equal_range(this->id);
	iterator it=iterpair.first;
	cout << "The Friends of ID : " << this->id << " are" << endl;
	for(;it!=iterpair.second;++it){
		cout << it->second << "   ";
	}
	cout << endl;
}

void User::deleteFriend(int id){
	typedef multimap<int,int>::iterator iterator;
	std::pair<iterator, iterator> iterpair = friends.equal_range(id);
	iterator it=iterpair.first;
	for(;it!=iterpair.second;++it){
		if(it->second==this->id){
			friends.erase(it);
			break;
		}
	}
	iterpair = friends.equal_range(this->id);
	it=iterpair.first;
	for(;it!=iterpair.second;++it){
		if(it->second==id){
			friends.erase(it);
			break;
		}
	}	
}

int SocialNetwork::addUser(){
	vector<string> hobbies={"skippin","trippin"};
	User obj("Pokran",12,"male",140,hobbies);
	obj.display();
	dict.insert(make_pair(obj.getId(),obj));
	return obj.getId();
}

