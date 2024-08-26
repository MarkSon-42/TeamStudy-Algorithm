#include <iostream>
#include <vector>

using namespace std;

long long map[499][499] = { 0, };
long long mmap[499][499] = { 0, };

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, d;
		cin >> n >> d;

		int times = d / 45; // �� �� ������ �ϴ���
		if (times < 0) times *= (-1);

		// ���� �迭
		map[499][499] = { 0, };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		// �ȵ��� ��
		if (d == 0) continue;

		// ���� �ð�������� ������
		if (d > 0) {
			for (int k = 0; k < times; k++) {
				mmap[499][499] = { 0, };

				// ��Ģ�� ���� �̵�
				for (int i = 0; i < n; i++) {
					mmap[i][n / 2] = map[i][i];
					mmap[i][n - 1 - i] = map[i][n / 2];
					mmap[n / 2][n - 1 - i] = map[i][n - 1 - i];
					mmap[n - 1 - i][n - 1 - i] = map[n / 2][n - 1 - i];
				}

				// �迭 �����鼭 ����
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (mmap[i][j] == 0) continue;
						map[i][j] = mmap[i][j];
					}
				}

			}
		}

		// ���� �ݽð�������� ������
		if (d < 0) {
			for (int k = 0; k < times; k++) {
				mmap[499][499] = { 0, };

				// ��Ģ�� ���� �̵�
				for (int i = 0; i < n; i++) {
					mmap[n / 2][i] = map[i][i];
					mmap[n - 1 - i][i] = map[n / 2][i];
					mmap[n - 1 - i][n / 2] = map[n - 1 - i][i];
					mmap[n - 1 - i][n - 1 - i] = map[n - 1 - i][n / 2];
				}

				// �迭 �����鼭 ����
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (mmap[i][j] == 0) continue;
						map[i][j] = mmap[i][j];
					}
				}

			}
		}


		// ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}
}