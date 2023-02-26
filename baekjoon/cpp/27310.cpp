#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int underbar=0, sz=s.size();
    for (int i=6; i<sz; i++)
        if (s[i]=='_') underbar++;
    cout << sz+2+underbar*5 << '\n';

    return 0;
}