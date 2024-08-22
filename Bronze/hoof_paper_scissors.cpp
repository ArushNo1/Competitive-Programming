#include <bits/stdc++.h>
using namespace std;
using l = long long;
#define int l

void print(int r[], int n){
    for(int x = 0; x < n + 1; x++){
        cout << r[x] << ", ";
    }
    cout << endl;
}

signed main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    int r[n + 1], p[n + 1], s[n + 1];
    r[0] = 0;
    p[0] = 0;
    s[0] = 0;

    char c;
    for(int i = 0; i < n; i ++)
    {
        cin >> c;
        if(c == 'H')
        {
            r[i + 1] = r[i] + 1;
            p[i + 1] = p[i];
            s[i + 1] = s[i];
        }
        else if(c == 'P')
        {
            r[i + 1] = r[i];
            p[i + 1] = p[i] + 1;
            s[i + 1] = s[i];
        }
        else if(c == 'S')
        {
            r[i + 1] = r[i];
            p[i + 1] = p[i];
            s[i + 1] = s[i] + 1;
        }
    }


    int max_wins = 0;
    int temp;
    for(int i = 0; i < n; i++){
        temp = max(p[n] - p[i - 1], s[n] - s[i - 1]);
        max_wins = max(max_wins, temp + r[i]);
        temp = max(r[n] - r[i - 1], s[n] - s[i - 1]);
        max_wins = max(max_wins, temp + p[i]);
        temp = max(r[n] - r[i - 1], p[n] - p[i - 1]);
        max_wins = max(max_wins, temp + s[i]);
    }

    cout << max_wins << endl;

}
