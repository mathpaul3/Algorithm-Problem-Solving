#include <iostream>
#include <queue>
using namespace std;

string command;
int N, num;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> command;
        if (command[0] == 'f') cout << (q.empty() ? -1 : q.front());
        else if (command[0] == 'b') cout << (q.empty() ? -1 : q.back());
        else if (command[0] == 'e') cout << q.empty();
        else if (command[0] == 's') cout << q.size();
        else if (command[1] == 'u') { cin >> num; q.push(num); continue; }
        else {
            if (q.empty()) cout << -1;
            else { cout << q.front(); q.pop(); }
        }
        cout << '\n';
    }

    return 0;
}