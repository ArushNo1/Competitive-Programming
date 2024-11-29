/*
ID: 1026840
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("   .in", "r", stdin);
    //freopen("promote.out", "w", stdout);

    int a = INT_MAX, b = INT_MAX, c = 0;
    int num[7];
    for(int i = 0; i < 7; i++){
        cin >> num[i];
        if(num[i] <= a){
            b = a;
            a = num[i];
        }
        else if(num[i] <= b){
            b = num[i];
        }
        if(num[i] >= c){
            c = num[i];
        }
    }
    cout << a << " " << b << " " << c - b - a << endl;

}
