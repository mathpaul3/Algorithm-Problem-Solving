#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, v1, v2;
        bool before[7]={0,1,0,0,0,0,0};
        char op1, op2;
        cin >> N;
        while (N--) {
            bool after[7]={0,};
            cin >> op1 >> v1 >> op2 >> v2;
            for (int i=0; i<7; i++) {
                if (before[i]) {
                    if (op1=='+') after[(i+v1)%7] = true;
                    else after[(i*v1)%7] = true;
                    if (op2=='+') after[(i+v2)%7] = true;
                    else after[(i*v2)%7] = true;
                }
            }
            for (int i=0; i<7; i++)
                before[i] = after[i];
        }
        if (before[0]) cout << "LUCKY\n";
        else cout << "UNLUCKY\n";
    }
    return 0;
}