// #include <iostream>
// #include <queue>
// using namespace std;

// char map[12][6] = {
//     0,
// };

// int iscombo(int i, int j, char color, int relation)
// {
//     if (map[i][j] == color)
//     {
//         map[i][j] = '1';
//         relation++;
//     }
//     else
//     {
//         return 0;
//     }
//     relation += iscombo(++i, j, color, relation);
//     relation += iscombo(i, ++j, color, relation);
//     relation += iscombo(--i, j, color, relation);
//     relation += iscombo(i, --j, color, relation);
//     return relation;
// }

// int main()
// {
//     int i, j = 0, combo = 0, test = 0;
//     queue<int> q_i, q_j;
//     for (i = 0; i < 12; i++)
//     {
//         for (j = 0; j < 6; j++)
//         {
//             cin >> map[i][j];
//             if (map[i][j] != '.')
//             {
//                 q_i.push(i);
//                 q_j.push(j);
//             }
//         }
//     }
//     while (!q_i.empty())
//     {
//         if (map[q_i.front()][q_j.front()] != '1')
//         {
//             test += iscombo(i, j, map[q_i.front()][q_j.front()], 0);
//             cout << test << endl;
//             if (test > 3)
//                 combo++;
//         }
//         q_i.pop();
//         q_j.pop();
//     }
//     for (i = 0; i < 12; i++)
//     {
//         for (j = 0; j < 6; j++)
//         {
//             cout << map[i][j];
//         }
//         cout << endl;
//     }
// }
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int ROW = 12;
const int COL = 6;
const int MAX_LABEL = 72;

char board[ROW][COL + 1];
const short posX[4] = {1, 0, -1, 0};
const short posY[4] = {0, 1, 0, -1};

struct Point
{
    short x;
    short y;

    Point() {}
    Point(short x, short y) : x(x), y(y) {}
};

bool removePuyo()
{
    bool res = false;
    queue<Point> q;
    vector<int> connectCount(MAX_LABEL);

    int label = 1;
    short visitTable[ROW][COL] = {};

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (visitTable[i][j] != 0 || board[i][j] == '.')
                continue;

            q.push(Point(i, j));

            while (!q.empty())
            {
                Point cur = q.front();
                q.pop();

                if (visitTable[cur.x][cur.y])
                    continue;

                visitTable[cur.x][cur.y] = label;
                connectCount[label - 1]++;

                for (int pos = 0; pos < 4; pos++)
                {
                    short nextX = cur.x + posX[pos];
                    short nextY = cur.y + posY[pos];

                    if (0 <= nextX && nextX < ROW && 0 <= nextY && nextY < COL)
                        if (board[nextX][nextY] != '.' && board[nextX][nextY] == board[cur.x][cur.y])
                            q.push(Point(nextX, nextY));
                }
            }

            label++;
        }
    }

    for (int i = 0; i < MAX_LABEL; i++)
    {
        if (connectCount[i] < 4)
            continue;

        if (res == false)
            res = true;

        for (int j = 0; j < ROW; j++)
            for (int k = 0; k < COL; k++)
                if (visitTable[j][k] == i + 1)
                    board[j][k] = '.';
    }

    return res;
}

void refreshBoard()
{
    for (int i = 0; i < COL; i++)
    {
        int target = 1, base = 0;

        while (base + target < ROW)
        {
            if (board[base][i] != '.')
                base++;
            else if (board[target + base][i] == '.')
                target++;
            else
            {
                swap(board[base][i], board[base + target][i]);
                base++;
                target = 1;
            }
        }
    }
}

int solution()
{
    int count = 0;
    for (; removePuyo(); count++)
        refreshBoard();

    return count;
}

int main()
{
    for (int i = ROW - 1; i >= 0; --i)
        cin >> board[i];

    cout << solution();

    return 0;
}