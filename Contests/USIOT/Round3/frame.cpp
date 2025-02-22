#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, a;
    cin >> n >> m >> a;
    vector<pair<ll, ll>> factors;
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            factors.push_back({i, a / i});
        }
    }
    ll answer = 0;
    for (int i = 0; i < factors.size(); i++) {
        if (factors[i].first >= n && factors[i].second >= m) {
            answer += 1;
        }
        if (factors[i].first >= m && factors[i].second >= n) {
            answer += 1;
        }
    }
    cout << answer;
}