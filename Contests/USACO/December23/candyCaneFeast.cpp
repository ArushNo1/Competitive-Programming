#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool cane_gone = false;

int ceil(int x, int ceiling){
    if(x >= ceiling){
        cane_gone = true;
        return ceiling;
    }
    return x;
}

int start()
{
    int num_cows;
    int num_canes;
    cin >> num_cows >> num_canes;
    long long cow_heights[num_cows];
    long long cane_heights[num_canes];
    int max_height = 0;
    int max_cow;
    for(int i = 0; i < num_cows; i++){
        cin >> cow_heights[i];
        if(cow_heights[i] > max_height){
            max_height = cow_heights[i];
            max_cow = i;
        }
    }
    for(int i = 0; i < num_canes; i++){
        cin >> cane_heights[i];
    }

    int previous_cow_height;
    for(int cane = 0; cane < num_canes; cane++){
        cane_gone = false;
        if(cow_heights[0] >= cane_heights[cane]){
            cow_heights[0] += cane_heights[cane];
            continue;
        }
        previous_cow_height = 0;
        for(int cow = 0; cow <= max_cow; cow++){
            int difference = ceil(cow_heights[cow], cane_heights[cane]) - previous_cow_height;
            if(difference <= 0) {
                    continue;
            }
            previous_cow_height = cow_heights[cow];
            cow_heights[cow] += difference;
            if(cane_gone){
                break;
            }
        }
    }

    for(int i = 0; i < num_cows; i++){
        cout << cow_heights[i] << endl;
    }
    return 0;
}
