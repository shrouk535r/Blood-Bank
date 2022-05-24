#include "blood.h"
#include<map>
#include<vector>
#include<iostream>
using namespace std;
blood::blood() {}
void blood::InsertBlood() {
	cout << "===============================================================" << endl;
	blood b;
	fstream bloodfile("blood.txt", ios::app);
	cout << "Enter the blood type\n";
	cin >> b.type;
	cout << "enter recieved date\n";
	cin >> b.Rday >> b.Rmonth >> b.Ryear;
	Date vali(b.Rday, b.Rmonth, b.Ryear);
	while (vali.validate() != true)
	{
		cout << "Enter valid data :" << endl;
		cout << "Enter the recieved date : " << endl;
		cin >> b.Rday >> b.Rmonth >> b.Ryear;
		vali.d = stoi(b.Rday);
		vali.m = stoi(b.Rmonth);
		vali.y = stoi(b.Ryear);

	}
	cout << "enter expired date\n";
	cin >> b.Eday >> b.Emonth >> b.Eyear;
	Date vali2(b.Eday, b.Emonth, b.Eyear);
	while (vali2.validate() != true)
	{
		cout << "Enter valid data :" << endl;
		cout << "Enter the expired date : " << endl;
		cin >> b.Eday >> b.Emonth >> b.Eyear;
		vali2.d = stoi(b.Eday);
		vali2.m = stoi(b.Emonth);
		vali2.y = stoi(b.Eyear);

	}
	cout << "enter the quantity\n";
	cin >> b.quantity;
	bloodfile << b.type << '|' << b.Rday << '|' << b.Rmonth
		<< '|' << b.Ryear << '|' << b.Eday << '|' << b.Emonth << '|'
		<< b.Eyear << '|' << b.quantity << '\n';
}
void blood::updateblood(string btype) {
	cout << "===============================================================" << endl;
	vector<blood> v;
	blood b;
	ifstream bloodfile;
	bloodfile.open("Blood.txt");
	if (bloodfile.is_open()) {
		while (bloodfile.peek() != EOF) {
			getline(bloodfile, b.type, '|');
			getline(bloodfile, b.Rday, '|');
			getline(bloodfile, b.Rmonth, '|');
			getline(bloodfile, b.Ryear, '|');
			getline(bloodfile, b.Eday, '|');
			getline(bloodfile, b.Emonth, '|');
			getline(bloodfile, b.Eyear, '|');
			getline(bloodfile, b.quantity, '\n');
			v.push_back(b);
		}
	}
	bloodfile.close();
	ofstream write("temp.txt", ios::app);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].type == btype)
		{
			char ans = 'o';
			while (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y')
			{
				cout << "the blood type: " << v[i].type << "\nthe recieved date: " <<
					v[i].Rday << "/" << v[i].Rmonth << '/' << v[i].Ryear << "\nthe expired date: " <<
					v[i].Eday << '/' << v[i].Emonth << '/' << v[i].Eyear << "\n the quantity: " <<
					v[i].quantity << endl;
				cout << "do you want update this data (y/n)\n";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					string choice;
					cout << "Do you want to update the recieved date ? \ny for yes\nn for no\n";
					cin >> choice;
					while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
					{
						cout << "Enter valid data (y/n) : ";
						cin >> choice;
					}
					if (choice == "y" || choice == "Y")
					{
						cout << "Enter recieved date : ";
						cin >> v[i].Rday >> v[i].Rmonth >> v[i].Ryear;
						Date vali(v[i].Rday, v[i].Rmonth, v[i].Ryear);
						while (vali.validate() != true)
						{
							cout << "Enter valid data :" << endl;
							cout << "Enter the date of recieved date : " << endl;
							cin >> v[i].Rday >> v[i].Rmonth >> v[i].Ryear;
							vali.d = stoi(v[i].Rday);
							vali.m = stoi(v[i].Rmonth);
							vali.y = stoi(v[i].Ryear);

						}

					}
					cout << "Do you want to update the expired date ? \ny for yes\nn for no\n";
					cin >> choice;
					while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
					{
						cout << "Enter valid data (y/n) : ";
						cin >> choice;
					}
					if (choice == "y" || choice == "Y")
					{
						cout << "Enter expired date : ";
						cin >> v[i].Eday >> v[i].Emonth >> v[i].Eyear;
						Date vali(v[i].Eday, v[i].Emonth, v[i].Eyear);
						while (vali.validate() != true)
						{
							cout << "Enter valid data :" << endl;
							cout << "Enter the date of expired date: " << endl;
							cin >> v[i].Eday >> v[i].Emonth >> v[i].Eyear;
							vali.d = stoi(v[i].Eday);
							vali.m = stoi(v[i].Emonth);
							vali.y = stoi(v[i].Eyear);

						}

					}
					cout << "Do you want to update the quantity ? \ny for yes\nn for no\n";
					cin >> choice;
					while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
					{
						cout << "Enter valid data (y/n) : ";
						cin >> choice;
					}
					if (choice == "y" || choice == "Y")
					{
						cout << "Enter the quantity : ";
						cin >> v[i].quantity;
					}
				}
				else if (ans == 'N' || ans == 'n')
				{
					continue;
				}
				else
					cout << "enter vaild choose y or n\n";
			}
		}
		write << v[i].type << '|' << v[i].Rday << '|' << v[i].Rmonth
			<< '|' << v[i].Ryear << '|' << v[i].Eday << '|' << v[i].Emonth << '|'
			<< v[i].Eyear << '|' << v[i].quantity << '\n';
	}
	write.close();
	int rov = remove("blood.txt");
	int rem = rename("temp.txt", "blood.txt");
	if (rov == 0 && rem == 0)
		cout << "the blood type " << btype << "is update sucessfully\n";
}
void blood::deleteblood(string btype) {
	cout << "===============================================================" << endl;
	vector<blood> v;
	blood b;
	ifstream bloodfile;
	bloodfile.open("Blood.txt");
	if (bloodfile.is_open()) {
		while (bloodfile.peek() != EOF) {
			getline(bloodfile, b.type, '|');
			getline(bloodfile, b.Rday, '|');
			getline(bloodfile, b.Rmonth, '|');
			getline(bloodfile, b.Ryear, '|');
			getline(bloodfile, b.Eday, '|');
			getline(bloodfile, b.Emonth, '|');
			getline(bloodfile, b.Eyear, '|');
			getline(bloodfile, b.quantity, '\n');
			v.push_back(b);
		}
	}
	bloodfile.close();
	ofstream write("temp.txt", ios::app);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].type == btype)
		{
			char ans = 'o';
			while (ans != 'n' && ans != 'N' && ans != 'y' && ans != 'Y')
			{
				cout << "the blood type: " << v[i].type << "\nthe recieved date: " <<
					v[i].Rday << "/" << v[i].Rmonth << '/' << v[i].Ryear << "\nthe expired date: " <<
					v[i].Eday << '/' << v[i].Emonth << '/' << v[i].Eyear << "\n the quantity: " <<
					v[i].quantity << endl;
				cout << "do you want delete this data (y/n)\n";
				cin >> ans;
				if (ans == 'Y' || ans == 'y')
				{
					continue;
				}
				else if (ans == 'N' || ans == 'n')
				{
					write << v[i].type << '|' << v[i].Rday << '|' << v[i].Rmonth
						<< '|' << v[i].Ryear << '|' << v[i].Eday << '|' << v[i].Emonth << '|'
						<< v[i].Eyear << '|' << v[i].quantity << '\n';
				}
				else
					cout << "enter vaild choose y or n\n";
			}
		}
		else {
			write << v[i].type << '|' << v[i].Rday << '|' << v[i].Rmonth
				<< '|' << v[i].Ryear << '|' << v[i].Eday << '|' << v[i].Emonth << '|'
				<< v[i].Eyear << '|' << v[i].quantity << '\n';
		}
	}
	write.close();
	int rov = remove("blood.txt");
	int rem = rename("temp.txt", "blood.txt");
	if (rov == 0 && rem == 0)
		cout << "the blood type " << btype << "is delete sucessfully\n";
}