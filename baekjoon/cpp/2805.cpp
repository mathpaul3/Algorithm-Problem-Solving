#include <iostream>
#include <algorithm>
using namespace std;

int N, M, wood[1000000]={0,};

int find(int left, int right) {
    if (left==right) return right;
    long long sum=0;
    int mid = (left+right)/2;
    for (int i=0; i<N; i++) {
        if (mid<wood[i]) sum += wood[i]-mid;
    }
    if (sum<M) return find(left, mid);
    else return find(mid+1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> wood[i];
    sort(wood, wood+N);

    cout << find(0, wood[N-1])-1 << '\n';

    return 0;
}