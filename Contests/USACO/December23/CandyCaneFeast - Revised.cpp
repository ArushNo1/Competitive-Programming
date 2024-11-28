#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int num_cows, num_canes;
    cin >> num_cows >> num_canes;
    ll cows[num_cows];
    int max_cow_index = 0;
    ll max_cow_height = 0;
    for(int i = 0; i < num_cows; i++){
        cin >> cows[i];
        if(cows[i] > max_cow_height){
            max_cow_index = i;
        }
    }

    ll cane_height, height_eaten;
    for(int q = 0; q < num_canes; q++){
        cin >> cane_height;
        height_eaten = 0;
        if(cows[0] >= cane_height){
            cows[0] += cane_height;
            continue;
        }
        for(int i = 0; i <= max_cow_index; i++){
            int amt_eaten = min(cane_height, cows[i]) - height_eaten;
            if(amt_eaten > 0){
                height_eaten += amt_eaten;
                cows[i] += amt_eaten;
            }
        }
    }

    for(int i = 0; i < num_cows; i++){
        cout << cows[i] << endl;
    }

}
