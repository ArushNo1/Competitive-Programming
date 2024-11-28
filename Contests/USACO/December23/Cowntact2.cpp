#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{


    int num_cows;
    string s;
    vector<int> stringLengths;
    cin >> num_cows >> s;
    int minStringLength = num_cows + 1;

    int counter = 0;
    char c;
    for(int i = 0; i < num_cows; i++){
        c = s[i];
        if(c == '1'){
            counter++;
        }
        else if(counter > 0){
            stringLengths.push_back(counter);
            if(counter < minStringLength){
                minStringLength = counter;
            }
            counter = 0;
        }
    }
    if(counter > 0){
        stringLengths.push_back(counter);
        if(counter < minStringLength){
            minStringLength = counter;
        }
        counter = 0;
    }

    for(int i = 0; i < stringLengths.size(); i++){
        counter += ceil((float)stringLengths[i] / minStringLength);
    }

    cout << counter;

    return 0;
}
