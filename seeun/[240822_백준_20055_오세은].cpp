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
		// ���� ����
		level += 1;

		// �� ĭ �̵�
		indexUp = indexUp - 1;
		indexDown = indexDown - 1;

		if (indexUp <= 0)
			indexUp = 2 * N;
		if (indexDown <= 0)
			indexDown = 2 * N;
		// cout << "�̵� : " << indexUp << " " << indexDown << endl;
		// ������ ������ ������ �κ��� ������ ������.
		if (robot[indexDown] == 1) {
			robot[indexDown] = 0;
		}

		// ���� �ö�� �κ����� �� ĭ�� �̵�
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

		// �ø��� ĭ�� �κ� �÷��ֱ�
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