#include <bits/stdc++.h>
using namespace std;
using l = long long;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    l A[N+1], B[N+1], C[N+1];
    l x;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 1){
            A[i + 1] = A[i] + 1;
            B[i + 1] = B[i];
            C[i + 1] = C[i];
        }
        else if(x == 2){
            A[i + 1] = A[i];
            B[i + 1] = B[i] + 1;
            C[i + 1] = C[i];
        }
        else if(x == 3){
            A[i + 1] = A[i];
            B[i + 1] = B[i];
            C[i + 1] = C[i] + 1;
        }
    }
    int a, b;
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << A[b] - A[a - 1] << " " << B[b] - B[a - 1] << " " << C[b] - C[a - 1] << endl;
    }
}
