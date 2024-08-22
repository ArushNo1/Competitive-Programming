#include <bits/stdc++.h>
using ll = long long;
 
 
using namespace std;

int main()
{
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    vector<ll> row(1001, 0);
    vector<vector<ll>> barn(1001, row);
    ll n, k;
    cin >> n >> k;
    ll x1, x2, y1, y2;
    ll m_x = 0, m_y = 0;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        m_x = max(m_x, x2);
        m_y = max(m_y, y2);
        for(int r = y1; r < y2; r++){
            barn[r][x1] ++;
            barn[r][x2] --;
        }
    }
    /*
    for(int r = 0; r < m_y + 2; r++){
        for(int c = 0; c < m_x + 2; c++){
            cout << barn[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    ll row_sum = 0;
    ll k_squares = 0;
    for(int r = 0; r < m_y + 2; r++){
        for(int c = 0; c < m_x + 2; c++){
            row_sum += barn[r][c];
            //cout << row_sum << " ";
            if(row_sum == k){
                k_squares++;
            }
        }
        //cout << endl;
    }
    cout << k_squares;

}


