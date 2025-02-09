#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'
#define dbg(x) cerr << #x << " = " << x << endll;

// Returns 0 for right angle, -1 for acute, 1 for obtuse
int angleType(const pair<int, int>& a, const pair<int, int>& b) {
    double dot = a.first * b.first + a.second * b.second;
    double magA = sqrt(a.first * a.first + a.second * a.second);
    double magB = sqrt(b.first * b.first + b.second * b.second);
    if (magA == 0 || magB == 0) return -1;
    double cos_theta = dot / (magA * magB);
    const double EPS = 1e-9;
    
    if (abs(cos_theta) < EPS) return 0;  // right angle
    if (cos_theta > 0) return -1;        // acute angle
    return 1;                            // obtuse angle
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    int n;
    cin >> n;
    int counter = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pair<int, int> vec0 = {x0 - x, y0 - y};
        pair<int, int> vec1 = {x1 - x, y1 - y};
        pair<int, int> vec2 = {x2 - x, y2 - y};
        pair<int, int> vec3 = {x3 - x, y3 - y};
        int type0 = angleType(vec0, vec1);
        int type1 = angleType(vec1, vec2);
        int type2 = angleType(vec2, vec3);
        int type3 = angleType(vec3, vec0);
        if(type0 * type1 * type2 * type3 == 0){
            continue;
        }
        if(type0 + type1 + type2 + type3 == 0){
            counter++;
        }
    }
    cout << counter << endll;
    return 0;
}
