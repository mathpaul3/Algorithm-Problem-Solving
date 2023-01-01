#include <iostream>
#include <string>
using namespace std;

int i, j, x, y, M;
int mv[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};
string map[8];

void Init()
{
    for (i=0; i<8; i++)
        cin >> map[i];
}

int converted(int xaxis, int yaxis)
{
    int cnv=0, x, y;
    for (i=0; i<8; i++)
    {
        for (j=0;;j++)
        {
            y = yaxis + mv[i][0] * (j+1);
            x = xaxis + mv[i][1] * (j+1);
            if (x>=0 && y>=0 && x<8 && y<8)
            {
                if (map[y][x] == 'W') {continue;}
                else if (map[y][x] == 'B') {cnv += j;}
                break;
            } else {break;}
        }
    }
    return cnv;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

int main() {
    Init();
    for (y=0; y<8; y++)
        for (x=0; x<8; x++)
            if (map[y][x] == '.')
                M = max(M, converted(x, y));

    cout << M;
    return 0;
}