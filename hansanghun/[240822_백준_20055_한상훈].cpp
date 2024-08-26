#include <iostream>
using namespace std;


int N, K;
struct robot
{
	bool ch;
	int v;
};
robot arr[200];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;

	int answer = 0;
	for (int i = 0; i < N * 2; i++)
	{
		int a;
		cin >> a;
		arr[i] = { false,a };
	}
	int cur = 0;
	int mod = N * 2;
	while (K > 0)
	{
		cur = (mod + cur - 1) % mod;
		int last = (cur + N - 1) % mod;
		arr[last].ch = false;
		for (int i = N - 2; i >= 0; i--)
		{
			int now = (cur + i) % mod;
			if (arr[now].ch)
			{
				int next = (now + 1) % mod;
				if (arr[next].v > 0 && !arr[next].ch)
				{
					arr[now].ch = false;
					arr[next].ch = true;
					arr[next].v -= 1;
					if (arr[next].v == 0)
						K--;
				}
			}
		}
		arr[last].ch = false;
		if (arr[cur].v > 0)
		{
			arr[cur].v -= 1;
			arr[cur].ch = true;
			if (arr[cur].v == 0)
				K--;
		}
		answer++;
	}
	cout << answer << "\n";
}