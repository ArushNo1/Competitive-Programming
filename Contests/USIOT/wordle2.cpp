#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef long long ll;

using namespace std;

vector<int> exclude(int n)
{
    vector<int> result;
    for (int i = 0; i < 5; i++)
    {
        if (i != n)
        {
            result.push_back(i);
        }
    }
    return result;
}

bool solved(string answer)
{
    for (int i = 0; i < 5; i++)
    {
        if (answer[i] == '_')
            return false;
    }
    return true;
}

void solve()
{
    vector<char> letterpos;
    string answer = "_____";
    vector<string> gs = {"abcde", "fghij", "klmno", "pqrst", "uvwxy"};

    int validlets = 0;
    for (int i = 0; i < gs.size(); i++)
    {
        string g = gs[i];
        cout << "? " << g << endl;
        string feed;
        cin >> feed;

        for (int j = 0; j < 5; j++)
        {
            char c = feed[j];
            if (c == 'G')
            {
                answer[j] = g[j];
                letterpos.push_back(g[j]);
                validlets++;
            }
            else if (c == 'Y')
            {
                letterpos.push_back(g[j]);
                validlets++;
            }
        }
        if (validlets >= 5)
        {
            break;
        }
    }

    if (solved(answer))
    {
        cout << "! " << answer << endl;
        return;
    }

    auto endpos = letterpos.size() == 5? --letterpos.end(): (letterpos.end());
    for (auto x = letterpos.begin(); x != endpos; x++)
    {

        string guess = "";
        for (int i = 0; i < 5; i++)
        {
            guess += *x;
        }
        cout << "? " << guess << endl;
        string feed;
        cin >> feed;
        for (int count = 0; count < feed.length(); count++)
        {
            if (feed[count] == 'G')
            {
                answer[count] = *x;
            }
        }
    }

    //cerr << "guess " <<  answer << endl;

    if (solved(answer))
    {
        cout << "! " << answer << endl;
        return;
    }

    if(letterpos.size()<5){
        

        for (int i = 0; i < 5; i++)
        {
            if (answer[i] == '_')
            {
                answer[i] = 'z';
            }
        }
        cout << "! " << answer << endl;
        return;
    }

    char last = *letterpos.rbegin();
    for (int i = 0; i < 5; i++)
    {
        if (answer[i] == '_')
        {
            answer[i] = last;
        }
    }
    cout << "! " << answer << endl;
    return;
}

int main()
{

    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        solve();
    }
}
