#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Node {
	int y, x, t;
};
int dy[9] = { 0,0,1,1,1,0,-1,-1,-1 };
int dx[9] = { 0,1,1,0,-1,-1,-1,0,1 };
string map[9][8];
int visited[8][8] = { 0 };
int main() {
	for (int i = 0; i < 8; i++) {
		cin >> map[0][i];
	}
	for (int i = 1; i<9; i++) {
		for (int j = 1; j < 8; j++) {
			map[i][8 - j] = map[i-1][8 - j - 1];
		}
		map[i][0] += "........";
	}
	queue<Node> q;
	q.push({ 7,0,0 });
	visited[7][0] = 1;
	int ans = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();
		if (now.t == 8) {
			ans = 1;
			continue;
		}
		
		if (now.t < 9 && map[now.t][now.y][now.x] == '#')continue;
		for (int d = 0; d < 9; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			int nt = now.t + 1;
			if (nt == 8) {
				ans = 1;
				continue;
			}
			if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8)continue;
			if (map[now.t][ny][nx] == '#') continue;
			 q.push({ ny,nx,nt });
		}
	}
	cout << ans;
}
