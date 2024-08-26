#include <iostream>
#include <queue>
using namespace std;
int N, M, T;
int map[100][100];
int dist[100][100] = { 0 };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
struct Edge {
	int y, x;
};
void bfs(int y, int x) {// dist 값은 최단 시간에 +1된 값
	queue<Edge> q;
	q.push({ y,x });
	dist[y][x] = 1;
	while (!q.empty()) {
		Edge now = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위 밖
			if (map[ny][nx] == 1)continue;//벽
			if (dist[ny][nx] != 0)continue;//이미 방문한곳
			q.push({ ny,nx });
			dist[ny][nx] = dist[now.y][now.x] + 1;
		}
	}//while끝
}

int main() {
	cin >> N >> M >> T;
	int ans;
	Edge gongju = { N - 1,M - 1 };
	Edge gram;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)gram = { i,j };
		}
	}
	bfs(0, 0);
	if (dist[gongju.y][gongju.x] == 0) {//공주한테 벽 안부수면 못가는 경우
		if (dist[gram.y][gram.x] == 0) {//그람에도 못가는 경우
			ans = -1;
		}
		else {
			int gtog = gongju.y - gram.y + gongju.x - gram.x;
			ans = dist[gram.y][gram.x] - 1 + gtog;
		}
	}
	else {//공주한테 그냥 갈 수 있는 경우
		ans = dist[gongju.y][gongju.x] - 1;

		if (dist[gram.y][gram.x] != 0) {//그람에 갈 수 있으면
			int gtog = gongju.y - gram.y + gongju.x - gram.x;
			ans = min(ans, dist[gram.y][gram.x] - 1 + gtog);//그람갖고가기 , 그냥가기중 가까운게 답
		}
	}
	if (ans == -1 || ans > T)cout << "Fail";
	else cout << ans;
}