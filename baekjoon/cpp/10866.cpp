#include <iostream>
#include <deque>
using namespace std;

deque<int> d;
string command;
int N, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> command;
        if (command[0] == 'f') cout << (d.empty() ? -1 : d.front());
        else if (command[0] == 'b') cout << (d.empty() ? -1 : d.back());
        else if (command[0] == 'e') cout << d.empty();
        else if (command[0] == 's') cout << d.size();
        else if (command[4] == 'f') {
            if (d.empty()) cout << -1;
            else {cout << d.front(); d.pop_front();}
        }
        else if (command[4] == 'b') {
            if (d.empty()) cout << -1;
            else {cout << d.back(); d.pop_back();}
        }
        else if (command[5] == 'f') {cin >> num; d.push_front(num); continue;}
        else {cin >> num; d.push_back(num); continue;}
        cout << '\n';
    }
    return 0;
}
