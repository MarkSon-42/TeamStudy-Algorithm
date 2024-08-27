#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N, M;
int C=0;
int answer;
int Map[8][8];
int TMap[8][8];
int turn[6] = { 0,4,2,4,4,1 };
int A[8];
pair<int, int> B[8];

void inspect1(int x,int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
}
void inspect2(int x, int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
	d = (d + 2) % 4;
	nx = x + dx[d];
	ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
}
void inspect3(int x, int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
	d = (d + 1) % 4;
	nx = x + dx[d];
	ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
}
void inspect4(int x, int y, int d)
{
	
	int nx = x + dx[d];
	int ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
	d = (d + 1) % 4;
	nx = x + dx[d];
	ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
	d = (d + 1) % 4;
	nx = x + dx[d];
	ny = y + dy[d];
	while (0 <= nx && nx < N && 0 <= ny && ny < M)
	{
		if (TMap[nx][ny] == 6)
			break;
		if (TMap[nx][ny] == 0)
			TMap[nx][ny] = 7;
		nx += dx[d];
		ny += dy[d];
	}
}
void inspect5(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (0 <= nx && nx < N && 0 <= ny && ny < M)
		{
			if (TMap[nx][ny] == 6)
				break;
			if (TMap[nx][ny] == 0)
				TMap[nx][ny] = 7;
			nx += dx[i];
			ny += dy[i];
		}
	}
}
int check(vector<int>& a)
{
	for (int i = 0; i < C; i++)
	{
		int x = B[i].first;
		int y = B[i].second;
		if (A[i] == 1)
		{
			inspect1(x, y, a[i]);
		}
		else if (A[i] == 2)
		{
			inspect2(x, y, a[i]);
		}
		else if (A[i] == 3)
		{
			inspect3(x, y, a[i]);
		}
		else if (A[i] == 4)
		{
			inspect4(x, y, a[i]);
		}
		else if (A[i] == 5)
		{
			inspect5(x, y);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (TMap[i][j] == 0)
				result++;
		}
	}
	return result;
}
void dfs(int d, vector<int>& a)
{
	if (d == C)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				TMap[i][j] = Map[i][j];
			}
		}
		int result = check(a);
		if (answer > result)
			answer = result;
		return;
	}
	for (int i = 0; i < turn[A[i]]; i++)
	{
		a.push_back(i);
		dfs(d + 1, a);
		a.pop_back();
	}
}



int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if (1 <= Map[i][j] && Map[i][j] <= 5)
			{
				A[C] = Map[i][j];
				B[C] = { i,j };
				C++;
			}
		}
	}
	
	answer = N * M;
	vector<int> t;
	dfs(0, t);
	cout << answer << "\n";
	return 0;
}