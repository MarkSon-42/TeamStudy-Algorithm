#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int E = 0;
char Map[50][51];
int G[7][7];
bool visited[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int answer = 1000000;
struct Coord {
	int x, y;
};
Coord ef[5];
Coord s;
Coord e;
struct Pos {
	int d, x, y;
};
void bfs(Coord now, int num) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	queue<Pos> q;
	q.push({ 0,now.x,now.y });
	visited[now.x][now.y] = true;
	while (!q.empty()) {
		int d = q.front().d;
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		if (Map[x][y] >= '0' && Map[x][y] <= '6')
		{
			int dis = Map[x][y] - '0';
			G[num][dis] = d;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && Map[nx][ny] != '#') {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ d + 1,nx,ny });
				}
			}
		}
	}
}
bool sel[5] = { false };
void dfs(int depth, vector<int>& v) {
	if (depth == E) {
		int start = 0;
		int end = E + 1;
		int result = 0;
		for (int i : v) {
			result += G[start][i + 1];
			start = i + 1;
		}
		result += G[start][end];
		if (answer > result)
			answer = result;
		return;
	}
	for (int i = 0; i < E; i++)
	{
		if (!sel[i])
		{
			sel[i] = true;
			v.push_back(i);
			dfs(depth + 1, v);
			sel[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> Map[i];
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 'S') {
				Map[i][j] = '0';
				s = { i,j };
			}
			else if (Map[i][j] == 'X') {
				Map[i][j] = '1' + E;
				ef[E] = { i,j };
				E++;
			}
			else if (Map[i][j] == 'E') {
				e = { i,j };
			}
		}
	}
	Map[e.x][e.y] = '1' + E;
	bfs(s, 0);
	bfs(e, E + 1);
	for (int i = 1; i <= E; i++) {
		bfs(ef[i - 1], i);
	}
	vector<int> temp;
	dfs(0, temp);
	cout << answer << "\n";
}