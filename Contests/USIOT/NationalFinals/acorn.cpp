#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endll '\n'

int main() {
    int x, y;
    cin >> x >> y;
    bool sp = 0;
    if(x > y){
        swap(x, y);
        sp = 1;
    }
    if(x == 0 && y == 1){
        cout << "N" << endl;
        return 0;
    }
    if(x % 2 == 1){
        cout << "C" << endl;
        y = x - 1;
        if(sp){
            cout << y << " " << x << endl;
        }
        else{
            cout << x << " " << y << endl;
        }
        if(x > y){
            sp = 1;
            swap(x, y);
        }
        while(x != 0 || y != 1){
            sp = 0;
            cin >> x >> y;
            if(x > y) {
                swap(x, y);
                sp = 1;
            }
            if(x == 0 && y == 1){
                return 0;
            }
            
            if(x % 2 == 0){
                y = x + 1;
            }
            else{
                y = x - 1;
            }
            if(sp){
                cout << y << " " << x << endl;
            } 
            else{
                cout << x << " " << y << endl;
            }
            if(x > y){
                swap(x, y);
            }
        }
    }
    else{
        if(y == x + 1){
            cout << "N" << endl;
        }
        else{
            cout << "C" << endl;
            y = x + 1;
            if(sp){
                cout << y << " " << x << endl;
            }
            else{
                cout << x << " " << y << endl;
            }
        }
        while(x != 0 || y != 1){
            sp = 0;
            cin >> x >> y;
            if(x > y) {
                swap(x, y);
                sp = 1;
            }
            if(x == 0 && y == 1){
                return 0;
            }
            if(x % 2 == 0){
                y = x + 1;
            }
            else{
                y = x - 1;
            }
            if(sp){
                cout << y << " " << x << endl;
            } 
            else{
                cout << x << " " << y << endl;
            }
            if(x > y){
                swap(x, y);
            }
        }
    }
}