#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool found = 0;
vector<vector<ll>> adj;
set<int> visited;
set<int> cc;

void dfs(int node, int par) {
    if(cc.count(node)){
        found = 1;
        return;
    }
    if(visited.count(node)){
        return;
    }
    visited.insert(node);
    cc.insert(node);
    for(auto nb : adj[node]){
        if(nb == par) continue;
        dfs(nb, node);
    }
}

int main() {
    ll n, m, e, x, y;
    cin >> n >> m >> e;
    adj = vector<vector<ll>>(n + m);
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        y += n;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    deque<ll> a, b;
    vector<bool> v(n + m);
    for(int i = 0; i < n + m; i++){
        if(!visited.count(i)){
            cc.clear();
            dfs(i, -1);
        }
        if(found){
            cout << -1;
            return 0;
        }
        if (cc.size() == 0) {
            continue;
        }
        stack<pair<ll, bool>> nodes; // 0 is left, 1 is right
        ll node = *(cc.begin());
        nodes.push({node, false});
        while (nodes.size() > 0) {
            node = nodes.top().first;
            bool dir = nodes.top().second;
            nodes.pop();
            if (node < n) {
                if (!dir) a.push_front(node);
                else a.push_back(node);
            }
            else {
                if (!dir) b.push_front(node);
                else b.push_back(node);
            }
            v[node] = true;
            ll neighborcount = 0;
            vector<ll> temp;
            ll secondneighbor = -1;
            for (ll neighbor : adj[node]) {
                if (adj[neighbor].size() > 1) {
                    neighborcount += 1;
                }
                if (neighborcount > 2) {
                    cout << -1;
                    return 0;
                }
                if (!v[neighbor]) {
                    if (adj[neighbor].size() > 1) {
                        if (neighborcount == 1) {
                            nodes.push({neighbor, 1});
                        }
                        else {
                            secondneighbor = neighbor;
                        }
                    }
                    else {
                        temp.push_back(neighbor);
                    }
                }
            }
            for (ll neighbor : temp) {
                nodes.push({neighbor, 0});
            }
            if (secondneighbor != -1) {
                nodes.push({secondneighbor, 0});
            }
        }
        cc.clear();
    }
    while (a.size() > 0) {
        cout << a.front() << " ";
        a.pop_front();
    }
    cout << "\n";
    for (int i = 0 ; i < m; i++) {
        cout << b.front() - n << " ";
        b.pop_front();
    }
}