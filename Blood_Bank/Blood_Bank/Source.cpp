#include <iostream>
#include<regex>
#include<fstream>
#include<string>
#include<queue>
#include"Date.h"
#include"admin.h"
#include"recipient.h"
#include"donor.h"
using namespace std;
int main()
{
	bool f = true;
	Donor d;
	admin a;
	recipient r;
	int n;
	cout << "\n\n";
	cout << "\t\t\t Welcome To Blood Bank " << endl;
	while (f) {
		cout << "===============================================================" << endl;
		cout << "1-Donor\n2-Recipient\n3-Admin\n4-exit\n";
		cin >> n;
		switch (n) {
		case 1:
			d.Run();
			break;
		case 2:
			r.Run();
			break;
		case 3:
			a.Run();
			break;
		case 4:
			f = false;
			break;
		default:
			cout << "Enter a valid number";
			break;
		}
	}
}