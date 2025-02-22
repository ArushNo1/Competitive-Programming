#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> nums(n, vector<ll>(m));
    vector<ll> rowsum(n), colsum(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            rowsum[i] += nums[i][j];
            colsum[j] += nums[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(rowsum[j] - rowsum[i]) % 3 != 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; m < n; j++) {
            if (abs(colsum[j] - colsum[i]) % 3 != 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO\n";
}