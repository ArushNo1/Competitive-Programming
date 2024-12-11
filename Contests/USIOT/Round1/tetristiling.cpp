#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;


void solveodd(int n){
    auto grid = vector<vi>(n, vi(n, 0));

    int id = 1;
    for(int i = 0; i < n - 6; i+=2){
        int r = i;
        int c = i;
        grid[r][c] = id;
        grid[r + 1][c] = id;
        grid[r + 2][c] = id;
        grid[r + 1][c + 1] = id;
        id++;
        grid[r][c + 1] = id;
        grid[r][c + 2] = id;
        grid[r + 1][c + 2] = id;
        grid[r + 1][c + 3] = id;
        id++;
        r = n - 1 - r;
        c = n - 1 - c;
        grid[r][c] = id;
        grid[r - 1][c] = id;
        grid[r - 2][c] = id;
        grid[r - 1][c - 1] = id;
        id++;
        grid[r][c - 1] = id;
        grid[r][c - 2] = id;
        grid[r - 1][c - 2] = id;
        grid[r - 1][c - 3] = id;
        id++;
        r = i;
        c = n - i - 1;
        grid[r][c] = id;
        grid[r + 1][c] = id;
        grid[r + 1][c - 1] = id;
        grid[r + 2][c - 1] = id;
        id++;
        grid[r][c - 1] = id;
        grid[r][c - 2] = id;
        grid[r][c - 3] = id;
        grid[r + 1][c - 2] = id;
        id++;
        r = n - 1 - r;
        c = i;
        grid[r][c] = id;
        grid[r - 1][c] = id;
        grid[r - 1][c + 1] = id;
        grid[r - 2][c + 1] = id;
        id++;
        grid[r][c + 1] = id;
        grid[r][c + 2] = id;
        grid[r][c + 3] = id;
        grid[r - 1][c + 2] = id;
        id++;  

        for(int j = i + 4; j < n - i; j += 2){
            int c = i;
            int r = j;
            cerr << "[" << i << "][" << j << "]" << endll;
        }
    }
    cout << id - 1<< endll;
    for(int i = 0; i < n; i++){
        cout << grid[i][0] << (grid[i][0] < 10 ? " " : "");
        for(int j = 1; j < n; j++){
            cout << " " << grid[i][j] << (grid[i][j] < 10 ? " " : "");
        }
        cout << endll;
    }
    
}

void solveeven(int n){
    auto grid = vector<vi>(n, vi(n, 0));

    int id = 1;
    for(int i = 0; i < n / 4 * 2; i+= 2){
        int r = i;
        int c = i;
        grid[r][c] = id;
        grid[r][c + 1] = id;
        grid[r][c + 2] = id;
        grid[r + 1][c + 1] = id;
        id++;
        r = n - i - 1;
        grid[r][c] = id;
        grid[r - 1][c] = id;
        grid[r - 2][c] = id;
        grid[r - 1][c + 1] = id;
        id++;
        c = n - i - 1;
        grid[r][c] = id;
        grid[r][c - 1] = id;
        grid[r][c - 2] = id;
        grid[r - 1][c - 1] = id;
        id++;
        r = i;
        grid[r][c] = id;
        grid[r + 1][c] = id;
        grid[r + 2][c] = id;
        grid[r + 1][c - 1] = id;
        id++;
    }
    
    for(int i = 1; i <= (n - 4) / 2; i += 2){
        dbg(i);
        for(int j = i + 1; j < (n - i - 2); j +=2){
            dbg(j);
            cerr << i << " " << j << endll;
            int r = i;
            int c = j;
            grid[r][c] = id;
            grid[r][c + 1] = id;
            grid[r - 1][c + 1] = id;
            grid[r - 1][c + 2] = id;
            id++;
            int temp = r;
            r = n - 1 - c;
            c = temp;
            grid[r - 2][c - 1] = id;
            grid[r - 1][c - 1] = id;
            grid[r - 1][c] = id;
            grid[r][c] = id;
            id++;
            temp = r;
            r = n - 1 - c;
            c = temp;
            grid[r][c] = id;
            grid[r][c - 1] = id;
            grid[r + 1][c - 1] = id;
            grid[r + 1][c - 2] = id;
            id++;
            temp = r;
            r = n - 1 - c;
            c = temp;
            grid[r + 2][c + 1] = id;
            grid[r + 1][c + 1] = id;
            grid[r + 1][c] = id;
            grid[r][c] = id;
            id++;
        }
    }

    
    cout << id - 1<< endll;
    for(int i = 0; i < n; i++){
        cout << grid[i][0];
        for(int j = 1; j < n; j++){
            cout << " " << grid[i][j];
        }
        cout << endll;
    }
}


void solve(int num_tc)
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endll << 0 << endll;
        return;
    }
    if(n == 2){
        cout << "0\n0 0\n0 0" << endll;
        return;
    }
    if(n == 3){
        cout << "1\n1 1 1\n0 1 0\n0 0 0" << endll;
        return;
    }
    if(n == 5){
        cout << "6" << endll;
        cout << "1 2 2 2 3\n1 1 2 3 3\n1 6 0 3 4\n6 6 5 4 4\n6 5 5 5 4" << endll;
        return;
    }
    if(n % 2 == 0){
        solveeven(n);
    }
    else{
        solveodd(n);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
