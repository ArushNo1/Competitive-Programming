#include <iostream>
#include <fstream>
#include <string>
/*
ID: 1026840
PROG: friday
LANG: C++
*/
using namespace std;

int num_days(int num_years)
{
    return num_years * 365 + (num_years / 4 - num_years / 100 + num_years / 400);
}
int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int num_years;
    fin >> num_years;
    int days_left = num_days(num_years - 1) + 19;
    int current_year = 100;
    int thirteenths[] = {0, 0, 0, 0, 0, 0, 0};
    string names[] = {"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};
    int current_day = 0;

    while(days_left > 0)
    {
        //january
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << "current day: " << current_day << endl;
        //cout << names[current_day] << ", january " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //february
        if(current_year % 400 == 200 || (current_year % 4 == 0 && current_year % 100 != 0))
        {
            thirteenths[current_day]++;
            //cout << names[current_day] << ", february " << 1800 + current_year << endl;

            days_left -= 29;
            current_day = (current_day + 1) % 7;
        }
        else
        {
            days_left -= 28;
            thirteenths[current_day]++;
            //cout << names[current_day] << ", february " << 1800 + current_year << endl;

        }
        //march
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", march " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //april
        days_left -= 30;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", april " << 1800 + current_year << endl;
        current_day = (current_day + 2) % 7;
        //may
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", may " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //june
        days_left -= 30;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", june " << 1800 + current_year << endl;
        current_day = (current_day + 2) % 7;
        //july
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", july " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //august
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", august " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //september
        days_left -= 30;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", september " << 1800 + current_year << endl;
        current_day = (current_day + 2) % 7;
        //october
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", october " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        //november
        days_left -= 30;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", november " << 1800 + current_year << endl;
        current_day = (current_day + 2) % 7;
        //december
        days_left -= 31;
        thirteenths[current_day]++;
        //cout << names[current_day] << ", december " << 1800 + current_year << endl;
        current_day = (current_day + 3) % 7;
        current_year++;
    }
    for(int i = 0; i < 6; i++)
    {
        fout << thirteenths[i] << " ";
        //cout << thirteenths[i] << " ";
    }
    fout << thirteenths[6] << endl;
    //cout << thirteenths[6] << endl;
}
