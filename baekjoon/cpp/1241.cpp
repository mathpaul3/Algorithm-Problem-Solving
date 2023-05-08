#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, student[100000]={0,}, number[1000001]={0,};
    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> student[i];
        number[student[i]]++;
    }
    for (int i=0; i<N; i++) {
        int n=student[i], cnt=0;
        for (int j=1; j*j<=n; j++) {
            if (!(n%j)) {
                if (n/j != j)
                    cnt += number[n/j];
                cnt += number[j];
            }
        }
        cout << cnt-1 << '\n';
    }

    return 0;
}