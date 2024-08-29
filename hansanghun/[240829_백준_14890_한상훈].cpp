#include <iostream>
#include <cmath>
using namespace std;

int N, L;
int A[100][100];
int B[100][100];
bool visited[100] = { false };
bool check(int C[100][100], int x)
{
	int pre = C[x][0];
	for (int i = 0; i < N; i++)
		visited[i] = false;
	int idx = 1;
	while (idx < N)
	{
		if (abs(pre - C[x][idx]) > 1)
			return false;
		if (pre + 1 == C[x][idx])
		{
			if (idx < L)
				return false;
			for (int i = idx-1; i>=idx-L; i--)
			{
				if (!visited[i] && C[x][i] == pre)
				{
					visited[i] = true;
				}
				else
					return false;
			}
			pre = C[x][idx];
			idx++;
		}
		else if (C[x][idx] + 1 == pre)
		{
			if (N - idx < L)
				return false;
			for (int i = idx; i < idx + L; i++)
			{
				if (!visited[i] && C[x][i] == C[x][idx])
				{
					visited[i] = true;
				}
				else
					return false;
			}
			pre = C[x][idx];
			idx += L;
			
		}
		else if(C[x][idx] == pre)
		{
			pre = C[x][idx];
			idx++;
		}

	}
	return true;
}
void turn90()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = A[j][i];
		}
	}
}
int main()
{
	int answer = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	turn90();
	for (int i = 0; i < N; i++)
	{
		if (check(A, i))
			answer++;
		if (check(B, i))
			answer++;
	}
	cout << answer << "\n";
}


