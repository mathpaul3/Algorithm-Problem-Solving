#include <iostream>
using namespace std;

int N, K, B, i;
int arr[101];
long long int sum=0;

int main() {
    cin >> N >> K >> B;

    int s=B%N-1;
    for (i=0; i<N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum = sum*(K/N);
    for (i=0; i<K%N; i++)
    {
        sum += arr[(s+i)%N];
    }
    cout << sum;

    return 0;
}