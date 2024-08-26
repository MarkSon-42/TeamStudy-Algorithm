#include <iostream>
#include <vector>
using namespace std;
int arr[22][22];
int N;
vector<int> stu[400];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	cin >> N;
	for (int i = 0; i < N*N; i++) {
		for (int j = 0; j < 5; j++) {
			int temp;
			cin >> temp;
			stu[i].push_back(temp);
		}
	}
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			arr[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 0;
		}
	}

	arr[2][2] = stu[0][0];
	for (int s = 1; s < N * N; s++) {
		int likemax = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] != 0)continue;//빈자리가 아닌 경우
				int likeflag = 0;
				int binjari = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (arr[ny][nx] == -1)continue; //범위 넘어가는 경우
					if (arr[ny][nx] == 0)binjari++;
					//좋아하는놈 있나 검사
					for (int k = 1; k <= 4; k++) {
						if (arr[ny][nx] == stu[s][k])likeflag++;
					}
				}
				//if (likeflag == 0)continue;
				if (likemax > likeflag)continue;
				likemax = likeflag;
			}
		}
		int binjarimax = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] != 0)continue;//빈자리가 아닌 경우
				int likeflag = 0;
				int binjari = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (arr[ny][nx] == -1)continue; //범위 넘어가는 경우
					if (arr[ny][nx] == 0)binjari++;
					//좋아하는놈 있나 검사
					for (int k = 1; k <= 4; k++) {
						if (arr[ny][nx] == stu[s][k])likeflag++;
					}
				}
				if (likeflag < likemax)continue;
				binjarimax = max(binjari, binjarimax);
			}
		}
		int breakflag = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] != 0)continue;//빈자리가 아닌 경우
				int likeflag = 0;
				int binjari = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (arr[ny][nx] == -1)continue; //범위 넘어가는 경우
					if (arr[ny][nx] == 0)binjari++;
					//좋아하는놈 있나 검사
					for (int k = 1; k <= 4; k++) {
						if (arr[ny][nx] == stu[s][k])likeflag++;
					}
				}
				if (likeflag == likemax && binjari == binjarimax) {
					breakflag = 1;
					arr[i][j] = stu[s][0];
					break;
				}
			}
			if (breakflag == 1)break;
		}
	}
	int score = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int scorecount = 0;
			int stuindex = 0;
			for (int k = 0; k < N * N; k++) {
				if (stu[k][0] == arr[i][j]) {
					stuindex = k;
					break;
				}
			}
			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (arr[nx][ny] == -1)continue;
				for (int like = 1; like <= 4; like++) {
					if (stu[stuindex][like] == arr[ny][nx])scorecount++;
				}
			}
			if (scorecount == 1)score += 1;
			if (scorecount == 2)score += 10;
			if (scorecount == 3)score += 100;
			if (scorecount == 4)score += 1000;
		}
	}

	cout << score;
}
