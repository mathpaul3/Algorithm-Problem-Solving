#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int n=0;
        for (int i=1; ; i++) {
            if (n+i < num) n += i;
            else {
                cout << "TERM " << num << " IS " << (i%2 ? i+1 - (num-n) : num-n) << "/" << (i%2 ? num-n : i+1 - (num-n)) << '\n';
                break;
            }
        }
    }
    return 0;
}