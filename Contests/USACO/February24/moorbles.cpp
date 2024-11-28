#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve1(ll num_marbles, ll num_moves)
{
    ll move;
    string answer = "";
    for (ll i = 0; i < num_moves; i++)
    {
        cin >> move;
        bool even = move % 2 == 0;
        if (!even && num_marbles > move)
        {
            even = true;
        }
        if (even)
        {
            answer += "Even ";
        }
        else
        {
            answer += "Odd ";
        }
        if (even != (move % 2 == 0))
        {
            num_marbles -= move;
        }
        else
        {
            num_marbles += move;
        }
    }
    answer.pop_back();
    std::cout << answer << endl;
    return;
}

void solve2(ll num_marbles, ll num_moves)
{
    // cerr << "n " << num_marbles << ", m = " << num_moves << endl;
    ll big_move, small_move;
    string answer = "";
    for (ll i = 0; i < num_moves; i++)
    {
        cin >> big_move;
        cin >> small_move;
        if (big_move < small_move)
        {
            ll temp = small_move;
            small_move = big_move;
            big_move = temp;
        }
        // cerr << big_move << ", " << small_move << " - ";
        bool big_even = big_move % 2 == 0;
        bool small_even = small_move % 2 == 0;
        // cerr << big_even << ", " << small_even << endl;
        if (small_even && big_even)
        {
            answer += "Even ";
            num_marbles += small_move;
        }
        else if (small_even)
        {
            if (num_marbles > big_move)
            {
                num_marbles -= big_move;
                answer += "Even ";
            }
            else
            {
                num_marbles -= small_move;
                answer += "Odd ";
            }
        }
        else if (big_even)
        {
            answer += "Even ";
            num_marbles += big_move;
        }
        else
        {
            if (num_marbles > big_move)
            {
                num_marbles -= big_move;
                answer += "Even ";
            }
            else
            {
                answer += "Odd ";
                num_marbles += small_move;
            }
        }
        if (num_marbles <= 0)
        {
            cout << "-1" << endl;
            return;
        }
    }
    answer.pop_back();
    cout << answer << endl;
}

void solve3(ll num_marbles, ll num_moves)
{
    ll moves[3];
    string answer = "";
    for (ll i = 0; i < num_moves; i++)
    {
        cin >> moves[0] >> moves[1] >> moves[2];
        std::sort(moves, moves + 3);
        bool a, b, c;
        a = moves[0] % 2 == 0;
        b = moves[1] % 2 == 0;
        c = moves[2] % 2 == 0;
        // cerr << big_even << ", " << small_even << endl;

        if (c)
        {
            answer += "Even ";
            if(!b){
                num_marbles -= moves[1];
            }
            else if(!a){
                num_marbles -= moves[0];
            }
            else{
                num_marbles += moves[0];
            }
        }
        else if (num_marbles > moves[2])
        {
            answer += "Even ";
            num_marbles -= moves[2];
        }
        else{
            answer += "Odd ";
            if(b){
                num_marbles -= moves[1];
            }
            else if(a){
                num_marbles -= moves[0];
            }
            else {
                num_marbles += moves[0];
            }
        }
        if (num_marbles <= 0)
        {
            cout << "-1" << endl;
            return;
        }
    }
    answer.pop_back();
    cout << answer << endl;
}

void solve4(ll num_marbles, ll num_moves)
{
    ll moves[4];
    string answer = "";
    for (ll i = 0; i < num_moves; i++)
    {
        cin >> moves[0] >> moves[1] >> moves[2] >> moves[3];
        std::sort(moves, moves + 4);
        bool a, b, c, d;
        a = moves[0] % 2 == 0;
        b = moves[1] % 2 == 0;
        c = moves[2] % 2 == 0;
        d = moves[3] % 2 == 0;
        // cerr << big_even << ", " << small_even << endl;

        if (d)
        {
            answer += "Even ";
            if (!c)
            {
                num_marbles -= moves[2];
            }
            else if (!b)
            {
                num_marbles -= moves[1];
            }
            else if (!a)
            {
                num_marbles -= moves[0];
            }
            else
            {
                num_marbles += moves[0];
            }
        }
        else if (num_marbles > moves[3])
        {
            answer += "Even ";
            num_marbles -= moves[3];
        }
        else {
            answer += "Odd ";
            if(c){
                num_marbles -= moves[2];
            }
            else if(b){
                num_marbles -= moves[1];
            }
            else if(a){
                num_marbles -= moves[0];
            }
            else{
                num_marbles += moves[0];
            }
        }
        if (num_marbles <= 0)
        {
            cout << "-1" << endl;
            return;
        }
    }
    answer.pop_back();
    cout << answer << endl;
}

void solve()
{
    ll num_marbles, num_moves, num_types;
    cin >> num_marbles >> num_moves >> num_types;
    if (num_types == 1)
    {
        solve1(num_marbles, num_moves);
        return;
    }
    if (num_types == 2)
    {
        solve2(num_marbles, num_moves);
        return;
    }
    if (num_types == 3)
    {
        solve3(num_marbles, num_moves);
        return;
    }
    if (num_types == 4)
    {
        solve4(num_marbles, num_moves);
        return;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}
