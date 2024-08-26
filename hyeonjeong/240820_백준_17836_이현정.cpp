#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, T;
int MAP[100][100] = { 0, };
int gram_y, gram_x;

// 가장 빠른 = BFS

void input() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				gram_y = i;
				gram_x = j;
			}
		}
	}
}

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 시작좌표(y, x), 도착좌표(y, x), gram 여부(0=없다/1=있다)
int BFS(int sy, int sx, int y, int x, int mode) {

	int visited[100][100] = { 0, };
	queue<int> q;
	// 시작좌표, 시간
	for (int i = 0; i < 3; i++) {
		q.push(sy);
		q.push(sx);
		q.push(0);
	}
	visited[0][0] = 1;

	while (!q.empty()) {
		int iy = q.front(); q.pop();
		int ix = q.front(); q.pop();
		int it = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = iy + dy[i];
			int nx = ix + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (mode == 0 and MAP[ny][nx] == 1) continue;
			if (visited[ny][nx] == 1) continue;
			// 도착지에 도달
			if (ny == y and nx == x) return it + 1;

			visited[ny][nx] = 1;
			q.push(ny); q.push(nx); q.push(it + 1);
		}
	}
	// 도착지에 도달 불가능
	return -1;
}

int main() {
	input();
	int t1, t2, t3;
	t1 = BFS(0, 0, N - 1, M - 1, 0); // 0 -> 공주
	t2 = BFS(0, 0, gram_y, gram_x, 0); // 0 -> gram
	t3 = BFS(gram_y, gram_x, N - 1, M - 1, 1); // gram -> 공주

	// 시간 비교 및 출력
	int t = T - 1;
	if (t1 == -1 and t2 == -1 or t3 == -1) t = T + 1;
	else if (t1 == -1) t = t2 + t3;
	else if (t2 == -1 or t3 == -1) t = t1;
	else t = min(t1, t2 + t3);
	if (T < t) cout << "Fail";
	else cout << t;
}