#include <iostream>
#include <queue>
using namespace std;

struct Coord
{
	int x, y, t, s;

};

int N, M, T;
int Map[100][100];
bool visited[100][100][2] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs()
{
	queue<Coord> q;
	visited[0][0][0] = true;
	q.push({ 0,0,0,0 });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int t = q.front().t;
		int s = q.front().s;
		q.pop();
		if (x == N - 1 && y == M - 1)
			return t;
		if (t == T)
			continue;
		if (Map[x][y] == 2)
		{
			s = 1;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny][s])
			{
				if (s == 1 && Map[nx][ny] == 1)
				{
					visited[nx][ny][s] = true;
					q.push({ nx,ny,t + 1, s });
				}
				else if (Map[nx][ny] != 1)
				{
					visited[nx][ny][s] = true;
					q.push({ nx,ny,t + 1, s });
				}
			}
		}
	}



	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	answer = bfs();
	if (answer == -1)
		cout << "Fail\n";
	else
		cout << answer << "\n";
}