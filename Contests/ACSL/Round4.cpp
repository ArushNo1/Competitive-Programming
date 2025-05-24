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

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode*& root, char x) {
    if (root == NULL) {
        root = new TreeNode(x);
    } else if (x <= root->val) {
        insert(root->left, x);
    } else {
        insert(root->right, x);
    }
}

int olef = 0;
int oright = 0;
int leaf = 0;
int ipl = 0;
int epl = 0;
void analyze(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    ipl += level;
    if (root->left == NULL && root->right == NULL) {
        leaf++;
    }
    else if(root->left != NULL && root->right == NULL) {
        olef++;
    }
    else if(root->left == NULL && root->right != NULL) {
        oright++;
    }
    if(root->left == NULL){
        epl += level + 1;
    }
    if(root->right == NULL){
        epl += level + 1;
    }
    analyze(root->left, level + 1);
    analyze(root->right, level + 1);
}

string analyzeTree(string word) {
    TreeNode* root = NULL;
    for (char c : word) {
        insert(root, c);
    }
    analyze(root, 0);
    return to_string(olef) + " " + to_string(oright) + " " + to_string(leaf) + " " + to_string(ipl) + " " + to_string(epl);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        string s;
        cin >> s;
        cout << analyzeTree(s) << endll;
    }
}
