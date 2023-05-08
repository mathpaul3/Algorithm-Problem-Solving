#include <iostream>
#include <tuple>
using namespace std;

int main() {
    long long N, f1=1000000, f2=2000000, f3=3000000;
    int face[6]={0,};
    cin >> N;

    int M=0, sum=0;
    for (int i=0; i<6; i++) {
        cin >> face[i];
        if (face[i]<f1) f1 = face[i];
        if (face[i]>M) M = face[i];
        sum += face[i];
    }
    if (N==1) {
        cout << sum-M << '\n';
        return 0;
    }

    pair<int,int> f2_case[12] = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4},
        {1, 2}, {1, 3}, {1, 5}, {2, 4},
        {2, 5}, {3, 4}, {3, 5}, {4, 5}
    };
    for (int i=0; i<12; i++) {
        if (face[f2_case[i].first]+face[f2_case[i].second] < f2)
            f2 = face[f2_case[i].first]+face[f2_case[i].second];
    }

    tuple<int,int,int> f3_case[8] = {
        {0, 1, 2}, {0, 2, 4}, {0, 4, 3}, {0, 3, 1},
        {5, 1, 2}, {5, 2, 4}, {5, 4, 3}, {5, 3, 1}
    };
    for (int i=0; i<8; i++) {
        int f, s, t;
        tie(f, s, t) = f3_case[i];
        if (face[f]+face[s]+face[t] < f3)
            f3 = face[f]+face[s]+face[t];
    }
    
    cout << f1*(5*N*N-16*N+12)+f2*(8*N-12)+f3*(4) << '\n';
    return 0;
}