#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    char N[11]={0,}, len=0;
    cin >> N;
    for (int i=0; N[i]; i++) len++;
    sort(N, N+len, greater<>());
    cout << N << '\n';
    return 0;
}