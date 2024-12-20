#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;


#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

/*
int n;
    cin >> n;
    ll sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    ll l = 0, r = n - 1;
    ll esum = 0;
    bool worthtrying = (sum != v[0] * n);
    for(int i = 0; i < (n - 1) / 2; ++i){
        if(v[l] > v[r]){
            esum += v[l];
            l++;
        }else if (v[l] < v[r]){
            esum += v[r];
            r--;
        }else if(worthtrying){
            int tl = l, tr = r;
            bool found = false;
            while(tl < tr){
                if(v[tl] > v[tr]){
                    esum += v[l];
                    l++;
                    found = true;
                    break;
                }else if(v[tl] < v[tr]){
                    esum += v[r];
                    r--;
                    found = true;
                    break;
                }
                tl++, tr--;
            }
            if(!found){
                esum += v[l];
                l++;
                worthtrying = false;
            }
        }else{
            esum += v[l];
            l++;
        }
    }
    cout << sum - esum << " " << esum << endll;
    //(n - 1) / 2 turns*/

void solve(int num_tc)
{
    
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    ll esum = 0;
    ll lsum = 0, rsum = 0;
    int k = (n - 1) / 2;
    for(int i = 0; i < k; i++){
        lsum += v[i];
    }
    esum = lsum;
    for(int i = k - 1; i >= 0; i--){
        rsum += v[n - 1 - i];
        lsum -= v[i];
        esum = max(esum, lsum + rsum);
    }
    cout << sum - esum << " " << esum << endll;
    //(n - 1) / 2 turns
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
