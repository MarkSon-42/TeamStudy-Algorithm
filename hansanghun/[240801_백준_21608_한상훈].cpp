#include <iostream>
#include <vector>
using namespace std;
int N;
pair<int, int> A[401];
bool visited[21][21] = { false };
bool fvisited[401] = { false };
int Map[21][21];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int friends[401][4];
int order[401];
int cc[21][21] = { 0 };
int friendc[21][21] = { 0 };
vector<pair<int, int>> v;
int main()
{
	cin >> N;
	for (int i = 0; i < N*N; i++)
	{
		int a;
		cin >> a;
		order[i + 1] = a;
		for (int j = 0; j < 4; j++)
		{
			cin >> friends[a][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1 || j == 1 || i == N || j == N)
				cc[i][j] = 3;
			else
				cc[i][j] = 4;
		}
	}
	cc[1][1] = 2;
	cc[1][N] = 2;
	cc[N][1] = 2;
	cc[N][N] = 2;
	for (int i = 1; i <= N * N; i++)
	{
		int a = order[i];
		fvisited[a] = true;
		vector<pair<int, int>> ans;
		for (int j = 0; j < 4; j++)
		{
			if (fvisited[friends[a][j]])
			{
				int x = A[friends[a][j]].first;
				int y = A[friends[a][j]].second;
				for (int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (1 <= nx && nx <= N && 1 <= ny && ny <= N && !visited[nx][ny])
					{
						ans.push_back({ nx,ny });
						friendc[nx][ny]++;
					}
				}
			}
		}
		if (!ans.empty())
		{
			int x = -1, y = -1;
			int meet = -1;
			int blank = -1;
			for (auto j : ans)
			{
				if (meet <= friendc[j.first][j.second])
				{
					if (meet < friendc[j.first][j.second])
					{
						x = j.first;
						y = j.second;
						meet = friendc[j.first][j.second];
						blank = cc[j.first][j.second];
					}
					else if (meet == friendc[j.first][j.second] && blank < cc[j.first][j.second])
					{
						x = j.first;
						y = j.second;
						blank = cc[j.first][j.second];
					}
					else if (blank == cc[j.first][j.second])
					{
						if (x > j.first)
						{
							x = j.first;
							y = j.second;
						}
						else if (x == j.first && y > j.second)
						{
							x = j.first;
							y = j.second;
						}
					}
				}
			}
			Map[x][y] = a;
			A[a] = { x,y };
			while (!ans.empty())
			{
				friendc[ans.back().first][ans.back().second]--;
				ans.pop_back();
			}
			visited[x][y] = true;
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (1 <= nx && nx <= N && 1 <= ny && ny <= N && !visited[nx][ny])
				{
					cc[nx][ny]--;
				}
			}
		}
		else
		{
			int x = 0, y = 0;
			int blank = -1;
			for (int j = 1; j <= N; j++)
			{
				for (int k = 1; k <= N; k++)
				{
					if (!visited[j][k] && blank < cc[j][k])
					{
						blank = cc[j][k];
						x = j;
						y = k;
						if (blank == 4)
							break;
					}
				}
			}
			Map[x][y] = a;
			A[a] = { x,y };
			visited[x][y] = true;
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (1 <= nx && nx <= N && 1 <= ny && ny <= N && !visited[nx][ny])
				{
					cc[nx][ny]--;
				}
			}
		}

	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a = Map[i][j];
			int fc = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
				{
					bool flag = false;
					for (int l = 0; l < 4; l++)
					{
						if (friends[a][l] == Map[nx][ny])
						{
							flag = true;
							break;
						}
					}
					if (flag)
						fc++;
				}
			}
			if (fc == 1)
				answer += 1;
			else if (fc == 2)
				answer += 10;
			else if (fc == 3)
				answer += 100;
			else if (fc == 4)
				answer += 1000;
		}
	}
	cout << answer << "\n";
}
