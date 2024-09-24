#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char board[9][8][9]; // 맵을 8개 모두 만든다.
bool visited[9][8][8] = { false }; // 8개의 맵에대한 visited
int N = 8;
void make_board() { //맵을 8개 만든다.

	for (int k = 1; k <= 8; k++) {
		for (int i = 0; i < N-1; i++) {
			for (int j = 0; j < N; j++) {
				board[k][i][j] = board[k - 1][i + 1][j];
			}
		}
	}
}

struct Coord {
	int d, x, y;
};
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };

int bfs() {
	queue<Coord> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		int d = q.front().d;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (x == 7 && y == 7) // 맨 위 오른쪽에 도착하면
			return 1;
		if (board[d][x][y] == '#') // 있는곳이 벽으로 막히면 건너뛴다.
			continue;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8&& board[d][nx][ny]!='#') {
				int nd = min(8, d + 1); //8초과하면 8로 조정한다.
				if (!visited[nd][nx][ny]) {
					visited[nd][nx][ny] = true;
					q.push({ nd,nx,ny });
				}
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 7; i >= 0; i--) // 맨밑이 0,0을 하기위해 아래서 부터 받는다.
		cin >> board[0][i];
	make_board();
	cout << bfs();
}