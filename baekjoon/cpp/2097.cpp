#include <iostream>
using namespace std;

int main() {
    long long N, height=1, width=1;
    cin >> N;
    while ((height+1)*(width+1)<N) {
        if (height==width) height++;
        else width++;
    }
    cout << (height+width)*2 << '\n';
    return 0;
}