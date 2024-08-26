#include <iostream>
#include <queue>

using namespace std;

char MAP[12][6];
int ans = 0;

// 초기 뿌요뿌요맵
void input() {
	for (int i = 0; i < 12; i++) {
		cin >> MAP[i];
	}
}

queue<int> Xs;

int visited[12][6] = { 0, };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int flag;

// 앞에 해당좌표 visited 해줄것
// 해당되는 좌표를 count해서 
void DFS(int y, int x, char a) {
	Xs.push(y);
	Xs.push(x);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= 12 or nx >= 6) continue;
		if (visited[ny][nx] == 1) continue;

		if (MAP[ny][nx] != a) continue;
		visited[ny][nx] = 1;
		DFS(ny, nx, a);
	}
}

void DFS_backup(int y, int x) {
	if (Xs.size() < 8) {
		while (!Xs.empty()) { Xs.pop(); }
		return;
	}
	else {
		flag = 1;
		Xs.push(y);
		Xs.push(x);

		while (!Xs.empty()) {
			int ny = Xs.front(); Xs.pop();
			int nx = Xs.front(); Xs.pop();
			MAP[ny][nx] = '.';
		}
	}
}

void puyo_push() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			char x = '.';
			if (MAP[i][j] == '.') {
				for (int y = i - 1; y >= 0; y--) {
					if (MAP[y][j] != '.') {
						x = MAP[y][j];
						MAP[y][j] = '.';
						break;
					}
				}
				if (x == '.') break;
				MAP[i][j] = x;
			}
		}
	}
}

int main() {
	input();
	while (true) {
		flag = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (MAP[i][j] == '.') continue;
				visited[i][j] = 1;
				char a = MAP[i][j];
				DFS(i, j, a);
				DFS_backup(i, j);
			}
		}
		/*for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}*/
		if (flag == 1) {
			ans++;
			puyo_push();
		}
		else break;
	}
	cout << ans;
}