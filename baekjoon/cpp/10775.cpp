#include <iostream>
using namespace std;

int G, P, g[100001], gi, flag=0, cnt=0;
bool f=false;

int docking(int num) {
    if (g[num] == 0) return 0;
    if (g[num] == num) {g[num]--; return num-1;}
    else return g[num] = docking(g[num]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=1; i<100002; i++)
        g[i] = i;

    cin >> G >> P;
    for (int i=0; i<P; i++) {
        cin >> gi;
        if (f) continue;
        if (docking(gi)) cnt++;
        else if (!flag) {cnt++; flag++;}
        else {f=true;}
    }
    cout << cnt << '\n';
    return 0;
}