#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int *matrix = new int[N*M], mi;
    int NM = N*M;
    for (int i=0; i<NM; i++) {
        cin >> matrix[i];
    }
    for (int i=0; i<NM; i++) {
        cin >> mi;
        matrix[i] += mi;
    }

    for (int i=0; i<NM; i++) {
        cout << matrix[i] << ((i+1)%N ? ' ' : '\n');
    }

    return 0;
}