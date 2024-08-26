#include <iostream>
using namespace std;
int belt[200];
int robot[100];
int N, K;
int kcnt = 0;
void input() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		cin >> belt[i];
	}
}
void rotate_belt_and_robot() {
	int temp = belt[2 * N - 1];
	for (int i = 2 * N - 1; i >= 1; i--) {
		belt[i] = belt[i - 1];
	}
	belt[0] = temp;
	for (int i = N - 1; i >= 1; i--) {
		robot[i] = robot[i - 1];
	}
	robot[0] = 0;
}
void move_robot() {
	robot[N - 1] = 0; //맨 끝 로봇 떨어짐
	for (int i = N - 2; i >= 1; i--) {
		if (robot[i] == 0)continue;//로봇없으면
		if (robot[i + 1] == 1)continue; //다음위치에 로봇이 있으면
		if (belt[i + 1] == 0)continue;//다음위치 내구도 0이면
		robot[i + 1] = 1;//로봇 옮기기
		robot[i] = 0;
		belt[i + 1]--;
		if (belt[i + 1] == 0)kcnt++;
	}
}
void put_robot() {
	if (belt[0] > 0) {
		robot[0] = 1;
		belt[0]--;
		if (belt[0] == 0)kcnt++;
	}
}
int main() {
	int lv = 0;
	input();
	while (kcnt < K) {
		lv++;
		rotate_belt_and_robot();
		move_robot();
		put_robot();
	}
	cout << lv;
}