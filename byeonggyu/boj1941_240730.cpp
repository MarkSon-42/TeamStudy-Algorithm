#include <iostream>
using namespace std;
char arr[5][6];
int used[5][5] = { 0 };
int ans[7][2] = { 0 };
int graph[5][5] = { 0 };
int graphv[5][5] = { 0 };
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 0;
int scount = 0;
int injup(int y1, int x1, int y2, int x2) {//1과 2가 인접하면 1
	if (y1 == y2) {
		if (x1 - x2 == 1 || x1 - x2 == -1)return 1;
	}
	if (x1 == x2) {
		if (y1 - y2 == 1 || y1 - y2 == -1)return 1;
	}
	return 0;
}
int incount = 0;
void dfs1(int y, int x) {
	graphv[y][x] = 1;
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && graphv[ny][nx] == 0 && graph[ny][nx] == 1) {
			dfs1(ny, nx);
		}
	}
}

void dfs(int level, int y, int x) {
	if (level == 7) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				graph[i][j] = 0;
				graphv[i][j] = 0;
			}
		}
		for (int i = 0; i < 7; i++) {
			int y = ans[i][0];
			int x = ans[i][1];
			graph[y][x] = 1;
		}
		incount = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (graphv[i][j] == 0 && graph[i][j] == 1) {
					incount++;
					dfs1(i, j);
				}
			}
		}
		if (incount != 1)return;
		if (scount >= 4) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (level > 0 && i < y)continue;
		for (int j = 0; j < 5; j++) {
			if (level > 0 && i == y && j < x)continue;
			/*if (level > 0) {
				int injupflag = 0;
				for (int k = 0; k < level; k++) {
					if (injup(ans[k][0], ans[k][1], i, j) == 1) {
						injupflag = 1;
					}
				}
				if (injupflag == 0)continue;
			}*/
			if (used[i][j] == 1)continue;
			used[i][j] = 1;
			ans[level][0] = i;
			ans[level][1] = j;
			if (arr[i][j] == 'S')scount++;

			dfs(level + 1, i, j);
			if (arr[i][j] == 'S')scount--;
			used[i][j] = 0;
			ans[level][0] = 0;
			ans[level][1] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	dfs(0, 0, 0);
	cout << cnt;
}