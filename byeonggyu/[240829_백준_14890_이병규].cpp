#include <iostream>
using namespace std;
int N, L;
int arr[100][100];
int ksl[100];
void kslreset() {
	for (int i = 0; i < N; i++) {
		ksl[i] = 0;
	}
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	//가로 검사
	for (int i = 0; i < N; i++) {
		kslreset();
		int flag = 0;//flag가 0이면 지나갈 수 있다
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1])continue; //높이가 이전 칸과 같으면
			if (arr[i][j] - arr[i][j - 1] > 1 || arr[i][j] - arr[i][j - 1] < -1) { //높이 차이가 2이상
				flag = 1;
				break;
			}
			if (arr[i][j] == arr[i][j - 1] - 1) {//한칸내리막인경우
				for (int l = 1; l < L; l++) {//flag가 1이되면 경사로를 놓을 수 없는 것
					if (j + l < N && arr[i][j + l] == arr[i][j])continue;
					flag = 1;
					break;
				}
				if (flag == 0) { // 경사로 놓기
					for (int l = 0; l < L; l++) {
						ksl[j + l] = 1;
					}
				}
				if (flag == 1) {
					break;
				}
			}//한칸내리막끝
			if (arr[i][j] == arr[i][j - 1] + 1) {//한칸오르막인경우
				if (L == 1 && ksl[j - 1] == 1)flag = 1;
				for (int l = 1; l < L; l++) {//flag가 1이되면 경사로를 놓을 수 없는 것
					if (j -1- l >=0  && arr[i][j- l-1]== arr[i][j-1]&&ksl[j-l-1]==0&&ksl[j-1]==0)continue;//내리막일때놓은경사로도 없어야 한다
					flag = 1;
					break;
				}
				//지나간길이니까 경사로 안놔도됨
				if (flag == 1) {
					break;
				}
			}//한칸오르막끝
		}//j끝
		if (flag == 0) {
			//cout << "가로" << i << " ";
			ans++;
		}
	}//가로검사끝

	//세로 검사
	for (int j = 0; j < N; j++) {
		kslreset();
		int flag = 0;//flag가 0이면 지나갈 수 있다
		for (int i = 1; i < N; i++) {
			if (arr[i][j] == arr[i-1][j])continue; //높이가 이전 칸과 같으면
			if (arr[i][j] - arr[i-1][j] > 1 || arr[i][j] - arr[i-1][j] < -1) { //높이 차이가 2이상
				flag = 1;
				break;
			}
			if (arr[i][j] == arr[i-1][j] - 1) {//한칸내리막인경우
				for (int l = 1; l < L; l++) {//flag가 1이되면 경사로를 놓을 수 없는 것
					if (i + l < N && arr[i+l][j] == arr[i][j])continue;
					flag = 1;
					break;
				}
				if (flag == 0) { // 경사로 놓기
					for (int l = 0; l < L; l++) {
						ksl[i + l] = 1;
					}
				}
				if (flag == 1) {
					break;
				}
			}//한칸내리막끝
			if (arr[i][j] == arr[i-1][j] + 1) {//한칸오르막인경우
				if (L == 1 && ksl[i - 1] == 1)flag=1;
				for (int l = 1; l < L; l++) {//flag가 1이되면 경사로를 놓을 수 없는 것
					if (i - l-1 >= 0 && arr[i-l-1][j] == arr[i-1][j] && ksl[i -1- l] == 0&&ksl[i-1]==0)continue;//내리막일때놓은경사로도 없어야 한다
					flag = 1;
					break;
				}
				//지나간길이니까 경사로 안놔도됨
				if (flag == 1) {
					break;
				}
			}//한칸오르막끝
		}//i끝
		if (flag == 0) {
			//cout <<"세로" << j << " ";
			ans++;
		}
	}//가로검사끝
	cout << ans;
}