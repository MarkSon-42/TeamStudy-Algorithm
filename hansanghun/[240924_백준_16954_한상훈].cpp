#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char board[9][8][9]; // ���� 8�� ��� �����.
bool visited[9][8][8] = { false }; // 8���� �ʿ����� visited
int N = 8;
void make_board() { //���� 8�� �����.

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
		if (x == 7 && y == 7) // �� �� �����ʿ� �����ϸ�
			return 1;
		if (board[d][x][y] == '#') // �ִ°��� ������ ������ �ǳʶڴ�.
			continue;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8&& board[d][nx][ny]!='#') {
				int nd = min(8, d + 1); //8�ʰ��ϸ� 8�� �����Ѵ�.
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
	for (int i = 7; i >= 0; i--) // �ǹ��� 0,0�� �ϱ����� �Ʒ��� ���� �޴´�.
		cin >> board[0][i];
	make_board();
	cout << bfs();
}