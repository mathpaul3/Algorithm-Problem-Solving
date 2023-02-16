#include <iostream>
#include <stack>
using namespace std;

string command;
int N, num;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> command;
        if (command[0] == 't') cout << (s.empty() ? -1 : s.top());
        else if (command[0] == 'e') cout << s.empty();
        else if (command[0] == 's') cout << s.size();
        else if (command[1] == 'u') { cin >> num; s.push(num); continue; }
        else {
            if (s.empty()) cout << -1;
            else { cout << s.top(); s.pop(); }
        }
        cout << '\n';
    }

    return 0;
}