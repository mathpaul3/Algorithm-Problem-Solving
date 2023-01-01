#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, A, B, i;
long long beauty=0;
int *Arr, *Brr;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B;
    Arr = (int *)malloc(sizeof(int)*A);
    Brr = (int *)malloc(sizeof(int)*B);
    for (i=0; i<A; i++)
        cin >> Arr[i];
    for (i=0; i<B; i++)
        cin >> Brr[i];
    sort(Arr, Arr+A);
    sort(Brr, Brr+B);

    if (N%2 == 1) {
        beauty += Arr[--A];
        N--;
    }

    int t1, t2;
    for (i=0; i<N; i+=2)
    {
        t1=0, t2=0;
        if (A>1) t1 = Arr[A-1] + Arr[A-2];
        if (B>0) t2 = Brr[B-1];

        if (t1>t2) {
            beauty += t1;
            A -= 2;
        } else {
            beauty += t2;
            B--;
        }
    }

    cout << beauty;

    return 0;
}