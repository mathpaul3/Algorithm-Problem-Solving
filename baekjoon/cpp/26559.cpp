#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    while (n--) {
        pair<int,string> friends[500];
        cin >> m;
        for (int i=0; i<m; i++)
            cin >> friends[i].second >> friends[i].first;
        sort(friends, friends+m);
        for (int i=m-1; i>=0; i--)
            cout << friends[i].second << (i ? ", " : "\n");
    }
    return 0;
}