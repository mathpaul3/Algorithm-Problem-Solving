#include <iostream>
using namespace std;

int check(int n)
{
    int six=0, nsix=0, div=100000000;
    for (; n>0; div/=10)
    {
        if (six == 3)
            nsix++;
        else if (n/div == 6)
            six++;
        else
            six=0;

        n %= div;
    }
    return nsix;
}

int pow(int a, int b)
{
    int ret=1;
    while(b--)
    {
        ret *= a;
    }
    return ret;
}

int main() {
    int N, c, num=666;
    cin >> N;
    
    for (int n=0; n<N;)
    {
        c = pow(10, check(num));
        if (n+c<N) {
            n += c;
        } else if (n+c >= N) {
            cout << (num/c)*c + (N-n-1);
            return 0;
        }
        num += 1000;
    }

    return 0;
}