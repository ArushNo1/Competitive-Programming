/*
ID: 1026840
PROG: gift1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
int line = 1;
int main()
{
    ofstream outputFile ("gift1.out");
    ifstream inputFile ("gift1.in");

    int num_people;
    inputFile >> num_people;

    map<string, int> accounts;
    string names[num_people];

    for(int i = 0; i < num_people; i++){
        string x;
        inputFile >> x;
        line++;
        names[i] = x;
        accounts[x] = 0;
    }


    for(int i = 0; i < num_people; i++){
        string x;
        int amtMoney, amtRecievers;
        inputFile >> x;
        line++;
        inputFile >> amtMoney >> amtRecievers;
        line++;
        if(amtRecievers == 0 || amtMoney == 0){
            continue;
        }
        accounts[x] -= (amtMoney - (amtMoney % amtRecievers));
        amtMoney /= amtRecievers;
        for(int j = 0; j < amtRecievers; j++){
            inputFile >> x;
            line++;
            accounts[x] += amtMoney;
        }
    }
    for(unsigned short i = 0; i < num_people; i++){
        outputFile << names[i] << " " << accounts[names[i]] << endl;
    }

    return 0;
}
