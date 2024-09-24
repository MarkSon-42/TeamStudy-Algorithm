#include <iostream>
// 백준 16954번 움직이는 미로 탈출

/*
제한시간 2초
backtracking이라고 판단
이유는 경우의 수가 꽤 많기는 하지만, 
걸러질 경우는 8초 이내에 걸러지기 떄문(벽이 먼저 떨어진다)

벽을 이동시킬 필요도 없다.
왜냐하면 벽은 현재 y좌표-시간이니까.
*/

using namespace std;
int MAP[8][8] = { 0, };
int nowy = 7, nowx = 0;

void input() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '.') {
				MAP[i][j] = 0;
			}
			else if (tmp == '#') {
				MAP[i][j] = 1;
			}
		}
	}
}

int flag = 0; // 갈 수 있느냐?
// 방향 배열 (상하좌우 + 제자리 + 대각선)
int dy[9] = { 0, 1, 0, -1, 0, 1, -1, 1, -1 };
int dx[9] = { 1, 0, -1, 0, 0, 1, -1, -1, 1 };

// 이동 (y좌표, x좌표, 현재 시간)
void move(int y, int x, int t) {
	if (y == 0 and x == 7 or t == 8) {
		// 도착 성공 (또는 벽이 모두 떨어져서 성공이 보장됨)
		flag = 1;
		return;
	}
	for (int i = 0; i < 9; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= 8 or nx >= 8) continue;
		// 현재 벽인 곳으로 이동하거나 미래 벽인 곳으로 이동하는 경우
		if ((ny-t>=0 and MAP[ny-t][nx] == 1) or (ny - t-1 >= 0 and MAP[ny - t-1][nx] == 1)) {
			continue;
		}
		move(ny, nx, t + 1);
		if (flag == 1) return;
	}
}

int main() {
	input();
	move(nowy, nowx, 0);
	cout << flag;
}
