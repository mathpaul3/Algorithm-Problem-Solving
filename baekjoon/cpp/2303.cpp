#include <iostream>
using namespace std;

int N, max_num=0, max_N=0;
int cards[5]={0,};

int main() {
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++)
            cin >> cards[j];
        for (int j=0; j<3; j++) {
        for (int k=j+1; k<4; k++) {
        for (int l=k+1; l<5; l++) {
            short remain = cards[j]+cards[k]+cards[l];
            if (remain%10 >= max_num) {
                max_num = remain%10;
                max_N = i;
            }
        }}}
    }
    cout << max_N+1 << '\n';
    return 0;
}