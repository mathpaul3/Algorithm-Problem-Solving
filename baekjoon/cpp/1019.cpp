#include <iostream>
using namespace std;

long long N, div_=1, len=0;
long long numnum[10]={0,};
char num[10]={0,};

void count(int idx) {
    for (int i=0; i<10; i++) {
        numnum[i] += (N/(div_*10)+(i<num[idx]))*div_;
        if (i==num[idx]) numnum[i] += (N%div_+1);
        if (!i) numnum[i] -= div_;
    }
}

int main() {
    cin >> N;
    for (int i=0; i<10; i++) {
        num[i] = (N/div_)%10;
        div_ *= 10; len++;
        if (div_ > N) break;
    }

    div_ = 1;
    for (int i=0; i<len; i++) {
        count(i); div_ *= 10;
    }

    for (int i=0; i<10; i++)
        cout << numnum[i] << ' ';
    return 0;
}