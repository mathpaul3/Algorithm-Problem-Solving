#include <iostream>
#include <algorithm>
using namespace std;

int n=0, opinion[300300]={0,}, trimmed_mean=0;
double mean=0, difficulty=0;

int rnd(double num) {
    int inum = num/1;
    if ((num-inum) >= 0.5) return inum+1;
    else return inum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    trimmed_mean = rnd((double)n*0.15);
    for (int i=0; i<n; i++)
        cin >> opinion[i];
    sort(opinion, opinion+n);
    for (int i=trimmed_mean; i<n-trimmed_mean; i++)
        mean += opinion[i];
    n -= trimmed_mean*2;
    if (n==0) n = 1;
    mean = rnd(mean/(double)n);
    cout << mean << '\n';
    return 0;
}