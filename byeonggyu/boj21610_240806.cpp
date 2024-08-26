#include <iostream>
#include <vector>
using namespace std;
int graph[51][51];
int temp[51][51] = { 0 };
vector<vector<int>> cloud;
vector<vector<int>> gogo;
int dy[9] = { 0, 0,-1,-1,-1,0,1,1,1 };//대각선 2,4,6,8
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });
	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
		gogo.push_back({ d,s });
	}
	for (int i = 0; i < M; i++) {//명령

		for (int j = 0; j < cloud.size(); j++) {//구름
			//구름 이동 후 비내리기
			cloud[j][0] = (N * 100 + cloud[j][0] + dy[gogo[i][0]] * gogo[i][1]) % N;
			cloud[j][1] = (N * 100 + cloud[j][1] + dx[gogo[i][0]] * gogo[i][1]) % N;
			graph[cloud[j][0]][cloud[j][1]] += 1;
			temp[cloud[j][0]][cloud[j][1]] = 1;//구름이 있던 곳 표시
		}
		for (int j = 0; j < cloud.size(); j++) {
			int daegak = 0;
			for (int d = 2; d < 9; d += 2) {
				int ny = cloud[j][0] + dy[d];
				int nx = cloud[j][1] + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
				if (graph[ny][nx] > 0)daegak++;
			}
			graph[cloud[j][0]][cloud[j][1]] += daegak;
		}

		cloud.resize(0);//구름 제거
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (temp[y][x] == 1)continue;//구름이 있던곳 넘기기
				if (graph[y][x] >= 2) { //새로운 구름
					cloud.push_back({ y,x });
					graph[y][x] -= 2;
				}
			}
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				temp[y][x] = 0;
			}
		}
	}
	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			ans += graph[y][x];
		}
	}
	cout << ans;
}
