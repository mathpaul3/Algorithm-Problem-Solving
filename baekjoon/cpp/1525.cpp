#include <iostream>
#include <queue>
#include <set>
using namespace std;

queue<unsigned int> possible;
set<unsigned int> visited;
int movable[9][4]={
    {1,3,-1,-1},
    {0,2,4,-1},
    {1,5,-1,-1},
    {0,4,6,-1},
    {1,3,5,7},
    {2,4,8,-1},
    {3,7,-1,-1},
    {4,6,8,-1},
    {5,7,-1,-1}
};

int main() {
    short number;
    unsigned int cur=0, cnt=0, ORGANIZED=0b01110110010101000011001000010000;
    for (int i=0; i<9; i++) {
        cin >> number;
        if (number) cur += (i << ((number-1)*4));
    }
    if (cur==ORGANIZED) { cout << 0 << '\n'; return 0; }
    possible.push(cur);
    visited.insert(cur);
    while (!possible.empty()) {
        int sz = possible.size();
        for (int t=0; t<sz; t++) {
            unsigned int prv = possible.front(); possible.pop();
            short zero=0;

            for (int i=0; i<8; i++)
                zero += ((prv & (0xF << (i*4))) >> (i*4));
            zero = 36 - zero;
            for (int i=0; i<4; i++) {
                if (movable[zero][i]!=-1) {
                    for (int j=0; j<8; j++) {
                        if (movable[zero][i]==((prv & (0xF << (j*4))) >> (j*4))) {
                            cur = prv - (prv & (0xF << j*4)) + (zero << (j*4));
                            if (cur==ORGANIZED) {
                                cout << cnt+1 << '\n';
                                return 0;
                            }
                            if (visited.find(cur)==visited.end()) {
                                possible.push(cur);
                                visited.insert(cur);
                            }
                            break;
                        }
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1 << '\n';
    return 0;
}