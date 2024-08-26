#include <iostream>
using namespace std;

int N, K;
int A[201];
int robot[201];
int level = 0;
int indexUp;
int indexDown;
int cnt;

void func() {
	while (1) {
		// 레벨 증가
		level += 1;

		// 한 칸 이동
		indexUp = indexUp - 1;
		indexDown = indexDown - 1;

		if (indexUp <= 0)
			indexUp = 2 * N;
		if (indexDown <= 0)
			indexDown = 2 * N;
		// cout << "이동 : " << indexUp << " " << indexDown << endl;
		// 내리는 지점에 도달한 로봇은 무조건 내린다.
		if (robot[indexDown] == 1) {
			robot[indexDown] = 0;
		}

		// 먼저 올라온 로봇부터 한 칸씩 이동
		for (int i = 1; i < N; i++) {
			int idx = indexDown - i;
			if (idx <= 0)
				idx += (2 * N);
			int nextIdx = (idx % (2 * N)) + 1;
			if (robot[idx] == 1) {
				int flag = 0;
				if (robot[nextIdx] == 1 || A[nextIdx] == 0)
					continue;
				robot[nextIdx] = 1; robot[idx] = 0;
				if (A[nextIdx] > 0) {
					A[nextIdx] -= 1;
					flag = 1;
				}
				if (A[nextIdx] <= 0 && flag == 1)
					cnt++;
				if (cnt >= K)
					return;
			}
		}

		// 올리는 칸에 로봇 올려주기
		robot[indexUp] = 1;
		int flag = 0;
		if (A[indexUp] > 0) {
			A[indexUp] -= 1;
			flag = 1;
		}
		if (A[indexUp] <= 0 && flag == 1)
			cnt++;
		if (cnt >= K)
			return;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> A[i];
	}
	indexUp = 1;
	indexDown = N;
	func();
	cout << level;
}