#include <iostream>
using namespace std;

int n;
pair<int,int> truthteller[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        truthteller[a].first++;
        truthteller[b].second++;
    }
    int cumsum=0, maximum=-1;
    for (int i=0; i<=n; i++) {
        cumsum += truthteller[i].first;
        if (cumsum==i) maximum = i;
        cumsum -= truthteller[i].second;
    }
    cout << maximum << '\n';
    return 0;
}