#include "fraction2.h"
#include <iostream>
#include <string>

using namespace std;


int main(){
	fraction f (2, 3);
	fraction s (4, 5); 
	fraction r = f+s;
	cout << r << endl;
	string n;
	n = s.toString();
	cout << n << endl;

	double x = f;
	cout << x << endl;
	cin >> f;
	if (f>=s){
		cout << "f is greater" << endl;
	}
	if (f<=s){
		cout << "f is lesser" << endl;
	}
	if (f==s){
		cout << "they are equal" << endl;
	}

	
	return 0;
}
