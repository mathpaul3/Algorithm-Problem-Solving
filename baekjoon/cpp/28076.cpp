#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, multitap[200000]={0,};
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> multitap[i];
    }
    sort(multitap, multitap+N);
    if (N==1) cout << multitap[0];
    else if (N==2) cout << multitap[0]+multitap[1]-1;
    else cout << multitap[N-1]+multitap[N*2/3-1]+multitap[N/3-1]-3;
    cout << '\n';
    return 0;
}

