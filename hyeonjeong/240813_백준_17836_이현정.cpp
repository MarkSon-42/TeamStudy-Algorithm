#include <iostream>
#include <vector>

using namespace std;
int N; // 이닝 수
int MAP[50][9]; // 주어진 점수들
int chMAP[50][9]; // 자리를 바꾼 후
int cur_num = 0; // 현재 타자
int ans = 0;// 최종 정답

// 입력
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> MAP[i][j];
		}
	}
}

// 해당 자리에 집어넣기
void take_seat(int a, int b) {
	for (int i = 0; i < N; i++) {
		chMAP[i][b] = MAP[i][a];
	}
}

int used_number[9] = { -1, -1, -1, 0, -1, -1, -1, -1, -1 };

// 이닝 n의 점수 구하기
int cal_scores(int n) {
	int fouls = 0, score = 0;
	vector<int> q;
	while (true) {
		int cur_score = chMAP[n][cur_num];
		if (cur_score == 0) {
			cur_num = (cur_num + 1) % 9;
			fouls++;
			if (fouls == 3) break;
			else continue;
		}

		q.push_back(cur_score);
		cur_num = (cur_num + 1) % 9;
	}
	int tmp = 0;
	for (int i = q.size() - 1; i >= 0; i--) {
		tmp += q[i];
		if (tmp > 3) {
			score = i + 1;
			break;
		}
	}
	return score;
}

void put_number(int a) {
	if (a == 9) {
		for (int i = 0; i < 9; i++) {
			take_seat(i, used_number[i]);
		}
		int tmp_ans = 0;
		for (int n = 0; n < N; n++) {
			tmp_ans += cal_scores(n);
		}
		if (tmp_ans > ans) ans = tmp_ans;
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (used_number[i] != -1) continue;
		used_number[i] = a;
		put_number(a + 1);
		used_number[i] = -1;
	}
}

int main() {
	input();
	put_number(1);
	cout << ans;
}