#include "admin.h"
#include<conio.h>
#include<regex>
#include<fstream>
#include<string>
#include<queue>
/*
* admin::readdata() => read from donationrequest file (current date)
* user::readdata() => read from donor file 
*/
using namespace std;
bool admin::validatadmin()
{
	cout << "===============================================================" << endl;
	char choose;
	cout << "Enter admin's email : ";
	cin >> email;
	cout << "Enter admin's password : ";
	cin >> password;
	if (email == "admin@gmail.com" && password == "doniashrouk") {
		return true;
	}
	else {
		cout << "The mail or password is wrong\n";
		cout << "Do you want to try again ?\nEnter y for yes , Enter n for no";
		cin >> choose;
		if (!(choose == 'y'|| choose =='Y'))
			return false;
		else {
			return validatadmin();
		}
	}
}
void admin::Run() {
	bool flag = true;
	int ch;
	cout << "===============================================================" << endl;
	cout << "\t\t\t Welcome Admin " << endl;
	cout << "\t\t    =======================" << endl;

	while (flag)
	{
		cout << "1-Login\n2-exit\n";
		cin >> ch;
		switch (ch)
		{
		case 1:
			Login();
			break;
		case 2:
			flag = false;
			break;
		default:
			cout << "choose correct number";
			break;
		}
	}
	cout << "===============================================================" << endl;

}
void admin::deltefile(const char* s) {
	remove(s);
	fstream f;
	f.open(s, ios::app);
	f.close();
}
void admin::validatedrequest(queue<userdata>& acceptedqueue, queue<userdata>& waitingqueue) {
	fstream wait;
	wait.open("waiting.txt");
	if (!wait.is_open())
		cout << "cannot open waiting file\n";
	userdata d;
	if (wait.is_open())
	{
		while (wait.peek() != EOF)
		{
			admin::readdata(wait, d);
			waiting.push(d);
		}
	}
	wait.close();
	fstream req;
	req.open("DonationRequest.txt");
	if (req.is_open())
	{
		userdata d1;
		while (req.peek() != EOF)
		{
			admin::readdata(req, d1);
			Date dt1(d1.day, d1.month, d1.year);//last donation 
			Date dt2(d1.cday, d1.cmonth, d1.cyear);// request date
			if (stof(d1.age) > 17 && stof(d1.age) < 60 && dt2.diffbetwenndates(dt1) >= 90 && (d1.donorCase == "No" || d1.donorCase == "no"))
			{
				if (d1.donorCase1 == "yes" || d1.donorCase1 == "Yes")
				{
					waiting.push(d1);
				}
				else
				{
					accepted.push(d1);
				}
			}
		}
	}
	/*
	while (!waiting.empty())
	{
		wait << waiting.pop();

	}*/
	req.close();

}
void admin::show(queue<userdata>& q)
{
	while (!q.empty()) {
		cout << "===============================================================" << endl;
		cout << "Name : " << q.front().name << "\t" << "ID : " << q.front().id << "\t" << "diseas or midicine : " << q.front().diseaseName << "\n";
		cout << "press 1 to accepted this donor\npress 2 to reject this donor\npress 3 to back\n";
		int num;
		cin >> num;
		switch (num) {
		case 1:
			accepted.push(q.front());
			q.pop();
			break;
		case 2:
			q.pop();
			break;
		case 3:
			return;
		default:
			cout << "Enter avalide number \n";
		}
	}
	cout << "the requests is finished\n";
}
void admin::insertfile(queue<userdata>& d, string s)//s->name of file
{
	fstream f;
	f.open(s, ios::app);
	while (!d.empty())
	{
		writedata(f, d.front());
		d.pop();
	}
	f.close();
}
void admin::Login() {
	string id;
	
	bool flag2 = true;
	if(validatadmin()==true)
	{
		validatedrequest(accepted, waiting);
		while (flag2)
		{
			cout << "===============================================================" << endl;
			blood b;
			string bloodtype;
			cout << "1-validate requests\n2-Insert new donor\n3-Update donor\n4-Delete donor\n5-Display donors' information\n6-Insert new blood information\n7-Update blood informaion\n8-Delete blood information\n9-Insert new reipient\n10-Update recipient\n11-Delete recipient\n12-display recipients' information\n13-Logout\n";
			cin >> ch2;
			switch (ch2)
			{
			case 1:
				show(waiting);
				break;
			case 2:
				D.Register();
				break;
			case 3:
				cout << "Please enter donor's id : ";
				cin >> id;
				D.update(id);
				break;
			case 4:
				cout << "Please enter donor's id : ";
				cin >> id;
				D.Delete(id);
				break;
			case 5:
				DisplayDonor();
				break;
			case 6:
				b.InsertBlood();
				break;
			case 7:
				cout << "enter blood type to update\n";
				cin >> bloodtype;
				b.updateblood(bloodtype);
				break;
			case 8:
				cout << "enter blood type to delete\n";
				cin >> bloodtype;
				b.deleteblood(bloodtype);
				break;
			case 9:
				R.Register();
				break;
			case 10:
				cout << "Please enter Recipient's id : ";
				cin >> id;
				R.update(id);
				break;
			case 11:
				cout << "Please enter Recipient's id : ";
				cin >> id;
				R.Delete(id);
				break;
			case 12:
				DisplayRecipient();
				break;
			case 13:
				insertblood();
				insertfile(waiting, "waiting.txt");
				deltefile("DonationRequest.txt");
				flag2 = false;
				break;
			default:
				cout << "choose correct number\n";
				break;
			}
		}
	}
}
void admin::DisplayDonor() {
	vector<userdata> vect;
	userdata data1;
	fstream file("Donor.txt");
	while (file.peek() != EOF) {
		cout << "===============================================================" << endl;
		D.readdata(file, data1);
		if (data1.id == "")
			break;
		vect.push_back(data1);
		cout << "\t\t\tThe donor information\n";
		cout << "Name : " << vect.front().name << "\n";
		cout << "ID : " << vect.front().id << "\n";
		cout << "Age : " << vect.front().age << "\n";
		cout << " Dangerous diseases" << vect.front().donorCase << "\n";
		cout << " Other Disease /Take Midicine  " << vect.front().donorCase1 <<vect.front().diseaseName<< endl;
		cout << "The last donation date : " << vect.front().day << " / " << vect.front().month << " / " << vect.front().year << "\n";
		cout << "Blood type : " << vect.front().bloodType << "\n";
		cout << "Gender : " << vect.front().gender << "\n";
		cout << "Mail : " << vect.front().mail << "\n";
		cout << "Password : " << vect.front().password << "\n";
		cout << "enter any key to continue...\n";
		getch();
		vect.pop_back();
	}
	cout << "the donors is finished\n";
	file.close();
}
void admin::readdata(fstream& f, userdata& d)
{
	getline(f, d.id, '|');
	getline(f, d.name, '|');
	getline(f, d.mail, '|');
	getline(f, d.password, '|');
	getline(f, d.age, '|');
	getline(f, d.gender, '|');
	getline(f, d.bloodType, '|');
	getline(f, d.donorCase, '|');
	getline(f, d.donorCase1, '|');
	getline(f, d.diseaseName, '|');
	getline(f, d.day, '|');
	getline(f, d.month, '|');
	getline(f, d.year, '|');
	getline(f, d.cday, '|');
	getline(f, d.cmonth, '|');
	getline(f, d.cyear, '\n');
}
void admin::writedata(fstream& f, userdata& d) {
	f << d.id << '|' << d.name << '|' << d.mail << '|' << d.password << '|' << d.age << '|'
		<< d.gender << '|' << d.bloodType << '|' << d.donorCase << '|' << d.donorCase1 << '|' << d.diseaseName << '|' << d.day << '|'
		<< d.month << '|' << d.year << '|' << d.cday << '|' << d.cmonth << '|' << d.cyear << '\n';
}
void admin::DisplayRecipient() {
	cout << "===============================================================" << endl;
	vector<userdata> vect;
	userdata data1;
	fstream file("Recipient.txt");
	while (file.peek() != EOF) {
		R.readdata(file, data1);
		if (data1.name == "")
			break;
		vect.push_back(data1);
		cout << "\t\t\tThe Recipient information\n";
		cout << "Name : " << vect.front().name << "\n";
		cout << "ID : " << vect.front().id << "\n";
		cout << "Age : " << vect.front().age << "\n";
		cout << "Blood type : " << vect.front().bloodType << "\n";
		cout << "Gender : " << vect.front().gender << "\n";
		cout << "Mail : " << vect.front().mail << "\n";
		cout << "Password : " << vect.front().password << "\n";
		cout << "Hospital : " << vect.front().hospital << '\n';
		cout << "Doctor_of_case : " << vect.front().doctor_of_case << '\n';
		cout << "enter any key to continue...\n";
		getch();
		vect.pop_back();
	}
	cout << "the recipients is finished\n";
	file.close();
}
void admin::insertblood() {
	fstream blood;
	Date expireddate;
	Date d;
	fstream f;
	f.open("accepted.txt", ios::app);
	blood.open("blood.txt", ios::app);
	while (!accepted.empty())
	{
		writedata(f, accepted.front());
		Date receiveddate(accepted.front().cday, accepted.front().cmonth, accepted.front().cyear);
		expireddate = d.countexpirydate(receiveddate, 42);
		blood << accepted.front().bloodType << '|' << receiveddate.d << '|' << receiveddate.m << '|' << receiveddate.y << '|' << expireddate.d << '|' << expireddate.m << "," << expireddate.y << "," << "1" << '\n';
		accepted.pop();
	}
	f.close();
	blood.close();
}
admin::admin() {}
admin::~admin() {}