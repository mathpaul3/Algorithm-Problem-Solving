#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 300
using namespace std;

int i, j, N, M;
int map[MAX][MAX], check[MAX][MAX];
int dx[] = {0, 1}, dy[] = {1, 0};

void Init()
{
	cin >> N >> M;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			cin >> map[i][j];
	}
}

void BFS()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	check[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << cnt << endl;
			return;
		}

		for (i = 0; i < 2; i++)
		{
			for (j = 1; j <= map[x][y]; j++)
			{
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && !check[nx][ny])
				{
					check[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Init();
	BFS();

	return 0;
}
