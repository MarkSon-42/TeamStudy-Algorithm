#include <iostream>
using namespace std;
char arr[12][6];
int dustho[12][6] = { 0 };
int visited[12][6] = { 0 };
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int puyo = 0;
void visitedclear() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			visited[i][j] = 0;
		}
	}
}
void dusthoclear() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			dustho[i][j] = 0;
		}
	}
}
void dfs(int y, int x) {
	visited[y][x] = 1;
	puyo++;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)continue;
		if (visited[ny][nx] == 1)continue;
		if (arr[y][x] == arr[ny][nx])dfs(ny, nx);
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	while (1) {
		int flag = 0;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visitedclear();
				if (arr[i][j] == '.')continue;
				puyo = 0;
				dfs(i, j);
				if (puyo >= 4) {
					flag = 1;
					for (int vi = 0; vi < 12; vi++) {
						for (int vj = 0; vj < 6; vj++) {
							if (visited[vi][vj] == 1)arr[vi][vj] = '.';
						}
					}
				}
			}
		}

		if (flag == 0)break;
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 12; y++) {
				if (arr[y][x] != '.')continue;
				for (int ny = y; ny > 0; ny--) {
					arr[ny][x] = arr[ny - 1][x];
				}
				arr[0][x] = '.';
			}
		}
		ans++;

	}

	cout << ans;
}