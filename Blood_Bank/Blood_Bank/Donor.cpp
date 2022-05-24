#include"Donor.h"
void Donor::DonationRequest(fstream& DonorReq, vector<userdata>& vec, int& i) {

    cout << "===============================================================" << endl;
    time_t now = time(0);
    struct tm nowlocal;
    nowlocal = *localtime(&now);
    if (DonorReq.is_open())
    {
        
        DonorReq << vec[i].id << '|' << vec[i].name << '|' << vec[i].mail << '|' << vec[i].password << '|' << vec[i].age << '|'
            << vec[i].gender << '|' << vec[i].bloodType << '|' << vec[i].donorCase << '|' << vec[i].donorCase1 << '|' << vec[i].diseaseName << '|' << vec[i].day << '|'
            << vec[i].month << '|' << vec[i].year << '|' << nowlocal.tm_mday << '|' << nowlocal.tm_mon + 1 << '|' << nowlocal.tm_year + 1900 << '\n';
        DonorReq.close();
        cout << "\n\t\tRequest is sent successfuly  " << endl;
    }
}
void Donor::Login() 
{
    string password, choice, decision, id;
    vector<userdata> vec;
    userdata data1;
    fstream file("Donor.txt");
    fstream   DonoReq;
    int input;
    cout << "===============================================================" << endl;

    cout << "Enter id : ";
    cin >> id;
    cout << "Enter password : ";
    cin >> password;

    bool flag = false;

    while (file.peek() != EOF) {
        readdata(file, data1);
        if (data1.name == "")
            break;
        vec.push_back(data1);
    }
    file.close();
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].id == id && vec[i].password == password)
        {
            DonoReq.open("DonationRequest.txt", ios::app);
            flag = true;
            cout << "===============================================================" << endl;

            cout << "\t\t\tWelcome " << vec[i].name << endl;
            cout << "===============================================================" << endl;
            cout << "1-Update data" << endl;
            cout << "2-Delete Acount " << endl;
            cout << "3-Donation Request " << endl;
            cout << "4-log out " << endl;
            cout << "Enter your choice :";
            cin >> input;

            do
            {
                switch (input)
                {
                case 1:
                {
                    update(id);
                    break;

                }
                case 2:
                {
                    Delete(id);
                    break;
                }
                case 3:
                {
                    DonationRequest(DonoReq, vec, i);
                    break;
                }


                }

                cout << "===============================================================" << endl;
                cout << "Do yo want to logout ? \n y for yes \n n for no" << endl;
                char answ;
                cin >> answ;

                if (answ == 'n' || answ == 'N')
                {

                    cout << "===============================================================" << endl;
                    cout << "1-Update data" << endl;
                    cout << "2-Delete Acount " << endl;
                    cout << "3-Donation Request " << endl;
                    cout << "4-log out " << endl;
                    cout << "Enter your choice :";
                    cin >> input;
                }
                else {
                    input = 4;
                }

            } while (!(input == 4));


        }
    }

    if (!flag)
    {
        cout << "there is no one that name  " << endl;
        cout << "Do you want regist ? yes or no  " << endl;
        cin >> decision;
        while (!(decision == "yes" || decision == "Yes" || decision == "No" || decision == "no"))
        {
            cout << "enter right choose (yes/no)\n";
            cin >> decision;
        }
        if (decision == "yes" || decision == "Yes")
            Register();

        else if (decision == "no" || decision == "No")
        {
            cout << "Do you want to go to login page ?" << endl;
            cin >> decision;
             while (!(decision == "yes" || decision == "Yes" || decision == "No" || decision == "no"))
        {
            cout << "enter right choose (yes/no)\n";
            cin >> decision;
        }
            if (decision == "yes" || decision == "Yes")
                Login();

        }
    }

    file.close();

}
void Donor::Run() {
    int input, num;
   cout << "===============================================================" << endl;
    cout << "\t\t\t Welcome Donor " << endl;
    cout << "\t\t    =======================" << endl;

    do {
        cout << "1-Regist data " << endl;
        cout << "2-Login" << endl;
        cout << "3-Exit" << endl;
        cout << "Choose an option : ";
        cin >> input;


        switch (input)
        {
        case 1:
        {
            Register();
            break;
        }
        case 2:
        {

            Login();
            break;
        }


        }
           cout << "===============================================================" << endl;

    } while (!(input == 3));
    if (input == 3)
    {
        cout << "\n\t\t\t Thank You " << endl;
    }
}
void Donor::readdata(fstream& f, userdata& d) {
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
    getline(f, d.year, '\n');
}
void Donor::writedata(fstream& f, userdata& d) {
    f << d.id << '|' << d.name << '|' << d.mail << '|' << d.password << '|' << d.age << '|'
        << d.gender << '|' << d.bloodType << '|' << d.donorCase << '|' << d.donorCase1 << '|' << d.diseaseName << '|' << d.day << '|'
        << d.month << '|' << d.year<<'\n';
}
void Donor::Register() {
    userdata data1;
    userdata d;
    vector<userdata> v;
    cout << "===============================================================" << endl;
    fstream file;
    file.open("Donor.txt");
    if (file.is_open()) {
        while (file.peek() != EOF) {
            readdata(file, data1);
            if (data1.id == "")
                break;
            v.push_back(data1);
        }
    }
    fstream write("Donor.txt", ios::app);

    cout << "Enter Donor's name : ";
    cin >> d.name;

    cout << "Enter Donor's id : ";
    cin >> d.id;


    while (true)
    {
        bool flag = false;

        for (int i = 0; i < v.size(); i++) {

            if (v[i].id == d.id)
                flag = true;


        }

        if (!flag)
        {
            break;
        }
        else {
            cout << "Enter an unique id :  ";
            cin >> d.id;
        }

    }

    cout << "Enter donor's age : ";
    cin >> d.age;


    cout << "Does the donor have any disease from this (blood pressure disorders,thyroid disease,diabetes,cancer,heart disorders,hepatitis ? \n";
    cin >> d.donorCase;
    while (!(d.donorCase == "yes" || d.donorCase == "Yes" || d.donorCase == "no" || d.donorCase == "No"))
    {
        cout << "Enter valid data : ";
        cin >> d.donorCase;
    }
    cout << "Does the donor have any disease not from above list Or take a medicine?\n";
    cin >> d.donorCase1;
    while (!(d.donorCase1 == "yes" || d.donorCase1 == "Yes" || d.donorCase1 == "no" || d.donorCase1 == "No"))
    {
        cout << "Enter valid data : ";
        cin >> d.donorCase1;
    }
    if (d.donorCase1 == "yes" || d.donorCase1 == "Yes")
    {
        cout << "Enter disease name : ";
        cin >> d.diseaseName;
    }
    else
        d.diseaseName = "none";

    cout << "Enter the date of latest donation : " << endl;

    cin >> d.day >> d.month >> d.year;
    Date vali(d.day, d.month, d.year);
    while (vali.validate() != true)
    {
        cout << "Enter valid data :" << endl;
        cout << "Enter the date of latest donation : " << endl;
        cin >> d.day >> d.month >> d.year;
        vali.d = stoi(d.day);
        vali.m = stoi(d.month);
        vali.y = stoi(d.year);

    }

    cout << "enter donor's mail : ";
    cin >> d.mail;
    while (!isValidmail(d.mail))
    {
        cout << "please enter vaild data" << endl;
        cout << "mail : ";
        cin >> d.mail;
    }


    cout << "Enter donor's password : ";
    cin >> d.password;
    while (d.password.empty())
    {
        cout << "please enter vaild data : ";
        cin >> d.password;
    }

    cout << "Enter donor's gender : ";
    cin >> d.gender;
    while (!(d.gender == "female" || d.gender == "Female" || d.gender == "male" || d.gender == "Male"))
    {
        cout << "please enter valid data : " << endl;
        cout << "Enter donor's gender : ";
        cin >> d.gender;
    }
    while (d.gender.empty())
    {
        cout << "please enter vaild data : ";
        cin >> d.gender;
    }

    cout << "Enter donor's blood type : ";
    cin >> d.bloodType;
    while (d.bloodType.empty())
    {
        cout << "Plesae enter valid data :" << endl;
        cout << "Enter donor's blood tybe : ";
        cin >> d.bloodType;
    }

    while (!(d.bloodType == "+A" || d.bloodType == "-A" || d.bloodType == "+B" || d.bloodType == "-B" || d.bloodType == "+O" || d.bloodType == "-O" || d.bloodType == "+AB" || d.bloodType == "-AB"))
    {
        cout << "Please enter vaild data (+A, -A, +B, -B, +O, -O, +AB, -AB)" << endl;
        cout << "Blood type : ";
        cin >> d.bloodType;
    }

    writedata(write, d);
    write.close();
    file.close();
    cout << "\n\n\t\t Regist is done successfully " << endl;

}
void Donor::update(string id) {
    vector<userdata> vec;
    userdata data1;
    fstream file("Donor.txt");
    fstream temp("temp.txt", ios::app);
    while (file.peek() != EOF) {
        readdata(file, data1);
        if (data1.id == "")
            break;
        vec.push_back(data1);
    }
    int x = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].id == id)
            x = i;
    }
    if (x != -1)
    {
        string choice1;
        userdata d;
        cout << "===============================================================" << endl;

        cout << "Do you want to update name ? \ny for yes\nn for no\n";
        cin >> choice1;
        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice1;
        }
        if (choice1 == "y" || choice1 == "Y")
        {
            cout << "Enter a name : ";
            cin >> d.name;
        }
        else {
            d.name = vec[x].name;
        }

        cout << "Do you want to update " << vec[x].name << "'s age ? \ny for yes\nn for no\n";
        cin >> choice1;
        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {

            cout << "Enter valid data (y/n) : ";
            cin >> choice1;

        }
        if (choice1 == "y" || choice1 == "Y") {
            cout << "Enter age : ";
            cin >> d.age;
        }
        else {
            d.age = vec[x].age;
        }
        cout << "Do you want to update " << vec[x].name << "'s donorcase ? \ny for yes\nn for no\n";
        cin >> choice1;
        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {

            cout << "Enter valid data (y/n) : ";
            cin >> choice1;

        }
        if (choice1 == "y" || choice1 == "Y") {
            cout << "Does " << vec[x].name << " have any disease from this (blood pressure disorders,thyroid disease,diabetes,cancer,heart disorders,hepatitis ? " << endl;
            cin >> d.donorCase;
            while (!(d.donorCase == "yes" || d.donorCase == "Yes" || d.donorCase == "no" || d.donorCase == "No"))
            {
                cout << "Enter valid data : ";
                cin >> d.donorCase;
            }
            cout << "Does the donor have any disease not from above list Or take a medicine?" << endl;
            cin >> d.donorCase1;
            while (!(d.donorCase1 == "yes" || d.donorCase1 == "Yes" || d.donorCase1 == "no" || d.donorCase1 == "No"))
            {
                cout << "Enter valid data : ";
                cin >> d.donorCase1;
            }
            if (d.donorCase1 == "yes" || d.donorCase1 == "Yes")
            {
                cout << "Enter disease name : ";
                cin >> d.diseaseName;
            }
            else
                d.diseaseName = "none";
        }
        else {
            d.donorCase = vec[x].donorCase;

            d.donorCase1 = vec[x].donorCase1;

        }
        cout << "Do you want to update donor's date of latest donation ? \ny for yes\nn for no\n";
        cin >> choice1;

        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice1;
        }

        if (choice1 == "y" || choice1 == "Y")
        {
            cout << "Date the latest donation : " << endl;

            cin >> d.day;

            cin >> d.month;

            cin >> d.year;
            Date vali(d.day, d.month, d.year);
            while (vali.validate() != true)
            {
                cout << "Enter valid data :" << endl;
                cout << "Enter the date of latest donation : " << endl;
                cin >> d.day >> d.month >> d.year;
                vali.d = stoi(d.day);
                vali.m = stoi(d.month);
                vali.y = stoi(d.year);

            }

        }
        else {
            d.day = vec[x].day;
            d.month = vec[x].month;
            d.year = vec[x].year;

        }
        cout << "Do you want to update " << vec[x].name << "'s mail ? \ny for yes\nn for no\n";
        cin >> choice1;

        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice1;
        }

        if (choice1 == "y" || choice1 == "Y") {
            cout << "Enter " << vec[x].name << "'s mail : ";
            cin >> d.mail;
            while (!isValidmail(d.mail))
            {
                cout << "please enter vaild data" << endl;
                cout << "mail : ";
                cin >> d.mail;
            }

        }
        else {
            d.mail = vec[x].mail;
        }
        cout << "Do you want to update " << vec[x].name << "'s password ? \ny for yes\nn for no\n";
        cin >> choice1;

        while (!(choice1 == "y" || choice1 == "Y" || choice1 == "n" || choice1 == "N"))
        {
            cout << "Enter valid data (y/n) : ";
            cin >> choice1;
        }

        if (choice1 == "y" || choice1 == "Y")
        {
            cout << "Enter a new password : ";
            cin >> d.password;
        }
        else {
            d.password = vec[x].password;
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
        rov = remove("Donor.txt");
        rem = rename("temp.txt", "Donor.txt");
        if (rov == 0 && rem == 0)
            cout << "\n\t \tData is updated successfully  " << endl;
    }
    else
        cout << "sorry this id isn't exist\n";
}
void Donor::Delete(string id)
{
    bool exist = false;
    vector<userdata> vect;
    userdata data1;
    fstream file("Donor.txt");
    fstream temp("temp.txt", ios::app);
    while (file.peek() != EOF) {
        readdata(file, data1);
        if (data1.id == "")
            break;
        vect.push_back(data1);
    }

    cout << "===============================================================" << endl;



    for (int j = 0; j < vect.size(); j++)
    {
        if (!(id == vect[j].id))
        {
            writedata(temp, vect[j]);

        }
        else {
            exist = true;
            continue;

        }

    }
    file.close();
    temp.close();
    bool rem, rov;
    rov = remove("Donor.txt");
    rem = rename("temp.txt", "Donor.txt");
    if (rov == 0 && rem == 0)
    {
        if (exist)
            cout << "\n\t \tThe donor's Account is deleted successfuly  " << endl;
        else
            cout << "sorry this id isn't exist\n";
    }
}
Donor::Donor() {}