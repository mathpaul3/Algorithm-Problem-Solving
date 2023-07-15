#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, t, T;
    string command, ans="";
    char c;
    stack<tuple<bool,int,int> > s;
    cin >> N;
    while (N--) {
        cin >> command;
        if (command[0]=='t') {
            cin >> c >> T;
            s.push(make_tuple(false,c,T));
        } else {
            cin >> t >> T;
            s.push(make_tuple(true,t,T));
        }
    }
    while (!s.empty()) {
        bool cmd;
        tie(cmd, t, T) = s.top();
        if (cmd) {
            while (!s.empty() && get<2>(s.top())>=(T-t))
                s.pop();
        } else {
            ans = (char)(t) + ans;
            s.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}