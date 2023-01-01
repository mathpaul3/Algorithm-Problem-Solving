#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int good_cnt = 0;
    
    for (int i=0; i<N; i++) {
        int l=0, r=N-1;
        while(l<r) {
            int sum = A[l] + A[r];
            if (sum < A[i]) l++;
            else if (sum > A[i]) r--;
            else {
                if (l!=i && r!=i) {
                    good_cnt++;
                    break;
                }
                else if (l==i) l++;
                else if (r==i) r--;
            }
        }
    }

    cout << good_cnt << '\n';
    return 0;
}