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
	robot[N - 1] = 0; //�� �� �κ� ������
	for (int i = N - 2; i >= 1; i--) {
		if (robot[i] == 0)continue;//�κ�������
		if (robot[i + 1] == 1)continue; //������ġ�� �κ��� ������
		if (belt[i + 1] == 0)continue;//������ġ ������ 0�̸�
		robot[i + 1] = 1;//�κ� �ű��
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