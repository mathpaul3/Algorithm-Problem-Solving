#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int dice[3], money;
    cin >> dice[0] >> dice[1] >> dice[2];
    sort(dice, dice+3);
    if (dice[0] == dice[2]) money = 10000 + dice[0]*1000;
    else if (dice[0]!=dice[1] && dice[1]!=dice[2]) money = dice[2]*100;
    else money = 1000 + dice[1]*100;
    cout << money << '\n';
    return 0;
}