#include <iostream>
using namespace std;

int main() {
    int N, prvd, curd, prvr, curr, arr[50]={0,};
    bool is_arithmetical = false;
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> arr[i];
    
    prvd = arr[1]-arr[0];
    prvr = (double)arr[1]/arr[0];
    for (int i=2; i<N; i++) {
        curd = arr[i]-arr[i-1];
        if (curd==prvd) is_arithmetical = true;
        prvd = curd;
    }
    cout << (is_arithmetical ? arr[N-1]+prvd : arr[N-1]*prvr) << '\n';
    return 0;
}