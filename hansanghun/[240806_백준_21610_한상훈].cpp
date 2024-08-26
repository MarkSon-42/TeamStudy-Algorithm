#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M;
int A[50][50];
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

int fx[] = { -1,-1,1,1 };
int fy[] = { -1,1,-1,1 };
void move(deque<pair<int, int>>& iq, int d, int s)
{
	bool visited[50][50] = { false }; //������ �־��� ��ġ ǥ��
	for (int i = 0; i < iq.size(); i++)
	{
		iq[i].first = (N*s + (iq[i].first + s * dx[d])) % N; //���� �̵�
		iq[i].second = (N*s + (iq[i].second + s * dy[d])) % N;
		int x = iq[i].first;
		int y = iq[i].second;
		A[x][y] += 1; //�� ���� 1 �����ش�.
		visited[x][y] = true; // ������ġ ǥ��
	}
	vector<int> temp;
	for (int i = 0; i < iq.size(); i++)
	{
		int x = iq[i].first;
		int y = iq[i].second;
		int plus = 0;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + fx[j];
			int ny = y + fy[j];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny]>0)
				plus += 1; // �밢���� ���� ������ �����ش�.
		}
		temp.push_back(plus);
	}
	for (int i = 0; i < temp.size(); i++)
	{
		int x = iq[i].first;
		int y = iq[i].second;
		A[x][y] += temp[i]; // �밢���� ���ִ� �� �����ش�.
	}
	iq.clear(); // ���� Ŭ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && A[i][j] >= 2)
			{
				A[i][j] -= 2;
				iq.push_back({ i,j }); // ���ο� ���� �����.
			}
		}
	}
}


int main()
{

	cin >> N >> M;
	deque<pair<int, int>> q = { {N - 1,0},{N - 1,1},{N - 2,0},{N - 2,1} };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}

	for (int i = 0; i < M; i++)
	{
		int d, s;
		cin >> d >> s;
		move(q, d - 1, s);
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			answer += A[i][j];
	}
	cout << answer << "\n";
}