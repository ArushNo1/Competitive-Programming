#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

ostream& operator<<(ostream& os, vector<int>& o){
    os << "[";
    for(int i = 0; i < o.size(); i++){
        os << o[i];
        if(i != o.size() - 1){
            os << ", ";
        }
    }
    os << "]";
    return os; 
}

ostream& operator<<(ostream& os, map<int, int>& o){
    os << "{";
    for(pair<int, int> x : o){
        os << x.first << ": " << x.second;
        os << ", ";
    }
    os << "}";
    return os;
}


void solve(int num_tc)
{
    ll n;
    cin >> n;
    set<int> b;
 

    for(int i = 0;i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    int result = 0;
    while(b.count(result)){
        result++;
    }

    cout << result << endl;

    for(int i = 0; i < 2*n + 1; i++){
        int resp;
        cin >> resp;
        if(resp == -1 || resp == -2){
            return;
        }
        cout << resp << endl;
    }
    
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
