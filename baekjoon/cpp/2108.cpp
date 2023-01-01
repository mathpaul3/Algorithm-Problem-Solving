#include <iostream>
using namespace std;


int N, tmp, mid=0, arr[8080]={0, }, m=5000, M=-5000, mode=-1, modei, Mode=0, Modei;
double sum;

int main() {
    cin >> N;
    
    for (int i=0; i<N; i++)
    {
        cin >> tmp;
        
        sum += tmp;
        if (tmp<m) m = tmp;
        if (tmp>M) M = tmp;

        arr[tmp+4000]++;
    }

    tmp = 0;
    for (int i=-4000; i<4001; i++)
    {
        if (arr[i+4000])
        {
            if (tmp*2 <= N+1)
            {
                tmp += arr[i+4000];
                if (!mid && tmp*2 > N)
                    mid = i;
            }

            if (arr[i+4000] > Mode)
            {
                Mode = arr[i+4000];
                Modei = i;
            }
            else if (arr[i+4000] == Mode && Mode != mode)
            {
                mode = arr[i+4000];
                modei = i;
            }
        }

    }

    cout << fixed;
    cout.precision(0);
    cout << sum/N << endl;
    cout << mid << endl;
    cout << (mode == Mode ? modei : Modei) << endl;
    cout << M-m;
    return 0;
}