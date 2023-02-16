#include <iostream>
using namespace std;

int N, value[100000]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) cin >> value[i];
    int l=0, r=N-1, sum=1, min_l, min_r, diff_min=0x7FFFFFFF;
    while (l<r) {
        sum = value[l]+value[r];
        if (sum==0) {min_l=l, min_r=r; break;}
        if (sum<0) {
            if (-sum<diff_min) {
                diff_min = -sum;
                min_l=l, min_r=r;
            }
            l++;
        } else {
            if (sum<diff_min) {
                diff_min = sum;
                min_l=l, min_r=r;
            }
            r--;
        }
    }
    cout << value[min_l] << ' ' << value[min_r] << '\n';

    return 0;
}