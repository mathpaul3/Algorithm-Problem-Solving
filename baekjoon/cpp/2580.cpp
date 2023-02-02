#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool board[9][9][10]={0,};
short remain[9][9]={0,};
char sudoku[9][9]={0,};
queue<pair<int,int> > zeros;
vector<pair<int,int> > zeros_v;

void fill_cross(int y, int x) {
    int num = sudoku[y][x]-'0';
    for (int i=0; i<9; i++)
        if (!board[i][x][num]) {board[i][x][num] = true; remain[i][x]--;}
    for (int i=0; i<9; i++)
        if (!board[y][i][num]) {board[y][i][num] = true; remain[y][i]--;}
}

void fill_33(int y, int x) {
    int num = sudoku[y][x]-'0';
    int y_from=(y/3)*3, y_to=y_from+3;
    int x_from=(x/3)*3, x_to=x_from+3;
    for (int i=y_from; i<y_to; i++)
        for (int j=x_from; j<x_to; j++)
            if (!board[i][j][num]) {board[i][j][num] = true; remain[i][j]--;}
}

void fill(int y, int x) {
    fill_33(y, x); fill_cross(y, x);
}

bool check_cross(int y, int x) {
    char num = sudoku[y][x];
    for (int i=0; i<9; i++)
        if (sudoku[i][x]==num && i!=y) return false;
    for (int i=0; i<9; i++)
        if (sudoku[y][i]==num && i!=x) return false;
    return true;
}

bool check_33(int y, int x) {
    char num = sudoku[y][x];
    int y_from=(y/3)*3, y_to=y_from+3;
    int x_from=(x/3)*3, x_to=x_from+3;
    for (int i=y_from; i<y_to; i++)
        for (int j=x_from; j<x_to; j++)
            if (sudoku[i][j]==num && i!=y && j!=x) return false;
    return true;
}

bool check(int y, int x) {
    if (check_cross(y, x) && check_33(y, x)) return true;
    return false;
}

bool DFS(int depth) {
    if (depth == zeros_v.size()) return true;
    int y=zeros_v[depth].first, x=zeros_v[depth].second;
    for (int i=1; i<10; i++) {
        if (!board[y][x][i]) {
            sudoku[y][x] = (char)(i+'0');
            if (check(y,x)) {
                // cout << "board[" << y << "][" << x << "][" << i << "] " << depth << '\n';
                if (DFS(depth+1)) return true;
                else {sudoku[y][x] = '0';}
            }
            else {sudoku[y][x] = '0';}
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> sudoku[i][j];
            remain[i][j] = 9;
            if (sudoku[i][j]-'0') {fill(i, j);}
            else zeros.push(make_pair(i, j));
        }
    }
    int sz=0;
    while (!zeros.empty()) {
        if (sz == zeros.size()) break;
        sz = zeros.size();
        for (int i=0; i<sz; i++) {
            int y=zeros.front().first, x=zeros.front().second, cnt=0, last=0;
            zeros.pop();
            if (remain[y][x]==1) {
                for (int j=1; j<10; j++) {
                    if (!board[y][x][j]) {
                        sudoku[y][x] = (char)(j+'0');
                        board[y][x][j] = true;
                        remain[y][x]--;
                    }
                }
            }
            else zeros.push(make_pair(y, x));
        }
    }
    while (!zeros.empty()) {zeros_v.push_back(make_pair(zeros.front().first, zeros.front().second)); zeros.pop();}
    DFS(0);

    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}