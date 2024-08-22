/*
ID: 1026840
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int num_words, max_width;
    cin >> num_words >> max_width;
    string words[num_words];
    for(int i = 0; i < num_words; i++){
        cin >> words[i];
    }
    int linewidth = words[0].length();

    cout << words[0];
    for(int i = 1; i < num_words; i++){
        int l = words[i].length();
        if(max_width - linewidth >= l){
            cout << " " << words[i];
            linewidth += l;
        }
        else{
            cout << "\n" << words[i];
            linewidth = l;
        }
        //cerr << linewidth << endl;
    }
    cout << endl;

}
