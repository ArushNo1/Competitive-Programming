#include <iostream>
#pragma GCC Optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define endll '\n'

#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& arr){
	os << "[";
    for(const T x : arr){
		os << x << " ";
	}
	os << "]";
    return os;
}
#define opp(x) (x == '0' ? '1' : '0')
void solven1(ll m){
    string s;
    cin >> s;
    int ans = 0;
    int count = 0;
    for(int i = 0; i < m - 2; i++){
        if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
            count++;
            if(i < m - 3 && s[i]!=s[i+3]){
                s[i+1]=!s[i];
            }else{
                s[i+2]=!s[i];
            }
        }
    }

    cout << count << endll;
}

void solve(){
    ll N, M; cin >> N >> M;

    if(N == 1 && M > 10) 
    {
        solven1(M);
        return;
    }

    vector<string> grid(N);

    for(ll i = 0; i < N; i++) cin >> grid[i];

    ll ans = 1e9;
    for(ll Nbm = 0; Nbm < (1 << N); Nbm++)
    {
        for(ll Mbm = 0; Mbm < (1 << M); Mbm++)
        {
            vector<string> curGrid = grid;
            ll curAns = 0;
            for(ll i = 0; i < N; i++)
            {
                if(Nbm & (1 << i))
                {
                    for(ll j = 0; j < M; j++) curGrid[i][j] = opp(curGrid[i][j]);
                    curAns++;
                }
            }

            for(ll j = 0; j < M; j++)
            {
                if(Mbm & (1 << j))
                {
                    for(ll i = 0; i < N; i++) curGrid[i][j] = opp(curGrid[i][j]);
                    curAns++;
                }
            }

            bool possible = true;

            for(ll i = 0; i < N; i++)
            {
                for(ll j = 0; j < M - 2; j++) if(curGrid[i][j] == curGrid[i][j+1] && curGrid[i][j] == curGrid[i][j+2]) possible = false;
            }

            for(ll j = 0; j < M; j++)
            {
                for(ll i = 0; i < N - 2; i++) if(curGrid[i][j] == curGrid[i+1][j] && curGrid[i][j] == curGrid[i+2][j]) possible = false;
            }

            if(possible) ans = min(ans, curAns);
        }
    }

    if(ans == 1e9) ans = -1;
    cout << ans << endll;
    
}

int main(){
    ll T; cin >> T;

    for(ll t = 0; t < T; t++)
    {
        solve();
    }
}