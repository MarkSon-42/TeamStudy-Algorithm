// 지도의 각 칸에는 그 곳의 높이가 있음
// 지도에서 지나갈 수 있는 길이 몇 개 있는지 구하려고 함
// '길' -> 한 행 또는 한 열 전부를 나타냄..
//  한쪽 끝에서 다른쪽 끝까지 (양방향인듯)
// 6 * 6 길은 2 * 6 = 12개가 있음.
// 길을 지나갈 수 있으려면..
// 1. 길에 속한 모든 칸의 높이가 모두 같아야 한다 -> 이걸 선처리 해서
// 2. 혹은 경사로를 놓아서 지나갈 수 있는 길을 만듬

// 경사로 '높이'는 항상 1. 길이는 L이다.
// 개수는 무한개임..
// 경사로는 낮은칸과 높은칸 연결

// #######아래와 같은 조건을 만족###########
// 1. 경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야
// 2. 낮은칸과 높은 칸의 높이 차이가 1이 아닌 경우
// 3. 낮은 지점의 칸의 높이가 모두 같지 않거나, 
// 4. L개가 연속되지 않은 경우 <- 이거때문인듯...

#include <iostream>
#include <cmath>

using namespace std;

int N, L;
int mtx1[101][101];
int mtx2[101][101];
int ans = 0;

void roadCnt(int mtx[][101]) {
	// 가로 길을 확인하는 함수
	for (int i = 0; i < N; i++) {
		bool slope[101] = { 0 };  // 경사로 여부 (visited같은..)
		bool possible = true;
		for (int j = 0; j < N - 1; j++) {
			if (abs(mtx[i][j] - mtx[i][j + 1]) > 1) {
				possible = false;
				break;
			}

			// 뭔말인지는 알겠는데 내일 또 봐야겠음 ;
			
			// 2. 경사로를 위에서 아래로 설치할 때
			// 여기 아래부분 로직이 이해가 안감 45번라인부터.. 
			if (mtx[i][j] == mtx[i][j + 1] + 1) {
				int curr_height = mtx[i][j + 1];  // 낮은 쪽의 높이를 저장
				for (int k = j + 2; k < j + 1 + L; k++) {  // 이미 앞서 j+1까지 확인 했으므로 j + 2부터 시작..
					if(k >= N || mtx[i][k] != curr_height) {  //
					// 경사로를 놓은 구간이 지도 밖으로 나가거나, 높이가 일정하지 않으면 false
						possible = false;
						break;
					}
				}
				if (possible) {
					slope[j + L] = true;
				}
				else {
					break;
				}
			}
			if (mtx[i][j] == mtx[i][j + 1] - 1) {
				int curr_height = mtx[i][j];
				for (int k = j; k < j - L; k--) {
					if (k < 0 || mtx[i][k] != curr_height || slope[k]) {
						// L만큼의 여유와 경사로 설치 여부를 확인
						possible = false;
						break;
					}
				}
				if (!possible) {
					break;
				}
			}
		}
		if (possible) {
			ans++;
		}
	}
}



int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mtx1[i][j];  // 지도 입력 받고
			mtx2[j][i] = mtx1[i][j];  // 가로 지도를 뒤집어서 세로 지도도 만들기
		}
	}
	roadCnt(mtx1);
	roadCnt(mtx2);

	cout << ans << endl;


	
	return 0;
}
