#include <iostream>
using namespace std;

int N, f1, f2;
bool finger[6][6];

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> f1 >> f2;
        finger[f1][f2] = true;
        finger[f2][f1] = true;
    }
    
    if (N==3 && finger[1][3] && finger[3][4] && finger[1][4])
        cout << "Wa-pa-pa-pa-pa-pa-pow!\n";
    else cout << "Woof-meow-tweet-squeek\n";

    return 0;
}