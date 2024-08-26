#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int answer = 0;
int C[5][5];
char A[5][6];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool check[5][5] = { false };
bool visited[5][5] = { false };

int dfs(int x, int y)
{
	visited[x][y] = true;
	int result = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && check[nx][ny] && !visited[nx][ny])
		{
			result += dfs(nx, ny);
		}
	}
	return result;
}



void back(int d, int next, int Y, vector<int> &v)
{
	if (d == 7)
	{
		for (int i : v)
		{
			int a = i / 5;
			int b = i % 5;
			visited[a][b] = false;
		}
		int x = v[0] / 5;
		int y = v[0] % 5;
		int result = dfs(x, y);
		if (result == 7)
			answer++;
		return;
	}
	for (int i = next; i < 25; i++)
	{
		int a = i / 5;
		int b = i % 5;
		if (A[a][b] == 'Y'&&Y < 3)
		{
			v.push_back(i);
			check[a][b] = true;
			back(d + 1, i + 1, Y + 1, v);
			check[a][b] = false;
			v.pop_back();
		}
		else if (A[a][b] == 'S')
		{
			v.push_back(i);
			check[a][b] = true;
			back(d + 1, i + 1, Y, v);
			check[a][b] = false;
			v.pop_back();
		}

	}
}



int main()
{
	for (int i = 0; i < 5; i++)
		cin >> A[i];
	vector<int> v;
	back(0, 0, 0, v);
	cout << answer << "\n";
	return 0;
}