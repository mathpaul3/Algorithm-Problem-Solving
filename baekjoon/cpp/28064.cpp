#include <iostream>
using namespace std;

int N;
string name[100];
bool connectable[100][100]={0,};

void check(int a, int b) {
    int sza=name[a].size(), szb=name[b].size();

    // a...b
    for (int i=sza-1; i>=0; i--) {
        if (name[a][i]==name[b][0]) {
            bool cnctbl = true;
            for (int j=0; j+i<sza; j++) {
                if (name[a][i+j]!=name[b][j]) {
                    cnctbl = false;
                    break;
                }
            }
            if (cnctbl) {
                connectable[a][b] = true;
                return;
            }
        }
    }

    // b...a
    for (int i=szb-1; i>=0; i--) {
        if (name[b][i]==name[a][0]) {
            bool cnctbl = true;
            for (int j=0; j+i<szb; j++) {
                if (name[b][i+j]!=name[a][j]) {
                    cnctbl = false;
                    break;
                }
            }
            if (cnctbl) {
                connectable[a][b] = true;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> name[i];
        for (int j=0; j<i; j++) {
            check(i, j);
        }
    }

    int cnt=0;
    for (int i=0; i<N; i++)
        for (int j=0; j<i; j++)
            if (connectable[i][j]) cnt++;
    cout << cnt << '\n';

    return 0;
}