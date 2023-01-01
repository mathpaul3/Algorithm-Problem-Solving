#include <iostream>
#include <climits>
using namespace std;

int N, M, B, temp, tmin=INT_MAX, ans;
int y[260][2];
// y[i][0] 시간
// y[i][1] 개수

int main() {
    cin >> N >> M >> B;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> temp;
            for (int k=0; k<=256; k++)
            {
                y[k][0] += (k < temp) ? (temp-k)*2 : (k-temp);
                y[k][1] += (temp-k);
            }
        }
    }

    for (int i=0; i<=256; i++)
    {
        if (y[i][0] <= tmin && 0<=y[i][1]+B)
        {
            tmin = y[i][0];
            ans = i;
        }
    }

    cout << tmin << " " << ans;
    return 0;
}