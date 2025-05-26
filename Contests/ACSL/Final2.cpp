#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

string curMove;

struct marble {
    int color;
    int size;
    marble(int c, int s) : color(c), size(s) {}
};

struct tube{
    int size;
    int currentSize = 0;
    string id;
    vector<marble> marbles;
    tube(int s) : size(s) {}
    tube(int s, string colors) : size(s) {
        for(char c : colors) {
            int color = c - '0'; // Assuming colors are represented as digits
            addMarble(color);
        }
    }
    bool addMarble(int color){
        if(currentSize == size){
            return false;
        }
        currentSize++;
        if(marbles.size() > 0 && marbles.back().color == color) {
            marbles.back().size++;
        } else {
            marbles.push_back(marble(color, 1));
        }
        return true;
    }
    bool addMarble(int color, int size){
        if(currentSize + size > this->size){
            return false;
        }
        currentSize += size;
        if(marbles.empty()) {
            marbles.push_back(marble(color, size));
            return true;
        }
        if(marbles.back().color == color) {
            marbles.back().size += size;
        } else {
            marbles.push_back(marble(color, size));
        }
        return true;
    }
    bool full() const {
        int totalSize = 0;
        for(const auto& m : marbles) {
            totalSize += m.size;
        }
        return totalSize >= size;
    }
    bool canMoveTo(const tube& other) const {
        if(id == other.id) return false;
        if(other.full()) return false;
        if(marbles.empty()) return false;
        if(other.marbles.empty()) return true;
        if(marbles[0].size == size) return false;
        if(marbles.back().color == other.marbles.back().color) {
            return other.currentSize + marbles.back().size <= other.size;
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, const tube& t) {
        if(t.empty()) {
            return os << "----";
        }
        string res;
        for(const auto& m : t.marbles) {
            res += string(m.size, char('0' + m.color));
        }
        while(res.size() < t.size) {
            res += '-'; 
        }
        return os << res;
    }
    bool empty() const {
        return marbles.empty();
    }
    bool sendMarbleTo(tube& other) {
        if(!canMoveTo(other)) return false;
        if(marbles.empty()) return false;
        if(id == other.id) return false;
        marble m = marbles.back();
        marbles.pop_back();
        currentSize -= m.size;
        if(other.addMarble(m.color, m.size)) {
            curMove += this->id + "" + other.id + " ";
            return true;
        }
        return false;
    }
};
vector<tube> tubes;

bool checksolved() {
    for(const tube& t : tubes){
        if(t.empty()) continue;
        if(!t.full()) return false;
        if(t.marbles.size() > 1) return false;
        if(t.marbles[0].size != t.size) return false;
    }
    return true;
}

int met2I = 0;

bool tryMethod1(){
    curMove = "";
    int firstEmpty = -1;
    for(int i = 0; i < tubes.size(); i++){
        if(tubes[i].empty()) {
            firstEmpty = i;
            break;
        }
    }
    dbg(firstEmpty);
    if(firstEmpty == -1) return false;


    int maxColor = -1;
    int maxCount = 0;
    for (int c = 0; c < 7; c++) {
        int count = 0;
        for (const tube& t : tubes) {
            if (t.empty()) continue;
            if (t.marbles.size() == 1 && t.marbles[0].size == t.size) 
                continue;          
            if (t.marbles.back().color == c) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxColor = c;
        }
    }
    dbg(maxColor);
    dbg(maxCount);

    bool moved = false;
    for(tube& t : tubes) {
        if(t.empty()) continue;
        if(t.marbles.back().color == maxColor) {
            if(t.sendMarbleTo(tubes[firstEmpty])) {
                moved = true;
            }
        }
    }
    if(moved) met2I = 0;
    return moved;
}



bool tryMethod2(){
    dbg("method2");
    curMove = "";
    int n = tubes.size();
    for(int cnt = 0; cnt < n; cnt++) {
        int i = (met2I + cnt) % n;
        dbg(i);
        for(int j = (i + 1) % n; j != i; j = (j + 1) % n){
            if(tubes[i].empty() || tubes[j].empty()) continue;
            if(tubes[i].canMoveTo(tubes[j])){
                dbg("moving marble from " + tubes[i].id + " to " + tubes[j].id);
                tubes[i].sendMarbleTo(tubes[j]);
                met2I = i;
                return true;
            }
        }
    }
    met2I = (met2I + 1) % n;
    return false;
}

/*
blue, green, purple, orange, red, tan, yellow
*/

string marblesSort(int num, vector<string> original) {
    for(string& s : original) {
        for(char & c : s) {
            if(c == 'B'){
                c = '0';
            } else if(c == 'G') {
                c = '1';
            } else if(c == 'O') {
                c = '2';
            } else if(c == 'P') {
                c = '3';
            } else if(c == 'R') {
                c = '4';
            } else if(c == 'T') {
                c = '5';
            } else if(c == 'Y') {
                c = '6';
            }
        }
        reverse(all(s));
    }
    for(const string& s : original) {
        tubes.push_back(tube(num, s));
        tubes.back().id = to_string(tubes.size());
    }
    tubes.push_back(tube(num));
    tubes.back().id = to_string(tubes.size());
    tubes.push_back(tube(num));
    tubes.back().id = to_string(tubes.size());
    string result = "";
    int counter = 0;
    while(!checksolved() && (counter++ < 125)) {
        dbg(tubes);
        if(!tryMethod1()) {
            if(!tryMethod2()){
                break;
            }
            else{
                result += curMove;
            }
        }else{
            result += curMove;
        }
        
    }
    dbg(tubes);
    return result + (checksolved() ? "WON" : "LOST");
}

void solve(int num_tc)
{
    int n;
    cin >> n;
    vector<string> jits(n);
    fillv(jits, n);
    cout << marblesSort(n, jits) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
