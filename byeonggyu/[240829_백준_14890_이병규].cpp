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
	//���� �˻�
	for (int i = 0; i < N; i++) {
		kslreset();
		int flag = 0;//flag�� 0�̸� ������ �� �ִ�
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1])continue; //���̰� ���� ĭ�� ������
			if (arr[i][j] - arr[i][j - 1] > 1 || arr[i][j] - arr[i][j - 1] < -1) { //���� ���̰� 2�̻�
				flag = 1;
				break;
			}
			if (arr[i][j] == arr[i][j - 1] - 1) {//��ĭ�������ΰ��
				for (int l = 1; l < L; l++) {//flag�� 1�̵Ǹ� ���θ� ���� �� ���� ��
					if (j + l < N && arr[i][j + l] == arr[i][j])continue;
					flag = 1;
					break;
				}
				if (flag == 0) { // ���� ����
					for (int l = 0; l < L; l++) {
						ksl[j + l] = 1;
					}
				}
				if (flag == 1) {
					break;
				}
			}//��ĭ��������
			if (arr[i][j] == arr[i][j - 1] + 1) {//��ĭ�������ΰ��
				if (L == 1 && ksl[j - 1] == 1)flag = 1;
				for (int l = 1; l < L; l++) {//flag�� 1�̵Ǹ� ���θ� ���� �� ���� ��
					if (j -1- l >=0  && arr[i][j- l-1]== arr[i][j-1]&&ksl[j-l-1]==0&&ksl[j-1]==0)continue;//�������϶��������ε� ����� �Ѵ�
					flag = 1;
					break;
				}
				//���������̴ϱ� ���� �ȳ�����
				if (flag == 1) {
					break;
				}
			}//��ĭ��������
		}//j��
		if (flag == 0) {
			//cout << "����" << i << " ";
			ans++;
		}
	}//���ΰ˻糡

	//���� �˻�
	for (int j = 0; j < N; j++) {
		kslreset();
		int flag = 0;//flag�� 0�̸� ������ �� �ִ�
		for (int i = 1; i < N; i++) {
			if (arr[i][j] == arr[i-1][j])continue; //���̰� ���� ĭ�� ������
			if (arr[i][j] - arr[i-1][j] > 1 || arr[i][j] - arr[i-1][j] < -1) { //���� ���̰� 2�̻�
				flag = 1;
				break;
			}
			if (arr[i][j] == arr[i-1][j] - 1) {//��ĭ�������ΰ��
				for (int l = 1; l < L; l++) {//flag�� 1�̵Ǹ� ���θ� ���� �� ���� ��
					if (i + l < N && arr[i+l][j] == arr[i][j])continue;
					flag = 1;
					break;
				}
				if (flag == 0) { // ���� ����
					for (int l = 0; l < L; l++) {
						ksl[i + l] = 1;
					}
				}
				if (flag == 1) {
					break;
				}
			}//��ĭ��������
			if (arr[i][j] == arr[i-1][j] + 1) {//��ĭ�������ΰ��
				if (L == 1 && ksl[i - 1] == 1)flag=1;
				for (int l = 1; l < L; l++) {//flag�� 1�̵Ǹ� ���θ� ���� �� ���� ��
					if (i - l-1 >= 0 && arr[i-l-1][j] == arr[i-1][j] && ksl[i -1- l] == 0&&ksl[i-1]==0)continue;//�������϶��������ε� ����� �Ѵ�
					flag = 1;
					break;
				}
				//���������̴ϱ� ���� �ȳ�����
				if (flag == 1) {
					break;
				}
			}//��ĭ��������
		}//i��
		if (flag == 0) {
			//cout <<"����" << j << " ";
			ans++;
		}
	}//���ΰ˻糡
	cout << ans;
}