#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[8][8];
int arr1[8][8];
int dy[4] = { 0,1,0,-1 };//우하좌상
int dx[4] = { 1,0,-1,0 };
int cctv = 0;
int ans = 64;
vector<int> v; // cctv방향 저장
void clearmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr1[i][j] = arr[i][j];
		}
	}
}
void gamsi() {//감시가능 구역에 7
	int cctvnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			//cout << cctvnum << "\n";
			if (arr1[i][j] == 0 || arr1[i][j] == 7 || arr1[i][j] == 6)continue;
			if (arr1[i][j] == 1) {
				for (int p = 1; p < 8; p++) {
					int ny = i + dy[v[cctvnum]]*p;
					int nx = j + dx[v[cctvnum]]*p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
			}
			if (arr1[i][j] == 2) {
				for (int p = 1; p < 8; p++) {//한방향
					int ny = i + dy[v[cctvnum]]*p;
					int nx = j + dx[v[cctvnum]]*p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
				for (int p = 1; p < 8; p++) {//반대방향
					int ny = i + dy[(v[cctvnum]+2)%4]*p;
					int nx = j + dx[(v[cctvnum]+2)%4]*p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
			}
			if (arr1[i][j] == 3) {
				for (int p = 1; p < 8; p++) {//한방향
					int ny = i + dy[v[cctvnum]] * p;
					int nx = j + dx[v[cctvnum]] * p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
				for (int p = 1; p < 8; p++) {//옆방향
					int ny = i + dy[(v[cctvnum] + 1) % 4] * p;
					int nx = j + dx[(v[cctvnum] + 1) % 4] * p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
			}
			if (arr1[i][j] == 4) {
				for (int p = 1; p < 8; p++) {//한방향
					int ny = i + dy[v[cctvnum]] * p;
					int nx = j + dx[v[cctvnum]] * p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
				for (int p = 1; p < 8; p++) {//옆방향
					int ny = i + dy[(v[cctvnum] + 1) % 4] * p;
					int nx = j + dx[(v[cctvnum] + 1) % 4] * p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
				for (int p = 1; p < 8; p++) {//반대방향
					int ny = i + dy[(v[cctvnum] + 2) % 4] * p;
					int nx = j + dx[(v[cctvnum] + 2) % 4] * p;
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
					if (arr1[ny][nx] == 6)break;//벽
					if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
					arr1[ny][nx] = 7;
				}
			}//4끝
			if (arr1[i][j] == 5) {
				for (int d = 0; d < 4; d++) {
					for (int p = 1; p < 8; p++) {
						int ny = i + dy[d]*p;
						int nx = j + dx[d]*p;
						if (ny < 0 || ny >= N || nx < 0 || nx >= M)break;//범위 밖
						if (arr1[ny][nx] == 6)break;//벽
						if (arr1[ny][nx] > 0 && arr1[ny][nx] < 6)continue;//cctv를 만나면
						arr1[ny][nx] = 7;
					}
				}
			}//5끝
			cctvnum++;
		}//j끝
	}//i끝
}
int countzero() {
	int zcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr1[i][j] == 0)zcnt++;
		}
	}
	return zcnt;
}
void dfs(int now) {
	if (now == cctv) {
		clearmap();
		gamsi();
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << arr1[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/
		int z = countzero();
		if (ans > z)ans = z;
		return;
	}
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		dfs(now + 1);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] < 6)cctv++;
		}
	}
	dfs(0);
	cout << ans;
}