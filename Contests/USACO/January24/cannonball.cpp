#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;
int main(){
    int position;
    int n;
    int velocity = 1;
    cin >> n >> position;
    position--;
    int objects[n];
    short types[n];
    short temp;
    set<int> targets;
    for(int i = 0; i < n; i++){
        cin >> types[i];
        cin >> objects[i];

    }
    int c;
    int counter = 0;

    while(position >= 0 && position < n && counter < 5000){
        counter++;
       // cout << position + 1 << "position " << velocity << " power " << endl;
        c = objects[position];
     //   cout << "power here required is " << c << endl;
        if(types[position] == 1){
            if(abs(velocity) >= c){
                targets.insert(position);
      //          cout << "added " << position << endl;
            }
        }
        else{
            if(velocity < 0){
                velocity -= c;
            }else{
                velocity += c;
            }
            velocity *= -1;
        }
        position += velocity;
    }
    cout << targets.size() << endl;

}
