#include "../Include/User.h"

int main(){
	int a[3];
	SocialNetwork Users;
	a[0]=Users.addUser();
	a[1]=Users.addUser();
	a[2]=Users.addUser();
	cout << a[0] << " " << a[1] << " " << a[2] << endl;
	return 0;
}