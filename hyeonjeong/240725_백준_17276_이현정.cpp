#include <iostream>
#include <vector>

using namespace std;

long long map[499][499] = { 0, };
long long mmap[499][499] = { 0, };

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, d;
		cin >> n >> d;

		int times = d / 45; // 몇 번 돌려야 하는지
		if (times < 0) times *= (-1);

		// 원본 배열
		map[499][499] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		// 안돌릴 때
		if (d == 0) continue;

		// 만약 시계방향으로 돌릴때
		if (d > 0) {
			for (int k = 0; k < times; k++) {
				mmap[499][499] = { 0, };

				// 규칙에 따라 이동
				for (int i = 0; i < n; i++) {
					mmap[i][n / 2] = map[i][i];
					mmap[i][n - 1 - i] = map[i][n / 2];
					mmap[n / 2][n - 1 - i] = map[i][n - 1 - i];
					mmap[n - 1 - i][n - 1 - i] = map[n / 2][n - 1 - i];
				}

				// 배열 훑으면서 복사
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (mmap[i][j] == 0) continue;
						map[i][j] = mmap[i][j];
					}
				}

			}
		}

		// 만약 반시계방향으로 돌릴때
		if (d < 0) {
			for (int k = 0; k < times; k++) {
				mmap[499][499] = { 0, };

				// 규칙에 따라 이동
				for (int i = 0; i < n; i++) {
					mmap[n / 2][i] = map[i][i];
					mmap[n - 1 - i][i] = map[n / 2][i];
					mmap[n - 1 - i][n / 2] = map[n - 1 - i][i];
					mmap[n - 1 - i][n - 1 - i] = map[n - 1 - i][n / 2];
				}

				// 배열 훑으면서 복사
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (mmap[i][j] == 0) continue;
						map[i][j] = mmap[i][j];
					}
				}

			}
		}


		// 출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}
}