#include <iostream>
using namespace std;

int N, S, nums[20]={0,}, cnt=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for (int i=0; i<N; i++)
        cin >> nums[i];

    int sz=(1<<N);
    for (int i=1; i<sz; i++) {
        int length=0, sum=0;
        while ((1<<length)<=i) {
            if ((i/(1<<length))%2) sum += nums[length];
            if ((1<<length)==i) break;
            length++;
        }
        if (sum == S) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}