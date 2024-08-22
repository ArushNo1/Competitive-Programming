/*
ID: 1026840
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int initial_bronze, final_bronze, initial_silver, final_silver, initial_gold, final_gold, initial_platinum, final_platinum;
    cin >> initial_bronze >> final_bronze >> initial_silver >> final_silver >> initial_gold >> final_gold >> initial_platinum >> final_platinum;

    int promoters_into_silver, promoters_into_gold, promoters_into_platinum = final_platinum - initial_platinum;

    promoters_into_gold = final_gold + promoters_into_platinum - initial_gold;
    promoters_into_silver = final_silver + promoters_into_gold - initial_silver;
    cout << promoters_into_silver << "\n" << promoters_into_gold << "\n" << promoters_into_platinum << endl;



}
