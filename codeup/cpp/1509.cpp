#include <iostream>
using namespace std;

int obstacle[10]={0,};

int main() {
    int map;
    for (int i=0; i<100; i++) {
        cin >> map;
        if (map!=0)
            obstacle[i%10] = map;
    }
    for (int i=0; i<10; i++) {
        cin >> map;
        if (map!=0) {
            cout << i+1 << ' ';
            if (obstacle[i]>0) cout << "crash\n";
            else if (obstacle[i]<0) cout << "fall\n";
            else cout << "safe\n";
        }
    }
    return 0;
}