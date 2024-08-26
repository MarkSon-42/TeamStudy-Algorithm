#include <iostream>
#include <vector>

using namespace std;

int N, K;
int ans; // 몇 단계 진행
int stp, edp; // 올리는 곳, 내리는곳 edp = (stp+N)%(2*N)
vector<int> conveys;
int robots[200] = { 0, }; // 로봇이 타있는 칸
int zeros; // 내구도 0인 칸 체크


void input() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int tmp;
		cin >> tmp;
		conveys.push_back(tmp);
	}
	stp = 0;
	edp = N - 1;
}

void step1() {
	stp = (stp - 1 + 2 * N) % (2 * N);
	edp = (edp - 1 + 2 * N) % (2 * N);
	robots[edp] = 0;
}

void step2() {
	if (edp < stp) edp = edp + 2 * N;
	for (int i = edp - 1; i >= stp; i--) {

		if (conveys[(i + 1) % (2 * N)] == 0) continue;
		if (robots[(i + 1) % (2 * N)] == 1) continue;
		if (robots[i % (2 * N)] == 0) continue;
		robots[i % (2 * N)] = 0; robots[(i + 1) % (2 * N)] = 1;
		conveys[(i + 1) % (2 * N)]--;
		if (conveys[(i + 1) % (2 * N)] == 0) zeros++;
	}
	robots[edp % (2 * N)] = 0;
}

void step3() {
	if (conveys[stp] != 0) {
		conveys[stp]--;
		robots[stp] = 1;
		if (conveys[stp] == 0) zeros++;
	}
}

int main() {
	ans = 1;
	zeros = 0;
	input();
	while (true) {

		step1();
		step2();
		step3();
		if (zeros >= K) break;

		ans++;
	}

	cout << ans;
}