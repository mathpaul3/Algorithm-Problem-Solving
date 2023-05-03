#include <iostream>
using namespace std;

int main() {
    long long N, file_sz, cluster_sz, sum=0;
    long long file[50];
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> file[i];
    }
    cin >> cluster_sz;

    for (int i=0; i<N; i++)
        sum += (file[i]%cluster_sz ? cluster_sz*(file[i]/cluster_sz + 1) : cluster_sz*(file[i]/cluster_sz));
    cout << sum << '\n';
    return 0;
}