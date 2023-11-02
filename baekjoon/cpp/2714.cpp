#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, R, C, mv[4]={0,1,0,-1};
    string message;
    cin >> T;
    while (T--) {
        cin >> R >> C >> message;
        bool visited[21][21]={0,};
        int cnt=0, cury=0, curx=0, nxty, nxtx, direction=0, len=0; // 0:우 1:하 2:좌 3:상
        char chr=0;
        string original;
        while (cnt<R*C) {
            chr = (chr<<1) + (message[cury*C+curx]-'0');
            if (++len==5) {
                if (chr==0) original += ' ';
                else original += chr+'A'-1;
                len=0; chr=0;
            }
            visited[cury][curx] = true;
            
            nxty = cury + mv[direction];
            nxtx = curx + mv[(direction+1)%4];
            if (nxtx<0 || nxty>=R || nxtx<0 || nxtx>=C || visited[nxty][nxtx])
                direction = (direction+1)%4;
            cury += mv[direction];
            curx += mv[(direction+1)%4];
            cnt++;
        }
        original.erase(original.find_last_not_of(' ')+1);
        cout << original << '\n';
    }
    return 0;
}