#include <iostream>

using namespace std;

int N, L; // 지도의 크기 N*N, 경사로 바닥 크기
int MAP[100][100] = { 0, };

/*
길을 지나가려면
1. 연속된 수의 차는 항상 1, 0, -1
2. 작은 숫자의 개수가 연속해서 L개 이상 (높은 칸은 상관 없다!)
연속 개수.
*/

// 입력
void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

int main() {
	input();
	int ncnt = 0; // 정답이 아님
	// 세로부터 세기
	for (int i = 0; i < N; i++) {
		int adj = 1; //연속된 수;
		int endf = 0;
		for (int j = 0; j < N; j++) {
			if (j == 0) continue;
			// 이전과 지금을 비교한다.
			if (MAP[i][j - 1] == MAP[i][j]) adj++;
			else {
				if (MAP[i][j - 1] - MAP[i][j] > 1 or MAP[i][j - 1] - MAP[i][j] < -1) {
					ncnt++;
					endf = 1;
					break;
				}

				if (adj < 0) {
					ncnt++;
					endf = 1;
					break;
				}
				if (MAP[i][j - 1] < MAP[i][j]) {
					if (adj < L) {
						ncnt++;
						endf = 1;
						break;
					}
					adj = 1;
				}
				else {
					adj = -1 * (L-1);
				}
				
			}
			
		}
		if (endf == 0 and adj < 0) ncnt++;
	}
	// 가로
	for (int i = 0; i < N; i++) {
		int adj = 1; //연속된 수;
		int endf = 0;
		for (int j = 0; j < N; j++) {
			if (j == 0) continue;
			// 이전과 지금을 비교한다.
			if (MAP[j-1][i] == MAP[j][i]) adj++;
			else {
				if (MAP[j-1][i] - MAP[j][i] > 1 or MAP[j-1][i] - MAP[j][i] < -1) {
					ncnt++;
					endf = 1;
					break;
				}

				if (adj < 0) {
					ncnt++;
					endf = 1;
					break;
				}
				if (MAP[j-1][i] < MAP[j][i]) {
					if (adj < L) {
						ncnt++;
						endf = 1;
						break;
					}
					adj = 1;
				}
				else {
					adj = -1 * (L - 1);
				}

			}
			
		}
		if (endf == 0 and adj < 0) ncnt++;
	}

	cout << 2 * N - ncnt;
}
