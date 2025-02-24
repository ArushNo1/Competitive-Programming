#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

typedef long long ll;

#define endll '\n'
#define dbg(x) //cerr << __LINE__ << ": " << #x << " = " << x << endl;

void print(vi& arr){
    if(arr.empty()) return;
    cout << arr[0];
    for(int i = 1; i < arr.size(); i++){
        cout << " " << arr[i];
    }
    cout << endll;
}

vi findordering(vi& arr){
    vi ans;
    int maxsofar = 0;
    for(int i = arr.size() - 1; i >= 0; i--){
        if(arr[i] >= maxsofar){
            maxsofar = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(int num_tc) {
    dbg(num_tc);
    int n;
    cin >> n;
    vi lastoc(n + 1);
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        lastoc[arr[i]] = i;
    }
    vi suffmax(n);
    suffmax[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--){
        suffmax[i] = max(suffmax[i + 1], arr[i]);
    }

    int lastprossed = -1;
    vi ans;
    for(int badindex = 0; badindex < n - 1; badindex++){
        if(arr[badindex] >= suffmax[badindex + 1]) {
            lastprossed = -1;
            continue;
        }
        if(lastprossed != -1) continue;
        //dbg(badindex);
        int j = lastoc[suffmax[badindex + 1]];
        //dbg(j);
        vi cop = arr;
        rotate(cop.begin() + badindex, cop.begin() + j, cop.begin() + j + 1);
        vi current_best = findordering(cop);
        if (ans.empty() || !lexicographical_compare(current_best.begin(), current_best.end(), ans.begin(), ans.end())) {
            ans = current_best;
            dbg("found");
            dbg(badindex);
            dbg(j);
        }
        lastprossed = j;
    }
    //dbg(suffmax);
    if(ans.empty()){
        print(arr);
        return;
    }
    print(ans);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++) {
        solve(t + 1);
    }
}