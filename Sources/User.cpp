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
	//if(this!=&obj){
		this->name=obj.name;
		this->age=obj.age;
		this->gender=obj.gender;
		this->height=obj.height;
		this->id=obj.id;
		this->hobbies=move(hobbies);
	//}
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

string User::getName(){
	return name;
}

int User::getAge(){
	return age;
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

vector<int> User::getFriend(){
	vector<int> frnds;
	typedef multimap<int,int>::iterator iterator;
	std::pair<iterator, iterator> iterpair = friends.equal_range(this->id);
	iterator it=iterpair.first;
	cout << "The Friends of ID : " << this->id << " are" << endl;
	for(;it!=iterpair.second;++it){
		frnds.push_back(it->second);
	}
	return frnds;
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
	string name,gender,hobby;
	int age,height,hobbNo;
	vector<string> hobbies;
	cout << "Enter your name: ";
	getline(cin,name);
	cout << "Enter your age: ";
	cin >> age;
	cin.ignore(250,'\n');
	cout << "Enter your gender(male/female): ";
	getline(cin,gender);
	cout << "Enter your height: ";
	cin >> height;
	cin.ignore(250,'\n');
	cout << "Enter the Number of Hobbies: ";
	cin >> hobbNo;
	cin.ignore(250,'\n');
	while(hobbNo--){
		getline(cin,hobby);
		hobbies.push_back(hobby);
	}
	User obj(name,age,gender,height,hobbies);
	obj.display();
	dict.insert(make_pair(obj.getId(),obj));
	namehash.insert(make_pair(obj.getName(),obj.getId()));
	agehash.insert(make_pair(obj.getAge(),obj.getId()));
	for(hobbNo=0;hobbNo<hobbies.size();hobbNo++){
		hobbhash.insert(make_pair(hobbies[hobbNo],obj.getId()));
	}
	return obj.getId();
}

void SocialNetwork::deleteUser(){
	int id,age,i;
	string name;
	vector<int> frnds;
	cout << "Enter the id: ";
	cin >> id;
	unordered_map<int,User>::iterator it;
	name=it->second.getName();
	age=it->second.getAge();
	frnds=it->second.getFriend();
	for(i=0;i<frnds.size();i++)
		it->second.deleteFriend(frnds[i]);
	dict.erase(it);
	typedef unordered_multimap<int,int>::iterator iterator1;
	std::pair<iterator1, iterator1> iterpair = agehash.equal_range(age);
	iterator1 it1=iterpair.first;
	for(;it1!=iterpair.second;++it1){
		if(it1->second==id)
			agehash.erase(it1);
	}
	typedef unordered_multimap<string,int>::iterator iterator2;
	std::pair<iterator2, iterator2> iterpair1 = namehash.equal_range(name);
	iterator2 it2=iterpair1.first;
	for(;it2!=iterpair1.second;++it2){
		if(it2->second==id)
			namehash.erase(it2);
	}
}



void SocialNetwork::displayData(){
	unordered_map<int,User>:: iterator it;
	for(it=dict.begin();it!=dict.end();++it){
		it->second.display();
	}
}

void SocialNetwork::addFriends(){
	int n,a,b,i;
	unordered_map<int,User>::iterator it;
	cout << "Enter the number of relations : ";
	cin >> n;
	cout << "Enter the relation: " << endl;
	for(i=0;i<n;i++){
		cin >> a >> b;
		it=dict.find(a);
		it->second.addFriend(b);
	}
}

void SocialNetwork::getFriendsOfUser(){
	int n,i;
	vector<int> frnds;
	cout << "Enter the Id: ";
	cin >> n;
	unordered_map<int,User>::iterator it;
	it=dict.find(n);
	frnds=it->second.getFriend();
	cout << "The friends of Id " << n << " are : ";
	for(i=0;i<frnds.size();i++)
		cout << frnds[i] << "  ";
	cout << endl;
}

void SocialNetwork::searchUserByName(){
	string name;
	cout << "Enter the name: ";
	cin >> name;
	typedef unordered_multimap<string,int>::iterator iterator;
	std::pair<iterator, iterator> iterpair = namehash.equal_range(name);
	iterator it=iterpair.first;
	unordered_map<int,User>::iterator it1;
	for(;it!=iterpair.second;++it){
		it1=dict.find(it->second);
		it1->second.display();
	}
}

void SocialNetwork::searchUserByAge(){
	int age;
	cout << "Enter the age: ";
	cin >> age;
	typedef unordered_multimap<int,int>::iterator iterator;
	std::pair<iterator, iterator> iterpair = agehash.equal_range(age);
	iterator it=iterpair.first;
	unordered_map<int,User>::iterator it1;
	for(;it!=iterpair.second;++it){
		it1=dict.find(it->second);
		it1->second.display();
	}
}


void SocialNetwork::searchUserByHobbies(){
	string hobb;
	int len,i;
	cout << "Enter the number of hobbies to search with: ";
	cin >> len;
	cin.ignore(250,'\n');
	for(i=0;i<len;i++){
		getline(cin,hobb);
	}
}