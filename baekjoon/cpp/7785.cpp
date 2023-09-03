#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    string name, log;
    set<string> people;
    cin >> n;
    while (n--) {
        cin >> name >> log;
        if (log[0]=='e') people.insert(name);
        else people.erase(name);
    }
    for (auto it=--people.end(); ; it--) {
        cout << (*it) << '\n';
        if (it==people.begin()) break;
    }
    return 0;
}