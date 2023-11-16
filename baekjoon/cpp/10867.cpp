#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    set<int> s;
    int N, number;
    cin >> N;
    while (N--) {
        cin >> number;
        s.insert(number);
    }
    for (auto it=s.begin(); it!=s.end(); it++)
        cout << (*it) << ' ';
    return 0;
}