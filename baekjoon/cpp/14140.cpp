#include <iostream>
using namespace std;

int main() {
    int L, K, mirko_x=0, mirko_y=0, slavko_x=0, slavko_y=0, chat=0;
    string path;
    cin >> L >> path;
    cin >> K;
    for (int i=0; i<L-1; i++) {
        switch(path[i]) {
            case 'L': mirko_x--; break;
            case 'R': mirko_x++; break;
            case 'U': mirko_y++; break;
            case 'D': mirko_y--; break;
        }
        if (i>=K) {
            switch(path[i-K]) {
            case 'L': slavko_x--; break;
            case 'R': slavko_x++; break;
            case 'U': slavko_y++; break;
            case 'D': slavko_y--; break;
        }
        }
        if (i>=K-1 &&
            -2<mirko_x-slavko_x && mirko_x-slavko_x<2 &&
            -2<mirko_y-slavko_y && mirko_y-slavko_y<2)
            chat++;
    }
    cout << chat << '\n';
    return 0;
}