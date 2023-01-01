#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int first, second;
    while (true) {
        cin >> first >> second;
        if (!(first && second))
            break;
        cout << (first > second ? "Yes" : "No") << '\n';
    }

    return 0;
}