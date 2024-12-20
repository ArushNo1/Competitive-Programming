#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

int num_visitable = 0;
int n;
vector<bool> unusable;
vector<bool> visited;
vector<int> nexts;
vector<int> cc;

void dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n){
        return;
    }
    if(unusable[x * n + y]){
        for(int i : cc){
            unusable[i] = true;
        }
        return;
    }
    
}

void solve(int num_tc)
{
    int m;
    cin >> n >> m;
    unusable = vector<bool>(n * n, false);
    visited = vector<bool>(n * n, false);
    vector<string> grid(n, string(n, '?'));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        char c;
        cin >> c;
        switch(c){
            case 'U':
                nexts[x * n + y] = x * n + y - n;
                break;
            case 'D':
                nexts[x * n + y] = x * n + y + n;
                break;
            case 'L':
                nexts[x * n + y] = x * n + y - 1;
                break;
            case 'R':
                nexts[x * n + y] = x * n + y + 1;
                break;
        }
    }
    for(int i = 0; i< n; i++){
        cerr << grid[i] << endll;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
