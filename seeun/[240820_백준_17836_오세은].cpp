#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, T;
int MAP[101][101];
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int visited[101][101][2]; // [y][x][gram] 상태에서의 최소 시간 저장

void move() {
	queue<tuple<int, int, int, int>> q; // (y, x, time, gram)
	q.push({ 1, 1, 0, 0 });
	visited[1][1][0] = 0;

	while (!q.empty()) {
		auto[currentY, currentX, time, gram] = q.front(); q.pop();

		if (currentY == N && currentX == M) {
			if (time <= T) {
				cout << time;
			}
			else {
				cout << "Fail";
			}
			return;
		}

		if (time >= T) continue;

		for (int d = 0; d < 4; d++) {
			int dy = currentY + direction[d][0];
			int dx = currentX + direction[d][1];
			if (dy < 1 || dx < 1 || dy > N || dx > M) continue;

			int nextTime = time + 1;
			int nextGram = gram;

			if (MAP[dy][dx] == 2) nextGram = 1; // Gram을 획득한 경우

			if (MAP[dy][dx] == 1 && nextGram == 0) continue; // 벽인데 gram이 없는 경우

			// 해당 상태에서 더 적은 시간에 방문했는지 확인
			if (visited[dy][dx][nextGram] == 0 || visited[dy][dx][nextGram] > nextTime) {
				visited[dy][dx][nextGram] = nextTime;
				q.push({ dy, dx, nextTime, nextGram });
			}
		}
	}

	cout << "Fail";
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	move();

	return 0;
}
