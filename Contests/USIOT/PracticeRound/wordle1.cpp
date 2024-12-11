

#include<vector>
#include<string>
#include<map>
#include<iostream>

typedef long long ll;

using namespace std;


vector<int> exclude(int n){
    vector<int> result;
    for(int i = 0; i < 5; i++){
        if(i != n){
            result.push_back(i);
        }
    }
    return result;
}


bool solved(string answer){
    for(int i = 0; i < 5; i++){
        if(answer[i] == '_')
            return false;
    }
    return true;
}

void solve(){
    map<char, vector<int>> letterpos;
    string answer = "_____";
    vector<string> gs = {"abcde", "fghij", "klmno","pqrst", "uvwxy", "zzzzz"};
    

    int validlets = 0;
    for(int i = 0; i < 6; i++){
        string g = gs[i];
        cout << "? " << g << endl;
        string feed;
        cin >> feed;
        
        for(int j = 0; j < 5; j++){
            char c = feed[j];
            if(c == 'G')
            {
                answer[j]=g[j];
                letterpos[g[j]] = exclude(j);
                validlets++;
            }
            else if(c == 'Y'){
                letterpos[g[j]] = exclude(j);
                validlets++;
            }
        }
        if(validlets >= 5){
            break;
        }
    }

    if(solved(answer)){
        cout << "! " << answer << endl;
        return;
    }
    
    for(auto x = letterpos.begin();x!=letterpos.end();x++){
        if(x->first == letterpos.rbegin()->first){
            break;
        }
        string guess="";
        for(int i=0;i<5;i++){
            guess+=x->first;
        }
        cout<< "? " << guess << endl;
        string feed;
        cin >> feed;
        for(int count=0;count<feed.length();count++){
            if(feed[count]== 'G'){
                answer[count]=x->first;
            }
        }
    }

    char last = letterpos.rbegin()->first;
    for(int i = 0; i < 5; i++){
        if(answer[i] == '_'){
            answer[i] = last;
        }
    }
    cout << "! " << answer << endl;
    return;
                

    

}

int main(){

    int T = 1;
    cin >> T;
    for(int t = 0; t < T; t++){
        solve();
    }
}

