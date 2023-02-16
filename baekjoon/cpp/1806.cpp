#include <iostream>
using namespace std;

int N, S, arr[100001]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> arr[i];
    int l=0, r=0, len=N+1, sum=arr[0];
    while (l<=r && r<N) {
        if (sum < S) sum += arr[++r];
        else {
            len = min(len, r-l+1);
            sum -= arr[l++];
        }
    }
    if (len==N+1) len=0;
    cout << len << '\n';
    return 0;
}