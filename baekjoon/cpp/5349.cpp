#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string number;
    set<string> num, dup;
    while (cin >> number) {
        if (number == "000-00-0000") break;
        if (num.find(number)==num.end()) num.insert(number);
        else dup.insert(number);
    }
    for (auto it=dup.begin(); it!=dup.end(); it++) {
        cout << (*it) << '\n';
    }
    return 0;
}