#include <iostream>
using namespace std;

int N, L;
int map[101][101];
int visitedRow[101];
int visitedCol[101];
int cnt;


void func() {
	for (int i = 0; i < N; i++) {
		int flag = 0;
		int now = map[i][0];
		for (int j = 0; j < N; j++) {
			visitedRow[j] = 0;
			visitedCol[j] = 0;
		}
		for (int j = 1; j < N; j++) {
			now = map[i][j - 1];
			int next = map[i][j];
			if (now > next + 1 || now + 1 < next) {
				flag = 1;
				break;
			}
			if (now  == next + 1) {
				for (int dx = j + 1; dx < j + L; dx++) {
					if (dx >= N) {
						flag = 1;
						break;
					}
					if (visitedRow[dx] == 1) {
						flag = 1;
						break;
					}
					if (map[i][dx] != next) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					for (int d = j; d < j + L; d++) {
						visitedRow[d] = 1;
					}
				}
			}
			if (now + 1 == next) {
				for (int dx = j - 1; dx >= j - L; dx--) {
					if (dx < 0) {
						flag = 1;
						break;
					}
					if (visitedRow[dx] == 1) {
						flag = 1;
						break;
					}
					if (map[i][dx] != now) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					for (int d = j - 1; d >= j - L; d--) {
						visitedRow[d] = 1;
					}
					continue;
				}
			}
		}
		if (flag == 0) {
			cnt++;
			// cout << "y : " << i << " => " << cnt << endl;
		}

		flag = 0;
		for (int j = 1; j < N; j++) {
			now = map[j - 1][i];
			int next = map[j][i];
			if (now == next)
				continue;
			if (now > next + 1 || now + 1 < next) {
				flag = 1;
				break;
			}
			if (now == next + 1) {
				for (int dy = j + 1; dy < j + L; dy++) {
					if (dy >= N) {
						flag = 1;
						break;
					}
					if (visitedCol[dy] == 1) {
						flag = 1;
						break;
					}
					if (map[dy][i] != next) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					for (int d = j; d < j + L; d++) {
						visitedCol[d] = 1;
					}
					continue;
				}
			}
			if (now + 1 == next) {
				for (int dy = j - 1; dy >= j - L; dy--) {
					if (dy < 0) {
						flag = 1;
						break;
					}
					if (visitedCol[dy] == 1) {
						flag = 1;
						break;
					}
					if (map[dy][i] != now) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					for (int dy = j - 1; dy >= j - L; dy--) {
						visitedCol[dy] = 1;
					}
					continue;
				}
			}
		}
		if (flag == 0) {
			cnt++;
			// cout << "x : " << i << " => " << cnt << endl;
		}
	}
	cout << cnt;
	return;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	func();
	return 0;
}
