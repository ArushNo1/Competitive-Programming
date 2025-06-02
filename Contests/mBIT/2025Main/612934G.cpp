#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll NEG_INF = LLONG_MIN/4;

// -- Segment‐Tree for point‐update + range‐max‐query over [0..N-1] --
struct SegmentTree {
    int N;
    vector<ll> seg;
    SegmentTree(int _N) {
        N = _N;
        seg.assign(4*N, NEG_INF);
    }
    // internal point‐update
    void upd(int idx, ll val, int node, int left, int right) {
        if (left == right) {
            seg[node] = max(seg[node], val);
            return;
        }
        int mid = (left + right) >> 1;
        if (idx <= mid) 
            upd(idx, val, node<<1, left, mid);
        else 
            upd(idx, val, node<<1 | 1, mid+1, right);
        seg[node] = max(seg[node<<1], seg[node<<1 | 1]);
    }
    void update(int idx, ll val) {
        upd(idx, val, 1, 0, N-1);
    }
    // internal range‐max over [ql..qr]
    ll qry(int ql, int qr, int node, int left, int right) {
        if (qr < left || right < ql) return NEG_INF;
        if (ql <= left && right <= qr) return seg[node];
        int mid = (left + right) >> 1;
        return max(
            qry(ql, qr, node<<1, left, mid),
            qry(ql, qr, node<<1 | 1, mid+1, right)
        );
    }
    ll query(int ql, int qr) {
        if (ql > qr) return NEG_INF;
        return qry(ql, qr, 1, 0, N-1);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        int n; 
        ll k;
        cin >> n >> k;

        vector<int> P(n+1);
        vector<ll> T(n+1);
        for(int i = 1; i <= n; i++){
            cin >> P[i] >> T[i];
        }

        // 1) Build prefix sums st[i], en[i].
        vector<ll> st(n+1, 0), en(n+1, 0);
        ll cur = 0;
        for(int i = 1; i <= n; i++){
            st[i] = cur;
            en[i] = cur + T[i];
            cur += T[i];
        }

        // 2) Coordinate‐compress all values { en[i],  st[i]-k,  en[i]-k }.
        vector<ll> allc;
        allc.reserve(3*n);
        for(int i = 1; i <= n; i++){
            allc.push_back(en[i]);
            allc.push_back(st[i] - k);
            allc.push_back(en[i] - k);
        }
        sort(allc.begin(), allc.end());
        allc.erase(unique(allc.begin(), allc.end()), allc.end());

        // helper to get compressed index of x
        auto getIndex = [&](ll x) {
            // binary search in allc
            int idx = int(lower_bound(allc.begin(), allc.end(), x) - allc.begin());
            return idx; // in [0..allc.size()-1]
        };

        int M = (int)allc.size();
        SegmentTree segDP(M), segVal(M);

        vector<ll> dp(n+1, NEG_INF);
        vector<int> lastOcc(n+1, 0); // last index where position p appeared

        ll answer = 0;

        for(int i = 1; i <= n; i++){
            // 3a) “Start fresh” in p[i]:
            ll best = T[i];

            // 3b) “Stay‐same‐position” from lastOcc[p[i]]:
            int prevIdx = lastOcc[P[i]];
            if (prevIdx != 0) {
                best = max(best, dp[prevIdx] + T[i]);
            }

            // 3c) “Switch from any other j<i”:
            // We need:
            //   best_full  = max_{en[j] ≤ st[i]-k} ( dp[j] ) + T[i]
            //   best_part  = max_{st[i]-k < en[j] ≤ en[i]-k} ( dp[j] - en[j] ) + (en[i]-k)
            //
            ll x1 = st[i] - k;   // threshold for “full capture”
            ll x2 = en[i] - k;   // upper threshold for “partial capture”
            int idx1 = getIndex(x1);
            int idx2 = getIndex(x2);

            // max over en[j] ≤ x1  of dp[j]
            ll best_full = segDP.query(0, idx1);
            if (best_full != NEG_INF) {
                best = max(best, best_full + T[i]);
            }

            // max over x1 < en[j] ≤ x2  of ( dp[j] - en[j] )
            ll best_part = segVal.query(idx1+1, idx2);
            if (best_part != NEG_INF) {
                best = max(best, best_part + (en[i] - k));
            }

            dp[i] = best;
            answer = max(answer, dp[i]);

            // 4) Insert dp[i] into our two segment‐trees at index = comp(en[i])
            int idx_en_i = getIndex(en[i]);
            segDP.update(idx_en_i, dp[i]);
            segVal.update(idx_en_i, dp[i] - en[i]);

            // 5) update lastOcc for position P[i]
            lastOcc[ P[i] ] = i;
        }

        cout << answer << "\n";
    }

    return 0;
}
