#include <iostream>
#include <queue>
using namespace std;

int T, h, w, dy[4]={0,0,-1,1}, dx[4]={-1,1,0,0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        int cnt=0;
        char map[100][100]={0,};
        bool visited[100][100]={0,}, key[26]={0,};
        queue<pair<int,int> > mv;
        cin >> h >> w;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> map[i][j];
                if (map[i][j]!='*' && (!i || !j || i==(h-1) || j==(w-1))) {
                    mv.push(make_pair(i,j));
                    visited[i][j] = true;
                }
            }
        }
        string keys;
        cin >> keys;
        int k_sz = keys.size();
        if (keys[0] != '0')
            for (int i=0; i<k_sz; i++)
                key[(int)(keys[i]-'a')] = true;


        while (!mv.empty()) {
            bool movable = false;
            int sz = mv.size();
            for (int i=0; i<sz; i++) {
                int y=mv.front().first, x=mv.front().second; mv.pop();
                if (map[y][x]=='$') cnt++;
                else if (map[y][x]!='.') {
                    if (map[y][x]>='a') {key[(int)(map[y][x]-'a')]=true; movable=true;}
                    else if (!key[(int)(map[y][x]-'A')]) {mv.push(make_pair(y, x)); continue;}
                }
                for (int j=0; j<4; j++) {
                    int yy=y+dy[j], xx=x+dx[j];
                    if ((0<=yy) && (yy<h) && (0<=xx) && (xx<w) && (map[yy][xx]!='*') && !visited[yy][xx]) {
                        mv.push(make_pair(yy,xx));
                        visited[yy][xx] = true;
                        movable = true;
                    }
                }
            }
            if (!movable) break;
        }
        cout << cnt << '\n';
    }
}