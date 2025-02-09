#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'
#define dbg(x) cerr << #x << " = " << x << endll;

//#include <vectordbg.h>


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    int perim = 0;
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1--; y1--; x2--; y2--;
        
        cout << perim << endll;
    }

    return 0;
}
