#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int Q, ball=0, wall=0;
    short direction=0;
    deque<bool> dq;
    string command;
    char param;
    cin >> Q;
    while (Q--) {
        cin >> command;
        switch (command[2]) {
            case 's':
                cin >> param;
                dq.push_back(param=='b');
                (param=='b' ? (ball++):(wall++));
                break;
            case 'p':
                if (!dq.empty()) {
                    (dq.front() ? (ball--) : (wall--));
                    dq.pop_front();
                }
                break;
            case 't':
                cin >> param;
                if (param=='l') {
                    if (direction==0) direction = 3;
                    else direction--;
                } else direction = (direction+1)%4;
                break;
            case 'u':
                cin >> param;
                cout << (param=='b' ? ball : wall) << '\n';
                break;
        }
        if (direction==1) {
            while (!dq.empty() && dq.front()) {
                ball--;
                dq.pop_front();
            }
        } else if (direction==3) {
            while (!dq.empty() && dq.back()) {
                ball--;
                dq.pop_back();
            }
        }
        if (!dq.empty()) {
            for (auto f=dq.begin(); f!=dq.end(); f++) {
                cout << *f << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}