#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[50][9];
int answer = 0;
bool visited[9] = { false };

int play(vector<int>& player)
{
	int result = 0;
	int cur = 0;

	for (int i = 0; i < N; i++)
	{
		int out_player = 0;
		int home[4] = { 0 };

		while (out_player < 3)
		{
			int attacker = player[cur];
			int attack = A[i][attacker];
			cur = (cur + 1) % 9;
			if (attack == 0)
			{
				out_player++;
				continue;
			}
			if (attack == 4)
			{
				result++;
				for (int j = 1; j <= 3; j++)
					if (home[j])
					{
						result++;
						home[j] = 0;
					}
			}
			else
			{
				for (int j = 3; j >= 1; j--)
				{
					if (home[j])
					{
						if (j + attack >= 4)
						{
							result++;
							home[j] = 0;
						}
						else
						{
							home[j + attack] = home[j];
							home[j] = 0;
						}
					}
				}
				home[attack] = 1;
			}

		}
	}
	return result;
}

void dfs(int d, vector<int>& v)
{
	if (d == 8)
	{
		int temp = play(v);
		if (temp > answer)
			answer = temp;
		return;
	}
	if (d == 3)
	{
		v.push_back(0);
	}
	for (int i = 1; i < 9; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			v.push_back(i);
			dfs(d + 1, v);
			v.pop_back();
			visited[i] = false;
		}
	}
	if (d == 3)
	{
		v.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> A[i][j];
		}
	}
	vector<int> v;
	dfs(0, v);
	cout << answer << "\n";
}

