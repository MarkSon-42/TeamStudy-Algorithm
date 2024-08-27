#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct camera {
	int y;
	int x;
	int num;
};

int N, M;
int map[10][10];
vector<camera> c;
int direction[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector < vector <int>> position[6];
int MAX;
int cnt;
int visited[10][10];

void init() {
	MAX = 0;
	for (int i = 0; i < 4; i++) {
		vector <int> p;
		p.push_back(i);
		position[1].push_back(p);
	}
	for (int i = 0; i < 2; i++) {
		vector <int> p;
		p.push_back(i);
		p.push_back(i + 2);
		position[2].push_back(p);
	}
	for (int i = 0; i < 4; i++) {
		vector <int> p;
		p.push_back(i % 4);
		p.push_back((i + 1) % 4);
		position[3].push_back(p);
	}
	for (int i = 0; i < 4; i++) {
		vector <int> p;
		p.push_back(i % 4);
		p.push_back((i + 1) % 4);
		p.push_back((i + 2) % 4);
		position[4].push_back(p);
	}
	vector <int> p;
	for (int i = 0; i < 4; i++) {
		p.push_back(i);
	}
	position[5].push_back(p);
}

void bfs(int level) {
	if (level == c.size()) {
		if (cnt > MAX) {
			MAX = cnt;
			// cout << MAX << endl;
		}
		return;
	}
	int Y = c[level].y;
	int X = c[level].x;
	int NUM = c[level].num;
	// visited[Y][X] = 1;
	for(int i = 0; i < position[NUM].size(); i++) {
		queue<int> ny;
		queue<int> nx;
		vector<int> dir = position[NUM][i];
		int watch = 0;
		for (int i = 0; i < dir.size(); i++) {
			int d = dir[i];
			for (int j = 1; j < N + M; j++) {
				int dy = Y + direction[d][0] * j;
				int dx = X + direction[d][1] * j;
				if (dy < 0 || dx < 0 || dy >= N || dx >= M) break;
				if (map[dy][dx] == 6) break;
				if (visited[dy][dx] == 1) continue;
				ny.push(dy); nx.push(dx);
				visited[dy][dx] = 1;
				watch++;
			}
		}
		cnt += watch;

		// cout << endl << level << " : " << cnt << endl;

		bfs(level + 1);
		cnt -= watch;
		while (!ny.empty()) {
			int vY = ny.front(); ny.pop();
			int vX = nx.front(); nx.pop();
			visited[vY][vX] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				c.push_back({ i, j, map[i][j] });
			}
			if (map[i][j] > 0) {
				cnt++;
				visited[i][j] = 1;
			}
		}
	}
	init();
	bfs(0);
	cout << ((N * M) - MAX);
	return 0;
}
