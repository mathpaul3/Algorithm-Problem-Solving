#include <iostream>
#include <queue>
using namespace std;

short R, C, mv[4]={0,0,-1,1};
char lake[1500][1500]={0,};
pair<short,short> swan1={-1,-1}, swan2={-1, -1};
pair<short,short> space[1500][1500];
queue<pair<short,short> > q;

bool check_range(short i, short j) {
    return (0<=i && i<R && 0<=j && j<C);
}

void BFS(int i, int j) {
    queue<pair<short,short> > bfsq;
    bfsq.push(make_pair(i, j));
    space[i][j] = make_pair(i, j);
    while (!bfsq.empty()) {
        short y = bfsq.front().first, x = bfsq.front().second;
        bfsq.pop();
        if (lake[y][x] == 'L') {
            if (swan1.first==-1) swan1 = make_pair(y, x);
            else swan2 = make_pair(y, x);
        }
        bool contact = false;
        for (short k=0; k<4; k++) {
            short yy = y+mv[k], xx = x+mv[(k+2)%4];
            if (check_range(yy, xx)) {
                if (lake[yy][xx]!='X' && space[yy][xx].first==-1) {
                    bfsq.push(make_pair(yy, xx));
                    space[yy][xx] = make_pair(i, j);
                } else if (lake[yy][xx]=='X') contact = true;
            }
        }
        if (contact) q.push(make_pair(y, x));
    }
}

pair<short,short> root(pair<short,short> loc) {
    pair<short,short> p = space[loc.first][loc.second];
    if (p == loc) return p;
    return space[loc.first][loc.second] = root(p);
}

void merge(pair<short,short> p1, pair<short,short> p2) {
    p1 = root(p1), p2 = root(p2);
    if (p1 == p2) return;
    pair<short,short> tmp;
    if (p1>p2) {tmp = p1; p1 = p2; p2 = tmp;}
    space[p2.first][p2.second] = space[p1.first][p1.second];
}

void melt() {
    int sz = q.size();
    for (int i=0; i<sz; i++) {
        short y = q.front().first, x = q.front().second;
        q.pop();
        for (int j=0; j<4; j++) {
            short yy = y+mv[j], xx = x+mv[(j+2)%4];
            if (check_range(yy, xx)) {
                if (lake[yy][xx]=='X') {
                    lake[yy][xx] = '.';
                    q.push(make_pair(yy, xx));
                    space[yy][xx] = space[y][x];
                    for (int k=0; k<4; k++) {
                        pair<short,short> none={-1,-1};
                        short yyy = yy+mv[k], xxx = xx+mv[(k+2)%4];
                        if (check_range(yyy, xxx) && space[yyy][xxx]!=none && space[yy][xx]!=none)
                            merge(space[yyy][xxx], space[yy][xx]);
                    }
                } else merge(space[yy][xx], space[y][x]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (short i=0; i<R; i++) {
        for (short j=0; j<C; j++) {
            cin >> lake[i][j];
            space[i][j] = make_pair(-1, -1);
        }
    }
    
    // Initialize
    for (short i=0; i<R; i++)
        for (short j=0; j<C; j++)
            if (lake[i][j]!='X' && space[i][j].first==-1)
                BFS(i, j);

    // Simulate
    short day=0;
    while (true) {
        melt();
        day++;
        swan1 = root(swan1), swan2 = root(swan2);
        if (swan1 == swan2) {
            cout << day << '\n';
            break;
        }
    }
    return 0;
}