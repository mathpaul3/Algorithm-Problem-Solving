#include <iostream>
#include <set>
#include <string.h>
using namespace std;

int R, C, T;
int upper_purifier=0, lower_purifier;
int mv[4] = {-1, 1, 0, 0};
set<pair<int,int> > dusts;

void diffuse(int A[][51], int result[][51]) {
    for (int i=0; i<R; i++)
        memset(result[i], 0, sizeof(int)*C);
    set<pair<int,int> > dust;

    // 확산 및 이동
    for (auto it=dusts.begin(); it!=dusts.end(); it++) {
        int y = (*it).first, x = (*it).second;

        int diff = A[y][x] / 5;

        if (diff) {
            for (int i=0; i<4; i++) {
                int cur_y = y+mv[i], cur_x = x+mv[(i+2)%4];
                if (0 <= cur_y && cur_y < R && 0 <= cur_x && cur_x < C) {
                    // 가로 이동
                    if ((cur_y == 0 || cur_y == (R-1)) && 0 < cur_x) {
                        result[cur_y][cur_x-1] += diff;
                        A[y][x] -= diff;
                        dust.insert(make_pair(cur_y, cur_x-1));
                    } else if ((cur_y == upper_purifier || cur_y == lower_purifier) && cur_x < (C-1)) {
                        if (cur_x) {
                            result[cur_y][cur_x+1] += diff;
                            A[y][x] -= diff;
                            dust.insert(make_pair(cur_y, cur_x+1));
                        }
                    }
                    // 세로 이동
                    else if ((cur_x == 0 && cur_y < upper_purifier) ||
                            (cur_x == (C-1) && upper_purifier < cur_y)) {
                        result[cur_y+1][cur_x] += diff;
                        A[y][x] -= diff;
                        if (cur_y+1 != upper_purifier)
                            dust.insert(make_pair(cur_y+1, cur_x));
                    } else if ((cur_x == (C-1) && cur_y < lower_purifier) ||
                            (cur_x == 0 && lower_purifier < cur_y)) {
                        result[cur_y-1][cur_x] += diff;
                        A[y][x] -= diff;
                        if (cur_y-1 != lower_purifier) {
                            dust.insert(make_pair(cur_y-1, cur_x));
                        }
                    }
                    // 일반
                    else {
                        result[cur_y][cur_x] += diff;
                        A[y][x] -= diff;
                        dust.insert(make_pair(cur_y, cur_x));
                    }
                }
            }
        }

        
        // 가로 이동
        if ((y == 0 || y == (R-1)) && 0 < x) {
            result[y][x-1] += A[y][x];
            dust.insert(make_pair(y, x-1));
        } else if ((y == upper_purifier || y == lower_purifier) && 0 < x && x < (C-1)) {
            result[y][x+1] += A[y][x];
            dust.insert(make_pair(y, x+1));
        }
        // 세로 이동
        else if ((x == 0 && y < upper_purifier) || (x == (C-1) && upper_purifier < y)) {
            result[y+1][x] += A[y][x];
            if (y+1 != upper_purifier) dust.insert(make_pair(y+1, x));
        } else if ((x == 0 && lower_purifier < y) || (x == (C-1) && y < lower_purifier)) {
            result[y-1][x] += A[y][x];
            if (y-1 != lower_purifier) dust.insert(make_pair(y-1, x));
        }
        // 일반
        else {
            result[y][x] += A[y][x];
            dust.insert(make_pair(y, x));
        }
    }
    result[upper_purifier][0] = -1;
    result[lower_purifier][0] = -1;

    dusts = dust;

    for (int i=0; i<R; i++)
        memcpy(A[i], result[i], sizeof(int)*C);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> T;

    int A[51][51], result[51][51];

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> A[i][j];
            if (A[i][j]) {
                if (A[i][j] == -1) {
                    if (!upper_purifier) upper_purifier = i;
                    else lower_purifier = i;
                } else
                    dusts.insert(make_pair(i, j));
            }
        }
    }

    for (int i=0; i<T; i++) {
        diffuse(A, result);
    }

    int sum = 0;
    for (auto it=dusts.begin(); it!=dusts.end(); it++) {
        pair<int,int> d = *it;
        sum += A[d.first][d.second];
    }

    cout << sum << '\n';

    return 0;
}