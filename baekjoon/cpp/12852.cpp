#include <iostream>
#include <queue>
using namespace std;

int prv[1000001]={0,};
queue<int> q;

void prnt(int X) {
    if (prv[X]==X) { cout << X << ' '; return; }
    prnt(prv[X]);
    cout << X << ' ';
}

int main() {
    int X, depth=-1;
    cin >> X;
    prv[X]=X; q.push(X);
    while (!q.empty()) {
        depth++;
        int sz=q.size();
        bool found=false;
        for (int i=0; i<sz; i++) {
            int front = q.front(); q.pop();
            if (front == 1) {found=true; break;}
            if (!(front%3) && !prv[front/3]) {prv[front/3]=front; q.push(front/3);}
            if (!(front%2) && !prv[front/2]) {prv[front/2]=front; q.push(front/2);}
            if (!prv[front-1]) {prv[front-1]=front; q.push(front-1);}
        }
        if (found) break;
    }
    cout << depth << '\n';
    prnt(1);
    return 0;
}