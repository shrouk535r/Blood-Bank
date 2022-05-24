#include "Date.h"
Date::Date(string day, string month, string year) {
	try
	{
		d = std::stoi(day);
		m = std::stoi(month);
		y = std::stoi(year);
	}
	catch (const std::exception& e)
	{
		cout << "int date\n";
	}
}
int Date::countleabyears()
{
	int years = y;
	if (m <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}
long long Date::diffbetwenndates(Date dt) {
	int monthdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	long long n1 = 0, n2 = 0;
	n1 += y * 365 + d + countleabyears();
	n2 += dt.y * 365 + dt.d + dt.countleabyears();
	for (int i = 0; i < 12; i++)
	{
		if (i + 1 < m)
			n1 += monthdays[i];
		if (i + 1 < dt.m)
			n2 += monthdays[i];
	}
	return n1 - n2;
}
bool Date::validate()
{
	if (d <= 31 && m <= 12 && y >= 1) {
		return true;
	}
	return false;
}
Date Date::countexpirydate(Date d , int n) {
	int months[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, sumofDays = 0, newdays, newmonth, newyear;
	Date date;
	for (i = 0; i < d.m; i++)
		sumofDays = sumofDays + months[i];
	sumofDays = sumofDays + d.d + n;
	newyear = sumofDays / 365;
	sumofDays = sumofDays % 365;
	 for (i = 0; i < 13; i++)
	 {
				newdays = sumofDays - months[i];
				if (newdays <= months[i + 1])
				{
					newmonth = i + 1;
					break;
				}
				else
					sumofDays = newdays;
	}
	 date.d = newdays;
	 date.m = newmonth;
	 date.y = newyear + d.y;
	 return date;
}