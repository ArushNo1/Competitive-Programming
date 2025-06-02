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

struct solu{
    
vector<bool> vis;
deque<int> snake;
vector<vector<int>> adj;
int n, u, v;

void dfs1(int node, int par = -1)
{
    for(int child : adj[node])
    {
        if(child == par) continue;
        snake.push_back(child);

        if(snake.back() == v)
        {
            return;
        }

        dfs1(child, node);

        if(snake.back() == v)
        {
            return;
        }

        snake.pop_back();
    }
}

//find farthest node from head of snake
int farthest = 0, farthest_node = -1; 
void dfs2(int node, int depth, int par = -1)
{
    //vis[node] = true;
    if(depth > farthest)
    {
        farthest = depth;
        farthest_node = node;
    }

    for(int child : adj[node])
    {
        if(child == par) continue;
        dfs2(child, depth + 1, node);
    }
}

//move the snake to the farthest point
void dfs3(int node, int far = -1, int par = -1)
{
    //vis[node] = true;
    for(int child : adj[node])
    {
        if(child == par) continue;

        snake.push_front(child);
        int last = snake.back();
        snake.pop_back();

        if(snake.front() == far)
        {
            return;
        }

        dfs3(child, far, node);

        if(snake.front() == far)
        {
            return;
        }

        snake.push_back(last);
        snake.pop_front();
    }
}

void dfs4(int node, int par = -1)
{
    vis[node] = true;
    for(int child : adj[node])
    {
        if(child == par) continue;
        dfs4(child, node);
    }
}

void solve(int num_tc)
{
    dbg(num_tc);
    cin >> n >> u >> v;
    //head = u, tail = v
    u--; v--;
    vis = vector<bool>(n, false);
    adj = vector<vector<int>>(n);
    snake = deque<int>();

    for(int i = 0; i < n-1; i++)
    {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    snake.push_front(u);
    //find the snake
    dfs1(u);

    snake.pop_front();
    int illegal = snake.front();
    snake.push_front(u);

    //find farthest node from head
    farthest = -1;
    farthest_node = -1;
    dfs2(u, 0, illegal);
    dbg(farthest_node);
    dbg(snake);

    //move head to farthest node
    dfs3(u, farthest_node);
    dbg(snake);

    //find all visitable nodes from tail
    int bck = snake.back();
    snake.pop_back();
    int illegal2 = snake.back();
    snake.push_back(bck);
    dfs4(bck, illegal2);
    dbg(vis);

    //move tail to farthest node
    //reverse the deque
    reverse(snake.begin(), snake.end());

    dbg(snake);

    farthest = -1;
    farthest_node = -1;
    int frt = snake.front();
    snake.pop_front();
    illegal = snake.front();
    snake.push_front(frt);
    dfs2(frt, 0, illegal);
    dbg(farthest_node)

    dfs3(frt, farthest_node);
    dbg(snake)

    bck = snake.back();
    snake.pop_back();
    illegal2 = snake.back();
    snake.push_back(bck);
    dfs4(bck, illegal2);
    dbg(vis);

    reverse(snake.begin(), snake.end());

    dbg(snake);

    farthest = -1;
    farthest_node = -1;
    frt = snake.front();
    snake.pop_front();
    illegal = snake.front();
    snake.push_front(frt);
    dfs2(frt, 0, illegal);
    dbg(farthest_node)

    dfs3(frt, farthest_node);
    dbg(snake)

    bck = snake.back();
    snake.pop_back();
    illegal2 = snake.back();
    snake.push_back(bck);
    dfs4(bck, illegal2);
    dbg(vis);

    for(int lmao = 0; lmao < 20; lmao++) {
    
    reverse(snake.begin(), snake.end());

    dbg(snake);

    farthest = -1;
    farthest_node = -1;
    frt = snake.front();
    snake.pop_front();
    illegal = snake.front();
    snake.push_front(frt);
    dfs2(frt, 0, illegal);
    dbg(farthest_node)

    dfs3(frt, farthest_node);
    dbg(snake)

    bck = snake.back();
    snake.pop_back();
    illegal2 = snake.back();
    snake.push_back(bck);
    dfs4(bck, illegal2);
    dbg(vis);
    }

    cout << accumulate(vis.begin(), vis.end(), 0) << endll;
}

};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        (solu()).solve(t+1);
    }
}