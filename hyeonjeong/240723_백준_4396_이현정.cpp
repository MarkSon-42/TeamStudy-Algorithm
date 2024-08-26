#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	char amap[10][10];
	char bmap[10][10];

	vector<vector<int>> bomb;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> amap[i][j];
			if (amap[i][j] == '*') {
				bomb.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> bmap[i];
	}

	char cmap[10][10];
	int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bmap[i][j] == '.') {
				cmap[i][j] = '.';
				continue;
			}
			if (amap[i][j] == '*') {
				flag = 1;
				continue;
			}
			int count = 0;
			for (int k = 0; k < 8; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 or nx < 0 or ny >= n or nx >= n) {
					continue;
				}

				if (amap[ny][nx] == '*') {
					count++;
				}
			}
			cmap[i][j] = char(count + 48);
		}
	}

	if (flag) {
		for (int i = 0; i < bomb.size(); i++) {
			cmap[bomb[i][0]][bomb[i][1]] = '*';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cmap[i][j];
		}
		cout << endl;
	}
}