#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num_plants;


bool check2(long long heights[], int pos[]){
    vector<int> maxIndeces;
    int max = -1;
    int maxIndex;

    for(int j = 0; j < num_plants; j++){
        for(int i = 0; i < num_plants; i++){
            if(heights[i] > max && find(maxIndeces.begin(), maxIndeces.end(), i) == maxIndeces.end()){
                maxIndex = i;
                max = heights[i];
            }
            else if(heights[i] == max){
                return false;
            }
        }

        if(pos[maxIndex] != j) return false;
        maxIndeces.push_back(maxIndex);
        max = -1;
    }

    return true;
}

bool check(long long heights[], int pos[]){
    int p_bigger = 0;
    for(int i = 0; i < num_plants; i++){
        for(int j = 0; j < num_plants; j++){
            if(heights[j] > heights[i]){
                p_bigger++;
            }
        }
        if(p_bigger != pos[i]){
            return false;
        }
        p_bigger = 0;
    }
    return true;
}

int main()
{
    vector<int> results;
    int num_cases;
    cin >> num_cases;
    for(int tCase = 0; tCase < num_cases; tCase++){
        cin >> num_plants;
        long long heights[num_plants];
        long long growth_speeds[num_plants];
        int desired_positions[num_plants];
        for(int i = 0; i < num_plants; i++){
            cin >> heights[i];
        }
        for(int i = 0; i < num_plants; i++){
            cin >> growth_speeds[i];
        }
        for(int i = 0; i < num_plants; i++){
            cin >> desired_positions[i];
        }
        int counter = 0;
        while(!check(heights, desired_positions) && counter < 20000){
            counter++;
            for(int i = 0; i < num_plants; i++){
                heights[i] += growth_speeds[i];
            }
        }
        if(counter == 20000) results.push_back(-1);
        else results.push_back(counter);
    }
    for(int i = 0; i < num_cases; i++){
        cout << results[i] << endl;
    }
    return 0;
}
