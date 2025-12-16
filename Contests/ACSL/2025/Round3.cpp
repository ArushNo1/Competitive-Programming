#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


typedef vector<vector<int>> vvi;
/*
 * Complete the 'findManDist' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER width
 *  2. INTEGER M
 *  3. INTEGER N
 */
vvi triangle;

pair<int, int> find(int M){
    for(size_t i = 0; i < triangle.size(); i++){
        for(size_t j = 0; j < triangle[i].size(); j++){
            if(triangle[i][j] == M){
                return {i, j};
            }
        }
    }
    return {0, 0};
}

int findManDist(int width, int M, int N) {
    bool up = false;
    int len = width;
    int num = 1;
    for(int i = 0; num <= max(M, N); i++){
        triangle.push_back({});
        for(int j = 0; j < len; j++){
            triangle[i].push_back(num++);
        }
        if(i % 2 == 1){
            reverse(triangle[i].begin(), triangle[i].end());
        }
        if(up){
            if(len == width){
                len--;
                up = false;
            }
            else{
                len++;
            }
        }
        else{
            if(len == 1){
                len = 2;
                up = true;
            }
            else{
                len--;
            }
        }
    }
    int x1, y1, x2, y2;
    tie(x1, y1) = find(M);
    tie(x2, y2) = find(N);
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string width_temp;
    getline(cin, width_temp);

    int width = stoi(ltrim(rtrim(width_temp)));

    string M_temp;
    getline(cin, M_temp);

    int M = stoi(ltrim(rtrim(M_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = findManDist(width, M, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
