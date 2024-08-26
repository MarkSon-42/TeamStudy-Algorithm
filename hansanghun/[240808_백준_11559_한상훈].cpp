#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[12][6] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
char A[12][7];
int answer = 0;
bool bfs(int nowx, int nowy, char nowc)
{
	int count = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> remove;
	q.push({ nowx,nowy });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (visited[x][y])
			continue;
		visited[x][y] = true;
		count++;
		remove.push_back({ x,y });
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 12 && 0 <= ny && ny < 6 && A[nx][ny] == nowc)
			{
				if (!visited[nx][ny])
					q.push({ nx,ny });
			}
		}
	}
	if (count >= 4)
	{
		for (auto i : remove)
		{
			A[i.first][i.second] = '.';
		}
		return true;
	}

	return false;
}

void move()
{
	for (int i = 0; i < 6; i++)
	{
		queue<int> q;
		for (int j = 11; j >= 0; j--)
		{
			if (A[j][i] != '.')
			{
				if (!q.empty())
				{
					int x = q.front();
					q.pop();
					A[x][i] = A[j][i];
					A[j][i] = '.';
					q.push(j);
				}
			}
			else
			{
				q.push(j);
			}
		}
	}
}
bool check()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
			visited[i][j] = false;
	}
	bool flag = false;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (!visited[i][j] && A[i][j] != '.')
				flag |= bfs(i, j, A[i][j]);
		}
	}
	if (flag)
	{
		answer += 1;
		move();
	}
	return flag;
}


int main()
{
	for (int i = 0; i < 12; i++)
		cin >> A[i];

	while (check());
	cout << answer << "\n";
}