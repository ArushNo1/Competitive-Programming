#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(bool op, int a, int b){
    if(op){
        cout << "and ";
    }else{
        cout << "or ";
    }
    cout << a << " " << b << endl;
    
    int x;
    cin >> x;
    return x;
}

int sum(int a, int b){
    return ask(true, a, b) + ask(false, a, b);
}



int main()
{
    //2n-2;
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n + 1);
    
    int ab, bc, ac;
    ab = sum(1, 2);
    bc = sum(2, 3);
    ac = sum(1, 3);
    nums[1] = (ab - bc + ac) / 2;
    nums[2] = (ab + bc - ac) / 2;
    nums[3] = (-ab + bc + ac) / 2;
    
    for(int i = 3; i < n; i ++){
        nums[i + 1] = sum(i, i + 1) - nums[i];
    }
    std::sort(nums.begin(), nums.end());
    cout << "finish " << nums[k] << endl;
}
