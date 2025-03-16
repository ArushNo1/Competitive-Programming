#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> gnomes(n);
    for (int i = 0; i < n; i++) {
        cin >> gnomes[i];
    }
    vector<pair<ll, ll>> swaps;
    set<ll> taken;
    for (int i = 0; i < n; i++) {
        if (gnomes[i] == i) {
            continue;
        }
        if (gnomes[gnomes[i]] != i) {
            cout << "NO";
            return 0;
        }
        else {
            if (taken.count(i) == 0) {
                swaps.push_back({i, gnomes[i]});
                taken.insert(i);
                taken.insert(gnomes[i]);
            }
        }
    }
    cout << "YES\n";
    vector<vector<pair<ll, ll>>> answer;
    for (int i = 0; i < swaps.size(); i++) {
        ll l = swaps[i].first, r = swaps[i].second;
        ll lower = 0, upper = answer.size() - 1, value = -1;
        while (upper >= lower) {
            ll mid = lower + (upper - lower) / 2;
            ll s = answer[mid].size() - 1;
            if (l > answer[mid][s].first && r < answer[mid][s].second) {
                value = mid;
                upper = mid - 1;
            }
            else {
                lower = mid + 1;
            }
        }
        if (value == -1) {
            answer.push_back({{l, r}});
        }
        else {
            answer[value].push_back({l, r});
        }
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i].size() * 2 << " ";
        for (auto p : answer[i]) {
            cout << p.first << " " << p.second << " ";
        }
        cout << "\n";
    }
}