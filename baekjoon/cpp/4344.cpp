#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int C;
    cin >> C;
    while (C--) {
        int N, score[1000], sum=0, cnt=0;
        double mean, ans;
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> score[i];
            sum += score[i];
        }
        mean = (double)sum/N;
        sort(score, score+N);
        for (int i=0; i<N; i++)
            if (score[i]>mean)
                cnt++;
        ans = (double)cnt*100/N;
        if ((int)(ans*10000)%10==5) ans = (double)((int)(ans*1000)+1)/1000;
        cout << fixed;
        cout.precision(3);
        cout << ans << "%\n";
    }
    return 0;
}