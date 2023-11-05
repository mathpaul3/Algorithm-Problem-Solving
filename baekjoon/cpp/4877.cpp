#include <iostream>
#include <sstream>
using namespace std;

string s, val;
int N, j;
double baskets[10][11], p[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, s);
    stringstream ss(s);
    while (getline(ss, val, ' '))
        baskets[0][N++] = stoi(val);
    for (int i=0; i<N; i++)
        baskets[0][N] += baskets[0][i];

    for (int i=1; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> baskets[i][j];
            baskets[i][N] += baskets[i][j];
        }
    }

    p[0] = 1;
    cout << fixed;
    cout.precision(5);
    for (int i=0; i<N; i++) cout << p[i] << ' ';
    cout << '\n';
    for (int t=0; t<9; t++) {
        double pt[10];
        for (int i=0; i<N; i++) pt[i] = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                pt[j] += p[i]*(baskets[i][j]/baskets[i][N]);
        for (int i=0; i<N; i++) {
            cout << pt[i] << ' ';
            p[i] = pt[i];
        }
        cout << '\n';
    }

    return 0;
}