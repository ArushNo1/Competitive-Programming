#include <bits/stdc++.h>
#include <cstdlib>
#include <set>
using namespace std;
int main(){
    int t;
    cin >> t;
    int n, last_num, c, last_num_2;
    string output;

    for(int test = 0; test < t; test++){
        cin >> n;
        int hays[n];
        for(int i = 0; i < n; i++){
            cin >> hays[i];
        }
        set<int> likeable;
        last_num_2 = -1;
        last_num = -1;
        for(int i = 0; i < n; i++){
            c = hays[i];
            if(c == last_num || c == last_num_2){
                likeable.insert(c);
            }
            last_num_2 = last_num;
            last_num = c;
        }
        if(likeable.size() == 0){
            output += "-1\n";
            continue;
        }
        for(auto x : likeable){
            output += to_string(x) + " ";
        }
        output.pop_back();
        output += "\n";
    }
    cout << output;
}
