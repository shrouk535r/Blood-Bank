#include<map>
#include<regex>
#include"recipient.h"
#include<fstream>
#include<string>
using namespace std;
// constractor 
recipient::recipient()
{
    userdata R;

    string day;
    string month;
    string year;
    string day1;
    string month1;
    string year1;
    string quantity;
    ifstream fout;
    fout.open("blood.txt");

    ofstream temp;
    temp.open("temp2.txt", ios::app);
    if (fout.is_open())
    {
        while (!fout.eof()) {
            getline(fout, R.bloodType, '|');
            if (R.bloodType == "")
                break;
            getline(fout, day, '|');
            getline(fout, month, '|');
            getline(fout, year, '|');
            getline(fout, day1, '|');
            getline(fout, month1, '|');
            getline(fout, year1, '|');
            getline(fout, quantity,'\n');
            Date Edt(day1, month1, year1);
            Date today;
            time_t now = time(0);
            struct tm nowlocal;
            nowlocal = *localtime(&now);
            today.d = nowlocal.tm_mday;
            today.m = nowlocal.tm_mon + 1;
            today.y = nowlocal.tm_year + 1900;
            if (Edt.diffbetwenndates(today) >=0)
            {
                temp << R.bloodType << '|' << day << '|' << month << '|' << year << '|' <<
                    day1 << '|' << month1 << '|' << year1 << '|' << quantity << '\n';
            }
        }
    }
    fout.close();
    temp.close();

    remove("blood.txt");
    rename("temp2.txt", "blood.txt");
}
void recipient::Run() {
    bool flag = true;
    cout << "===============================================================" << endl;
    cout << "\t\t\t Welcome Recipient " << endl;
    cout << "\t\t    =======================" << endl;
    while (flag)
    {
        userdata b;
       cout << "for register press 1" << endl;
        cout << "for login press 2" << endl;
        cout << "if you want to see all available blood type press 3 " << endl;
        cout << "for exit press4 " << endl;

        int n;
        cin >> n;
        if (n == 1) {
            Register();
        }
        else if (n == 2) {
            Login();
        }
        else if (n == 3) {
            display();
        }
        else if (n == 4) {
            cout << "thank you for visiting" << endl;
            flag = false;
        }
        else {
            cout << "invalid data";
        }
        cout << "===============================================================" << endl;

    }
}
void recipient::Login() {
    cout << "===============================================================" << endl;
    string id1, password1;
    cout << "enter your id" << endl;
    cin >> id1;
    cout << "enter your password" << endl;
    cin >> password1;
    fstream fout;
    fout.open("Recipient.txt");

    vector<userdata>v;
    userdata R;
    bool flag = false;
    if (fout.is_open())
    {
        while (!fout.eof()) {
            readdata(fout, R);
            v.push_back(R);

        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (id1 == v[i].id && password1 == v[i].password)
        {
            int n=0;
            do {
                cout << "welcom ";
                cout << v[i].name << endl;
                cout << v[i].doctor_of_case << endl;
                cout << v[i].bloodType << endl;
                cout << "for update press 1" << endl;
                cout << "for delete press 2" << endl;
                cout << "for request press 3" << endl;
                cout << "for logout press 4" << endl;

                cin >> n;
                if (n == 1) {
                    update(id1);
                    flag = true;
                }
                else if (n == 2)
                {
                    Delete(id1);
                    flag = true;
                }
                else if (n == 3) {
                    request(v[i].bloodType);
                    flag = true;
                }
                else if(n !=4)
                    cout << "enter right choose\n";

            } while (n != 4);
            fout.close();
        }
    }
    if (!flag)
    {
        char ch;
        cout << "the id or password is Wrong! \ndo you want try again?(y/n)";
        cin >> ch;
        while (!(ch == 'Y' || ch == 'y' || ch == 'n' || ch == 'N')) {
            cout << "invaild data enter(y/n)\n";
            cin >> ch;
        }
        if (ch == 'Y' || ch == 'y')
            Login();
        else {
            string decision;
            cout << "Do you want regist ? yes or no  " << endl;
            cin >> decision;
            while (!(decision == "yes" || decision == "Yes" || decision == "No" || decision == "no"))
            {
                cout << "enter right choose (yes/no)\n";
                cin >> decision;
            }
            if (decision == "yes" || decision == "Yes")
                Register();
        }
    }
}
void recipient::display() {
    cout << "===============================================================" << endl;
    userdata R;
    string day;
    string month;
    string year;
    string day1;
    string month1;
    string year1;
    string quantity;
    fstream fout;
    fout.open("blood.txt");
    if (fout.is_open())
    {
        while (fout.peek() != EOF) {
            getline(fout, R.bloodType, '|');
            getline(fout, day, '|');
            getline(fout, month, '|');
            getline(fout, year, '|');
            getline(fout, day1, '|');
            getline(fout, month1, '|');
            getline(fout, year1, '|');
            getline(fout, quantity);


            cout << R.bloodType << " " << " recieved date is " << " " << day << "/" << month << "/" << year << " expired date is " << day1 << "/" << month1 << "/" << year1 << " quantity " << quantity << endl;
        }
    }

    fout.close();
}
void recipient::request(string bloodf) {
    cout << "===============================================================" << endl;
    bool exist=false;
    userdata R;
    cout << "enter quantity" << endl;
    cin >> R.your_need;

    bool a = false;

    string day;
    string month;
    string year;
    string day1;
    string month1;
    string year1;
    string quantity;
    fstream fout;
    fout.open("blood.txt");
    if (fout.is_open())
    {
        while (!fout.eof()) {
            getline(fout, R.bloodType, '|');
            getline(fout, day, '|');
            getline(fout, month, '|');
            getline(fout, year, '|');
            getline(fout, day1, '|');
            getline(fout, month1, '|');
            getline(fout, year1, '|');
            getline(fout, quantity);
            int num = std::stoi(quantity);

            mp[R.bloodType] += num;


        }
    }
    fout.close();
    auto  it = mp.begin();
    for (; it != mp.end(); it++) {
        if (it->first == bloodf) {
            exist = true;
            if (it->first == bloodf && it->second < R.your_need) {
                cout << "sorry we have just " << it->second << " if you want them press 1" << endl;
                int n;
                cin >> n;
                if (n == 1) {
                    cout << "we will confirm about hospital " << endl;
                    update_bloood(R.your_blood, 0);
                }
                else {
                    cout << "sorry we can't help you";
                }

            }
            else if (it->first == bloodf && it->second >= R.your_need) {
                cout << "we will confirm about hospital " << endl;
                while (R.your_need != 0) {
                    R.your_need--;
                    it->second--;
                }
                update_bloood(R.your_blood, it->second);

            }
        }
    }
    if (!exist)
        cout << "sorry we 0 quantity from bloodtype" << bloodf << endl;
}
void recipient::update_bloood(string bloodtype, int rest)
{
    userdata R;

    string day;
    string month;
    string year;
    string day1;
    string month1;
    string year1;
    string quantity;
    ifstream fout;
    fout.open("blood.txt");

    ofstream temp;
    temp.open("temp.txt", ios::app);

    while (!fout.eof()) {
        getline(fout, R.bloodType, '|');
        if (R.bloodType == "")
            break;
        getline(fout, day, '|');
        getline(fout, month, '|');
        getline(fout, year, '|');
        getline(fout, day1, '|');
        getline(fout, month1, '|');
        getline(fout, year1, '|');
        getline(fout, quantity);
        int num = std::stoi(quantity);
        if (bloodtype == R.bloodType)
        {
            if (rest >= num)
            {
                temp << R.bloodType << '|' << day << '|' << month << '|' << year << '|' <<
                    day1 << '|' << month1 << '|' << year1 << '|' << num << '\n';
                rest = rest - num;
            }
            else
            {
                if (rest != 0)
                {
                    temp << R.bloodType << '|' << day << '|' << month << '|' << year << '|' <<
                        day1 << '|' << month1 << '|' << year1 << '|' << rest << '\n';
                    rest = 0;
                }
            }
        }
        else
        {
            temp << R.bloodType << '|' << day << '|' << month << '|' << year << '|' <<
                day1 << '|' << month1 << '|' << year1 << '|' << num << '\n';
        }

    }

    fout.close();
    temp.close();

    remove("blood.txt");
    rename("temp.txt", "blood.txt");

}
void recipient::readdata(fstream& f, userdata& d) {
    getline(f, d.id, '|');
    getline(f, d.name, '|');
    getline(f, d.mail, '|');
    getline(f, d.password, '|');
    getline(f, d.age, '|');
    getline(f, d.gender, '|');
    getline(f, d.bloodType, '|');
    getline(f, d.hospital, '|');
    getline(f, d.doctor_of_case, '\n');
}
void recipient::writedata(fstream& f, userdata& d) {
    f << d.id << '|' << d.name << '|' << d.mail << '|' << d.password << '|' << d.age << '|'
        << d.gender << '|' << d.bloodType << '|' << d.hospital << '|' << d.doctor_of_case<<'\n';
}
void recipient::Register() {
    cout << "===============================================================" << endl;
    userdata data1;
    userdata R;
    vector<userdata> v;
    fstream file;
    file.open("Recipient.txt");
    if (file.is_open()) {
        while (file.peek() != EOF) {
            readdata(file, data1);
            if (data1.id == "")
                break;
            v.push_back(data1);
        }
    }
    file.close();
    fstream write("Recipient.txt", ios::app);

    cout << "Enter  name : ";
    cin >> R.name;

    cout << "Enter id : ";
    cin >> R.id;


    while (true)
    {
        bool flag = false;

        for (int i = 0; i < v.size(); i++) {

            if (v[i].id == R.id)
                flag = true;


        }

        if (!flag)
        {
            break;
        }
        else {
            cout << "Enter an unique id :  ";
            cin >> R.id;
        }

    }

    cout << "Enter  age : ";
    cin >> R.age;

    cout << "enter  mail : ";
    cin >> R.mail;
    while (!isValidmail(R.mail))
    {
        cout << "please enter vaild data" << endl;
        cout << "mail : ";
        cin >> R.mail;
    }
    while (R.mail.empty())
    {
        cout << "please enter vaild data" << endl;
        cout << "Enter  mail : ";
        cin >> R.mail;
    }

    cout << "Enter  password : ";
    cin >> R.password;
    while (R.password.empty())
    {
        cout << "please enter vaild data : ";
        cin >> R.password;
    }

    cout << "Enter  gender : ";
    cin >> R.gender;
    while (!(R.gender == "female" || R.gender == "Female" || R.gender == "male" || R.gender == "Male"))
    {
        cout << "please enter valid data(female/male) : " << endl;
        cout << "Enter  gender : ";
        cin >> R.gender;
    }
    while (R.gender.empty())
    {
        cout << "please enter vaild data : ";
        cin >> R.gender;
    }

    cout << "Enter  blood type : ";
    cin >> R.bloodType;
    while (R.bloodType.empty())
    {
        cout << "Plesae enter valid data (+A,-A,+B,-B,+AB,-AB,+O,-O):" << endl;
        cout << "Enter  blood tybe : ";
        cin >> R.bloodType;
    }

    while (!(R.bloodType == "+A" || R.bloodType == "-A" || R.bloodType == "+B" || R.bloodType == "-B" || R.bloodType == "+O" || R.bloodType == "-O" || R.bloodType == "+AB" || R.bloodType == "-AB"))
    {
        cout << "Please enter vaild data (+A, -A, +B, -B, +O, -O, +AB, -AB)" << endl;
        cout << "Blood type : ";
        cin >> R.bloodType;
    }
    cout << "Enter hospital : ";
    cin >> R.hospital;
    while (R.hospital.empty())
    {
        cout << "please enter vaild data : ";
        cin >> R.hospital;
    }
    cout << "Enter  doctor_of_case : ";
    cin >> R.doctor_of_case;
    while (R.doctor_of_case.empty())
    {
        cout << "please enter vaild data : ";
        cin >> R.doctor_of_case;
    }
    writedata(write, R);
    write.close();
    cout << "\n\n\t\t Register is done successfully " << endl;
}
void recipient::update(string id)
{
    cout << "===============================================================" << endl;
    vector<userdata> vec;
    userdata R;
    fstream file("Recipient.txt");
    fstream temp("temp.txt", ios::app);
    while (file.peek() != EOF) {
        readdata(file, R);
        if (R.id == "")
            break;
        vec.push_back(R);
    }
    int x = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].id == id)
            x = i;
    }
    if (x != -1)
    {
        string choice;
        userdata d;
        cout << "===============================================================" << endl;
        cout << vec[x].name << "'s information\n";
        cout << "Do you want to update name ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"|| choice == "Y")
        {
            cout << "Enter a name : ";
            cin >> d.name;
        }
        else {
            d.name = vec[x].name;
        }

        cout << "Do you want to update  age ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"||choice == "Y") {
            cout << "Enter age : ";
            cin >> d.age;
        }
        else {
            d.age = vec[x].age;
        }

        cout << "Do you want to update  mail ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"||choice == "Y") {
            cout << "Enter  mail : ";
            cin >> d.mail;
            while (!isValidmail(d.mail))
            {
                cout << "please enter vaild data" << endl;
                cout << "mail : ";
                cin >> d.mail;
            }
            while (d.mail.empty())
            {
                cout << "please enter vaild data" << endl;
                cout << "Enter " << vec[x].name << "'s mail : ";
                cin >> d.mail;
            }
        }
        else {
            d.mail = vec[x].mail;
        }
        cout << "Do you want to update  password ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"||choice == "Y")
        {
            cout << "Enter a new password : ";
            cin >> d.password;
        }
        else {
            d.password = vec[x].password;
        }
        cout << "Do you want to update hospital ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"||choice == "y")
        {
            cout << "Enter a hospital name : ";
            cin >> d.hospital;
        }
        else {
            d.hospital = vec[x].hospital;
        }

        cout << "Do you want to update doctor_of_case ? \ny for yes\nn for no\n";
        cin >> choice;
        while (!(choice == "y" || choice == "Y" || choice == "n" || choice == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice;
        }
        if (choice == "y"||choice == "y")
        {
            cout << "Enter a name of doctor_of_case : ";
            cin >> d.doctor_of_case;
        }
        else {
            d.doctor_of_case = vec[x].doctor_of_case;
        }

        d.id = vec[x].id;
        d.gender = vec[x].gender;
        d.bloodType = vec[x].bloodType;

        for (int j = 0; j < vec.size(); j++)
        {

            if (vec[j].id == id)
            {
                writedata(temp, d);

            }
            else if (!(vec[j].id == id))
            {
                writedata(temp, vec[j]);

            }
        }
        file.close();
        temp.close();
        bool rem, rov;
        rov = remove("Recipient.txt");
        rem = rename("temp.txt", "Recipient.txt");
        if (rov == 0 && rem == 0)
            cout << "\n\t \tData is updated successfully  " << endl;
    }
    else
        cout << "sorry this id isn't exist\n";
}
void recipient::Delete(string id) {
    cout << "===============================================================" << endl;
    userdata p;
    vector<userdata> v;
    ifstream fout;
    fout.open("recipient.txt");

    ofstream temp;
    temp.open("temp.txt", ios::app);

    while (!fout.eof()) {
        getline(fout, p.id, '|');
        getline(fout, p.name, '|');
        getline(fout, p.mail, '|');
        getline(fout, p.password, '|');
        getline(fout, p.age, '|');
        getline(fout, p.gender, '|');
        getline(fout, p.bloodType, '|');
        getline(fout, p.hospital, '|');

        getline(fout, p.doctor_of_case);

        v.push_back(p);
    }

    bool flag = false;
    for (int i = 0; i < v.size(); i++) {
        if (id == v[i].id) {
            flag = true;
            cout << "deleted successfully" << endl;
            continue;
        }
        else
        {
            temp << v[i].id << '|' << v[i].name << '|' << v[i].mail << '|' << v[i].password << '|' << v[i].age << '|'
                << v[i].gender << '|' << v[i].bloodType << '|' << v[i].hospital << '|' << v[i].doctor_of_case << '\n';
            cin.ignore();
        }
    }
    if (!flag)
        cout << "this id isn't exist\n";


    fout.close();
    temp.close();

    remove("recipient.txt");
    rename("temp.txt", "blood.txt");
}