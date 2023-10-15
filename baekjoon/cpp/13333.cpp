#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, i, paper[1000]={0,};
    cin >> n;
    for (int i=0; i<n; i++) cin >> paper[i];
    sort(paper, paper+n);

    for (i=n-1; i>=0 && paper[i]>=(n-i); i--) {}
    cout << n-(++i) << '\n';
    return 0;
}