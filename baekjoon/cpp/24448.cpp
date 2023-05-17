#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int Q;
    stack<string> stack;
    cin >> Q;

    while (Q--) {
        string book;
        cin >> book;
        if (book[0]=='R') {
            cout << stack.top() << '\n';
            stack.pop();
        } else {
            stack.push(book);
        }
    }

    return 0;
}