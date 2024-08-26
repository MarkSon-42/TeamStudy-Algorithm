#include <iostream>
#include <vector>
using namespace std;

char map[12][6];	// 게임 필드
int directionY[4] = { 1, 0, 0, -1 };
int directionX[4] = { 0, 1, -1, 0 };
int visited[12][6];
int cnt;
int result;
vector<int> bombY;	// 터뜨려야할 위치(4개 이상일 때)
vector<int> bombX;

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			visited[j][i] = 0;
		}
	}
	cnt = 1;
}

void applyGravity() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] == '.') {
				for (int k = i - 1; k >= 0; k--) {
					if (map[k][j] != '.') {
						map[i][j] = map[k][j];
						map[k][j] = '.';
						break;
					}
				}
			}
		}
	}
}

void Count(int y, int x) {
	char nowColor = map[y][x];
	bombY.push_back(y);
	bombX.push_back(x);
	for (int i = 0; i < 4; i++) {
		int dy = y + directionY[i];
		int dx = x + directionX[i];
		if (dy < 0 || dx < 0 || dy >= 12 || dx >= 6)
			continue;
		if (visited[dy][dx] == 1)
			continue;
		if (map[dy][dx] != nowColor)
			continue;
		visited[dy][dx] = 1;
		cnt++;
		Count(dy, dx);
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		cin >> map[i];

	while (1) {
		bool exploded = false;
		init();

		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] == '.')
					continue;
				if (visited[i][j] == 1)
					continue;

				visited[i][j] = 1;
				Count(i, j);

				if (cnt >= 4) {
					exploded = true;
					for (int k = 0; k < bombY.size(); k++) {
						map[bombY[k]][bombX[k]] = '.';
					}
				}
				bombY.clear(); bombX.clear();
				cnt = 1;
			}
		}
		if (!exploded)
			break;

		applyGravity();
		result++;
	}
	cout << result;
	return 0;
}