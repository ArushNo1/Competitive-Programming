#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'
#define dbg(x) cerr << #x << " = " << x << endll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i= 0; i< n; i++){
        cin >> nums[i];
    }

    int maxlen = 1;
    for(int i = 0; i < n; i++){
        int negval = -1;
        for(int len = 1; len <= n; len++){
            if(i + len >= n){
                break;
            }
            if(i - len < 0){
                break;
            }
            int a = nums[i + len];
            int b = nums[i - len];
            if(a == -1){
                a = negval;
            }
            if(b == -1){
                b = negval;
            }
            if(a == b){
                maxlen = max(maxlen, 2 * len + 1);
                continue;
            }
            if(a == -1){
                maxlen = max(maxlen, 2 * len + 1);
                negval = b;
                continue;
            }
            if(b == -1){
                maxlen = max(maxlen, 2 * len + 1);
                negval = a;
                continue;
            }
            break;
        }
    }
    for(int i = 0; i < n; i++){
        int negval = -1;
        for(int len = 1; len <= n; len++){
            if(i + len > n){
                break;
            }
            if(i - len < 0){
                break;
            }
            int a = nums[i + len - 1];
            int b = nums[i - len];
            if(a == -1){
                a = negval;
            }
            if(b == -1){
                b = negval;
            }
            if(a == b){
                maxlen = max(maxlen, 2 * len);
                continue;
            }
            if(a == -1){
                maxlen = max(maxlen, 2 * len);
                negval = b;
                continue;
            }
            if(b == -1){
                maxlen = max(maxlen, 2 * len);
                negval = a;
                continue;
            }
            break;
        }
    }
    cout << maxlen << endll;
    return 0;
}
