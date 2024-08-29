#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> v;//���� ����
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
		for (int i = 0; i < 4; i++) {//�� �ʱ�ȭ
			ru[i] = 0;
		}
		while (outcnt < 3) {
			if (enings[ening][v[taja]] == 0) outcnt++;//�ƿ�
			else if (enings[ening][v[taja]] == 1) { //1��Ÿ
				if (ru[3] == 1) {//3��� ����
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2���3���
					ru[3] = 1;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1���2���
					ru[2] = 1;
					ru[1] = 0;
				}
				ru[1] = 1;//Ÿ������
			}
			else if (enings[ening][v[taja]] == 2) {//2��Ÿ
				if (ru[3] == 1) {//3��� ����
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2�������
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1���3���
					ru[3] = 1;
					ru[1] = 0;
				}
				ru[2] = 1;//Ÿ������
			}
			else if (enings[ening][v[taja]] == 3) {//3��Ÿ
				if (ru[3] == 1) {//3��� ����
					score++;
					ru[3] = 0;
				}
				if (ru[2] == 1) {//2�������
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {//1�������
					score++;
					ru[1] = 0;
				}
				ru[3] = 1;//Ÿ������
			}
			else if (enings[ening][v[taja]] == 4) {
				for (int i = 1; i < 4; i++) {//�� ���� ����
					if (ru[i] == 1) {
						score++;
						ru[i] = 0;
					}
				}
				score++;//Ÿ������
			}
			if (printcnt == 0) {
				cout << "Ÿ��" << taja << "�̴�" << ening << "�ƿ�" << outcnt << "����" << score << "\n";
			}
			taja = (taja + 1) % 9;
		}//while����
	}//ening for�� ��
}//�߱� �Լ� ��

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