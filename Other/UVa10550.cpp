#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool open = true;


int norm(int x){
    x = x * 9;
    x += 360;
    x %= 360;
    return x;
}

int solve(int a, int b, int c, int d){
    int output = 720;
    output += norm(a - b);
    output += 360;
    output += norm(c - b);
    output += norm(c - d);
    return output;
}


int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(a || b || c || d){
        cout << solve(a, b, c, d) << endl;
        cin >> a >> b >> c >> d;
    }
    

}
