#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, prv, cur, local=1, longest=1;
    cin >> n >> k;
    cin >> prv;
    while (--n) {
        cin >> cur;
        if (cur==prv) local=1;
        else if (++local>longest) longest = local;
        prv = cur;
    }
    cout << longest << '\n';
    return 0;
}