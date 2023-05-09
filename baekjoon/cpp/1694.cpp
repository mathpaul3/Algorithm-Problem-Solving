#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int cnt_safe(vector<string> *map) {
    int mvn[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int mvk[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int mvp[2] = {-1, 1};

    char board[8][8] = {0,};
    int sz=map->size();
    for (int i=0; i<sz; i++) {
        int len = (*map)[i].size(), cnt=0;
        for (int j=0; j<len; j++) {
            char cur = (*map)[i][j];
            if ('1'<=cur && cur<='9') {
                int blank = (int)(cur-'0');
                for (int k=0; k<blank; k++) {
                    board[i][cnt++] = ' ';
                }
            } else {
                board[i][cnt++] = cur;
            }
        }
    }
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            char cur=board[i][j];

            int limUL=(i<j?i:j), limUR=(i<(7-j)?i:(7-j)), limLL=((7-i)<j?(7-i):j), limLR=((7-i)<(7-j)?(7-i):(7-j));
            int dy=(board[i][j]=='p' ? 1 : -1);
            switch (cur) {
                case 'q':
                case 'Q':
                case 'r':
                case 'R':
                    for (int k=i-1; k>=0; k--) {
                        if (board[k][j]>'.') break;
                        else board[k][j] = '.';
                    }
                    for (int k=i+1; k<8; k++) {
                        if (board[k][j]>'.') break;
                        else board[k][j] = '.';
                    }
                    for (int k=j-1; k>=0; k--) {
                        if (board[i][k]>'.') break;
                        else board[i][k] = '.';
                    }
                    for (int k=j+1; k<8; k++) {
                        if (board[i][k]>'.') break;
                        else board[i][k] = '.';
                    }
                    if (cur=='r' || cur=='R')
                        break;
                case 'b':
                case 'B':
                    for (int k=1; k<=limUL; k++) {
                        if (board[i-k][j-k]>'.') break;
                        else board[i-k][j-k] = '.';
                    }
                    for (int k=1; k<=limUR; k++) {
                        if (board[i-k][j+k]>'.') break;
                        else board[i-k][j+k] = '.';
                    }
                    for (int k=1; k<=limLL; k++) {
                        if (board[i+k][j-k]>'.') break;
                        else board[i+k][j-k] = '.';
                    }
                    for (int k=1; k<=limLR; k++) {
                        if (board[i+k][j+k]>'.') break;
                        else board[i+k][j+k] = '.';
                    }
                    break;
                case 'n':
                case 'N':
                case 'k':
                case 'K':
                    for (int k=0; k<8; k++) {
                        int y, x;
                        if (board[i][j]=='n' || board[i][j]=='N') {
                            y = i+mvn[k]; x=j+mvn[(k+2)%8];
                        } else {
                            y = i+mvk[k]; x=j+mvk[(k+2)%8];
                        }
                        if (0<=y && y<8 && 0<=x && x<8 && board[y][x]<='.') {
                            board[y][x] = '.';
                        }
                    }
                    break;
                case 'p':
                case 'P':
                    for (int k=0; k<2; k++) {
                        int y=i+dy, x=j+mvp[k];
                        if (0<=y && y<8 && 0<=x && x<8 && board[y][x]<='.') {
                            board[y][x] = '.';
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    int cnt=0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j]==' ') cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string input;
    while (cin >> input) {
        vector<string> map;
        stringstream ss(input);
        string buffer;
        while (getline(ss, buffer, '/')) {
            map.push_back(buffer);
        }

        cout << cnt_safe(&map) << '\n';
    }
    
    return 0;
}