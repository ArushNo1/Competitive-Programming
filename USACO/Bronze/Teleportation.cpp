/*
ID: 1026840
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int max_of(int a, int b)
{
    return a >= b ? a : b;
}
int min_of (int a, int b)
{
    return a <= b ? a : b;
}
int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if(a == b)
    {
        cout << "0" << endl;
    }
    else
    {
        int distance = abs(b - a);
        int ma = max_of(x, y);
        int mi = min_of(x, y);
        if(a > b){
            int c = abs(a - ma);
            int d = abs(b - mi);
            if(c + d < distance){
                distance = c + d;
            }
        }
        else {
            int c = abs(a - mi);
            int d = abs(b - ma);
            if(c + d < distance){
                distance = c + d;
            }
        }

        cout << distance << endl;
    }

}
