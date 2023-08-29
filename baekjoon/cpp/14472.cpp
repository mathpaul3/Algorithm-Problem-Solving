#include <iostream>
using namespace std;

char area[100][100]={0,};

int main() {
    int N, M, D, cnt=0, continuous=0;
    cin >> N >> M >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> area[i][j];
            if (area[i][j]=='.') continuous++;
            else {
                cnt += (continuous-D+1 > 0 ? continuous-D+1 : 0);
                continuous = 0;
            }
        }
        cnt += (continuous-D+1 > 0 ? continuous-D+1 : 0);
        continuous = 0;
    }
    cnt += (continuous-D+1 > 0 ? continuous-D+1 : 0);
    continuous = 0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (area[j][i]=='.') continuous++;
            else {
                cnt += (continuous-D+1 > 0 ? continuous-D+1 : 0);
                continuous = 0;
            }
        }
        cnt += (continuous-D+1 > 0 ? continuous-D+1 : 0);
        continuous = 0;
    }
    cout << cnt << '\n';
    return 0;
}