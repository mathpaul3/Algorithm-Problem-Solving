#include <iostream>
using namespace std;

int main() {
    int K;
    string s;
    cin >> K;
    K++;
    while (K) {
        s = ((K&1)==1 ? "7":"4") + s;
        K >>= 1;
    }
    cout << s.substr(1) << '\n';
    
    return 0;
}