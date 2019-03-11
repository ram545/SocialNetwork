#include "../Include/User.h"

idCounter=1;

User::User(string name,int age,bool gender,int height,vector<string> hobbies){
	this->name=name;
	this->age=age;
	this->gender=gender;
	this->height=height;
	this->id=generateId();
	this->hobbies=hobbies;
}

User::User(String name){
	this->name=name;
	this->id=generateId();
	this->age=0;
	this->height=0;
	this->gender=false;
	this->hobbies=null;
}

User::~User(){
	name=" ";
	age=0;
	gender=false;
	height=0;
	id=0;
	hobbies.clear();
}

User::User(User&& obj){

}

void User::addAge(int age){
	this->age=age;
}
		
void User::addGender(bool gender){
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

}