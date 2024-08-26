#include <iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	//왼쪽위 시작 , 시계방향
	int dy[8] = { -1,-1,-1,0,1,1,1,0 };
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	for (int tc = 0; tc < t; tc++) {

		//45도를 돌리면 ans배열의 중심 + d[i]자리에 arr열의 중심 + d[i-1]값을 채운다
		// deg도를 돌리면 d[i-(deg/45)] 값을 채운다,
		int n, deg;
		cin >> n >> deg;
		vector<vector<int>> arr(n, vector<int>(n));
		vector<vector<int>> ans(n, vector<int>(n, 0));
		//int arr[500][500];
		//int ans[500][500] = { 0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int c = n / 2;
		ans[c][c] = arr[c][c];
		//중심 + 회전하는 부위를 먼저 채워넣는다
		for (int p = 1; p <= c; p++) { //8방 뻗어나가기
			for (int d = 0; d < 8; d++) {//방향벡터돌리기
				int ny = c + p * dy[d];
				int nx = c + p * dx[d];
				// deg도를 돌리면 d[i-(deg/45)] 값을 채운다 ,
				//음수 처리 -> (8+i-(deg/45))%8
				int ay = c + p * dy[(8 + d - (deg / 45)) % 8];
				int ax = c + p * dx[(8 + d - (deg / 45)) % 8];
				ans[ny][nx] = arr[ay][ax];
			}
		}
		//채워지지 않은 자리 (값이 0) 에 입력받은 값 채워넣는다
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] == 0) {
					ans[i][j] = arr[i][j];
				}
			}
		}
		//출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}