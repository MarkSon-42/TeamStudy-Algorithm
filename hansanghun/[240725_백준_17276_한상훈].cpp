#include <iostream>
#include <deque>
#include <vector>
using namespace std;


int N;
int A[500][500];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, d;
	cin >> T;
	while (T--)
	{
		vector<int> v[8];
		deque<vector<int>*> dq;
		cin >> N >> d;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> A[i][j];
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[0].push_back(A[i][i]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[1].push_back(A[i][N / 2]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[2].push_back(A[i][N - 1 - i]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[3].push_back(A[N / 2][N - 1 - i]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[4].push_back(A[N - 1 - i][N - 1 - i]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[5].push_back(A[N - 1 - i][N / 2]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[6].push_back(A[N - 1 - i][i]);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v[7].push_back(A[N / 2][i]);
		}
		for (int i = 0; i < 8; i++)
		{
			dq.push_back(&v[i]);
		}
		if (d >= 0)
		{
			d /= 45;
			d %= 8;
			while (d--)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		else
		{
			d *= -1;
			d /= 45;
			d %= 8;
			while (d--)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[i][i] = (dq[0])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[i][N / 2] = (dq[1])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[i][N - 1 - i] = (dq[2])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[N / 2][N - 1 - i] = (dq[3])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[N - 1 - i][N - 1 - i] = (dq[4])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[N - 1 - i][N / 2] = (dq[5])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[N - 1 - i][i] = (dq[6])->at(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			A[N / 2][i] = (dq[7])->at(i);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
	}
}