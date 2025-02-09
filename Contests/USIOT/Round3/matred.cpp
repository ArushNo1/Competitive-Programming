#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'
#define dbg(x) cerr << #x << " = " << x << endll;

struct matmove{
    int x1, y1, x2, y2;
    int val;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    int val;
    cin >> val;
    for(int i= 1; i < n * m; i++){
        int t;
        cin >> t;
    }
    val *= -1;

    vector<matmove> moves;
    if(n % 3 == 0){
        for(int top = 0; top < n - 2; top += 3){
            for(int left = 0; left < m; left++){
                moves.push_back({top, left, top + 2, left, val});
            }
        }
        cout << "YES" << endll;
        cout << moves.size() << endll;
        for(auto move : moves){
            cout << move.x1 + 1 << " " << move.y1 + 1 << " " << move.x2 + 1 << " " << move.y2 + 1 << " " << move.val << endll;
        }
        return 0;
    }
    if(m % 3 == 0){
        for(int left = 0; left < m - 2; left += 3){
            for(int top = 0; top < n; top++){
                moves.push_back({top, left, top, left + 2, val});
            }
        }
        cout << "YES" << endll;
        cout << moves.size() << endll;
        for(auto move : moves){
            cout << move.x1 + 1 << " " << move.y1 + 1 << " " << move.x2 + 1 << " " << move.y2 + 1 << " " << move.val << endll;
        }
        return 0;
    }
    cout << "NO" << endll;
    return 0;
} 
