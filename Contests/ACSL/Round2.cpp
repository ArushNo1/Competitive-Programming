#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

map<char, int> cmap = {
    {'R', 0},
    {'Y', 1},
    {'G', 2},
    {'B', 3},
};
class card {
    public:
    //-1 and * means wild
    int color;
    int number;
    char symbol;
    bool wild = false;
    string tostring;

    //constructor for a card, based on the string
    card(string init) {
        tostring = init;
        if (init.size() == 3) {
            color = cmap[init[0]];
            number = init[1] - '0';
            symbol = init[2];
        } else if (init.size() == 1) {
            wild = true;
            char c = init[0];
            if (c >= '0' && c <= '9') {
                color = -1;
                number = c - '0';
                symbol = '*';
            } else if (cmap.count(c)) {
                color = cmap[c];
                number = -1;
                symbol = '*';
            } else {
                color = -1;
                number = -1;
                symbol = c;
            }
        }
    };

    //custom function allowing the meaning of card1 == card2 to change
    //equivalent to defining a .equals() method
    bool operator==(const card &other) const {
        //number of matching attributes
        int count = 0;

        //if either is a wildcard wild is true
        bool wild = this->wild || other.wild;
        count += color == other.color && (color != -1);
        count += number == other.number && (number != -1);
        count += symbol == other.symbol && (symbol != '*');
        return (count == 2) || (wild && count >= 1);
    }
};
ostream &operator<<(ostream &os, const card &c) {
    os << c.tostring;
    return os;
}

//find the index of the first card that can be placed in any pile
//p is the pile that the card gets placed in
//the & on parameters means its passed by reference
inline int findmatch(card &p1, card &p2, vector<card> &hand, int &p) {
    for (int i = 0; i < hand.size(); i++) {
        if (p1 == hand[i]) {
            p = 1;
            return i;
        }
        if (p2 == hand[i]) {
            p = 2;
            return i;
        }
    }
    return -1;
}

//same thing for auxiliary placements when you have to match the pile
int findmatch(card &p, vector<card> &hand) {
    for (int i = 0; i < hand.size(); i++) {
        if (p == hand[i]) {
            return i;
        }
    }
    return -1;
}

string printResult(string pilesraw, string handraw, string drawPileraw) {
    //reading in the input from the strings
    string token;
    istringstream iss(pilesraw);
    iss >> token;
    card p1 = card(token);
    iss >> token;
    card p2 = card(token);

    //reading the cards into the vector (arraylist) hand
    vector<card> hand;
    iss = istringstream(handraw);
    for (int i = 0; i < 7; i++) {
        iss >> token;
        hand.push_back(card(token));
        //equivalent to token = sc.next(); hand.add(new Card(token));
    }

    //allows easy reading and removal of the top value in the card pile
    queue<card> drawPile;
    iss = istringstream(drawPileraw);
    while (iss >> token) {
        drawPile.push(card(token));
    }

    //keep going until no cards can be placed or the hand is empty (0 size)
    while (!hand.empty()) {
        int p;
        int index = findmatch(p1, p2, hand, p);
        if (index == -1) {
            //no card can be placed
            break;
        }
        //make the current pile either p1 or p2, based on what findmatch returned
        card current = (p == 1) ? p1 : p2;
        current = hand[index];

        //removes the card from the hand
        //equivalent to (hand.remove(index);)
        hand.erase(hand.begin() + index);

        //calls the auxiliary method when the pile is fixed
        index = findmatch(current, hand);
        while (index != -1) {
            //keep going until nothing can be placed anymore
            current = hand[index];
            hand.erase(hand.begin() + index);
            index = findmatch(current, hand);
        }

        //keep drawing cards until you have 7 again
        while (!drawPile.empty() && hand.size() < 7) {
            hand.push_back(drawPile.front()); //add the top card to the hand
            drawPile.pop(); //remove the top card from the pile
        }

        //updating the piles to the new variable
        if(p == 1) {
            p1 = current;
        } else {
            p2 = current;
        }   
    }

    //to_string allows integer to be converted to string
    return to_string(hand.size()) + " " + p1.tostring + " " + p2.tostring;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string piles;
    getline(cin, piles);

    string hand;
    getline(cin, hand);

    string drawPile;
    getline(cin, drawPile);

    string result = printResult(piles, hand, drawPile);

    cout << result << "\n";
}
