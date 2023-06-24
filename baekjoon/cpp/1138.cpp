#include <iostream>
using namespace std;

int N, remember, arr[10]={0,};

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        int cnt=0;
        cin >> remember;
        while (remember>-1) {
            if (!arr[cnt++]) remember--;
        }
        arr[--cnt] = i;
    }
    
    for (int i=0; i<N; i++) cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}