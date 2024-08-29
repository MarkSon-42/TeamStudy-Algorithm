#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> v;//선수 순서
int enings[50][9];
int ru[4] = { 0 };
int visited[9] = { 0 };
int ans = 0;
int score = 0;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> enings[i][j];
		}
	}
}
int printcnt = 1;
void baseball() {
	score = 0;
	int taja = 0;
	for (int ening = 0; ening < N; ening++) {
		int outcnt = 0;
		for (int i = 0; i < 4; i++) {//루 초기화
			ru[i] = 0;
		}
		while (outcnt < 3) {
			if (enings[ening][v[taja]] == 0) outcnt++;//아웃
			else if (enings[ening][v[taja]] == 1) { //1루타
				if (ru[3] == 1) {//3루수 점수
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2루수3루로
					ru[3] = 1;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1루수2루로
					ru[2] = 1;
					ru[1] = 0;
				}
				ru[1] = 1;//타자진루
			}
			else if (enings[ening][v[taja]] == 2) {//2루타
				if (ru[3] == 1) {//3루수 점수
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2루수점수
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1루수3루로
					ru[3] = 1;
					ru[1] = 0;
				}
				ru[2] = 1;//타자진루
			}
			else if (enings[ening][v[taja]] == 3) {//3루타
				if (ru[3] == 1) {//3루수 점수
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2루수점수
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1루수점수
					score++;
					ru[1] = 0;
				}
				ru[3] = 1;//타자진루
			}
			else if (enings[ening][v[taja]] == 4) {
				for (int i = 1; i < 4; i++) {//루 선수 점수
					if (ru[i] == 1) {
						score++;
						ru[i] = 0;
					}
				}
				score++;//타자점수
			}
			if (printcnt == 0) {
				cout << "타자" << taja << "이닝" << ening << "아웃" << outcnt << "점수" << score << "\n";
			}
			taja = (taja + 1) % 9;
		}//while문끝
	}//ening for문 끝
}//야구 함수 끝

void func(int now) {
	if (now == 9) {
		baseball();
		ans = max(ans, score);
		if (printcnt == 0) {
			for (int i = 0; i < 9; i++) {
				cout << v[i];
			}
			cout << "\n";
			printcnt++;
		}
		return;
	}
	if (now == 3) {
		v.push_back(0);
		func(now + 1);
		v.pop_back();
	}
	for (int i = 0; i < 9; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		v.push_back(i);
		func(now + 1);
		v.pop_back();
		visited[i] = 0;
	}
}
int main() {
	visited[0] = 1;
	input();
	func(0);
	cout << ans;
}