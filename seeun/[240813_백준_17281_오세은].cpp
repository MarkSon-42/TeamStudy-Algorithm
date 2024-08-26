#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int score[51][10];
int nowPlaying;
int order[10];
int result;
int out;
int MAX;
int base[3];

void cal() {
	result = 0;
	nowPlaying = 0;
	for (int play = 1; play <= N; play++) {
		out = 0;
		fill(base, base + 3, 0); // 베이스 초기화
		while (out < 3) {
			nowPlaying = (nowPlaying) % 9 + 1;
			int state = score[play][order[nowPlaying]];
			if (state == 0) {
				out++;
			}
			else {
				if (state == 4) {
					result++;
					for (int i = 0; i < 3; i++) {
						if (base[i] > 0) {
							result++;
							base[i] = 0;
						}
					}
				}
				else {
					for (int i = 2; i >= 0; i--) {
						if (i + state > 2) {
							result += base[i];
						}
						else {
							base[i + state] = base[i];
						}
						base[i] = 0;
					}
					base[state - 1] = 1; // 타자는 상태에 따라 베이스로 진입
				}
			}
		}
	}
	MAX = max(MAX, result);
}

int main() {
	cin >> N;
	for (int play = 1; play <= N; play++) {
		for (int j = 1; j <= 9; j++) {
			cin >> score[play][j];
		}
	}

	vector<int> player = { 2, 3, 4, 5, 6, 7, 8, 9 }; // 1번 선수는 4번 타순에 고정
	do {
		order[4] = 1; // 1번 선수를 4번 타자로 고정
		for (int i = 0, j = 1; i < player.size(); i++) {
			if (j == 4) j++; // 4번은 이미 1번 선수로 고정
			order[j++] = player[i];
		}
		cal();
	} while (next_permutation(player.begin(), player.end()));

	cout << MAX;
	return 0;
}