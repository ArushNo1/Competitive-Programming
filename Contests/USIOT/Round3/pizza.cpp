#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q, numingredients, currentingredient;
    cin >> n >> m >> q;
    vector<pair<ll, ll>> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i].first >> costs[i].second;
    }
    vector<string> pizzas(m);
    for (int i = 0; i < m; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            s += '0';
        }
        cin >> numingredients;
        for (int j = 0; j < numingredients; j++) {
            cin >> currentingredient;
            s[currentingredient] = '1';
        }
        pizzas[i] = s;
    }
    for (int i = 0; i < q; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            s += '0';
        }
        cin >> numingredients;
        for (int j = 0; j < numingredients; j++) {
            cin >> currentingredient;
            s[currentingredient] = '1';
        }
        ll answer = 1e15;
        for (int j = 0; j < m; j++) {
            ll cost = 0;
            for (int k = 0; k < n; k++) {
                if (pizzas[j][k] != s[k]) {
                    if (pizzas[j][k] == '0' && s[k] == '1') {
                        cost += costs[k].first;
                    }
                    else {
                        cost += costs[k].second;
                    }
                }
            }
            answer = min(answer, cost);
        }
        cout << answer << "\n";
    }
}