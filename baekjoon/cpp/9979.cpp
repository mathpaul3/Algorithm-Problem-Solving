#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N=0, day, weight;
    string name;
    pair<int,string> people[100];
    while (cin >> name) {
        if (name=="START") continue;
        if (name=="END") {
            sort(people, people+N);
            for (int i=N-1; i>=0; i--)
                cout << people[i].second << '\n';
            cout << '\n';
            N = 0;
        } else {
            cin >> day >> weight;
            people[N++] = make_pair(weight-day, name);
        }
    }
    return 0;
}