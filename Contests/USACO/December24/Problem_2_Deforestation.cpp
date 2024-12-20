#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << " ";
    }
    return os << "]";
}
ostream& operator<< (ostream& os, const set<int>& arr){
    os << "[";
    for(const int x : arr){
        os << x << " ";
    }
    os << "]";
    return os;
}

struct segment{
    int l, r;
    int count;
    friend ostream& operator<< (ostream& os, const segment& s){
        os << "(" << s.l << ", " << s.r << ", " << s.count << ", e:" << s.t << ")";
        return os;
    }
    int t;
    bool operator< (const segment& s){
        return l < s.l;
    }
};

void solvegen(int num_tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> trees;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        trees.push_back(t);
    }
    sort(all(trees));
    dbg(trees);
    //for each segment, calculate the number of trees in it
    //Then, you can remove T - ti trees from each segment
    //Remove the trees that are only in one segment?

    vector<segment> segments;
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        int t;
        cin >> t;
        auto lb = lower_bound(all(trees), l);
        auto ub = upper_bound(all(trees), r);
        int trees = ub - lb;
        segments.push_back({l, r, trees, trees - t});
    }
    dbg(segments);
    
}

void solvesmall(int num_tc){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> trees(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        trees[i] = {x, 0};
    }
    sort(all(trees));
    vector<segment> segments;

    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        int t;
        cin >> t;
        int lb = lower_bound(all(trees), make_pair(l, -1e9)) - trees.begin();
        int ub = upper_bound(all(trees), make_pair(r, 1e9)) - trees.begin();
        for(int j = lb; j < ub; j++){
            trees[j].second ++;
        }
        segments.push_back({l, r, ub - lb, ub - lb - t});
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
