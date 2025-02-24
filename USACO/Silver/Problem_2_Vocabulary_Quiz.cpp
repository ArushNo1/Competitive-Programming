#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()


void solve(int num_tc)
{
    int n;
    cin >> n;
    vi parent(n + 1, -1);
    vi depth(n + 1, 0);
    vi children(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> parent[i];
        children[parent[i]]++;
        depth[i] = depth[parent[i]] + 1;
    }
    int q = 0;
    for(int i = 1; i <= n; i++){
        if(children[i] == 0){
            q++;
        }
    }
    for(int i = 0; i < q; i++){
        int node;
        cin >> node;
        if(i == q - 1){
            cout << 0 << endll;
            break;
        }
        int orignode = node;
        while(children[parent[node]] <= 1){
            node = parent[node];
            if(node == -1 || node == 0) break;
        }
        children[parent[orignode]]--;
        while(children[parent[orignode]] == 0){
            orignode = parent[orignode];
            children[parent[orignode]]--;
        }
        if(node == -1) {
            cout << 0 << endll;
        }
        else{
            cout << depth[node] << endll;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
