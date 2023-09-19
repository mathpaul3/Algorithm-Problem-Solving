#include <iostream>
using namespace std;

int main() {
    string ah, ahah;
    cin >> ah >> ahah;
    cout << (ah.size()<ahah.size() ? "no\n" : "go\n");
    return 0;
}