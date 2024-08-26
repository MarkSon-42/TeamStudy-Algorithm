#include <iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	//������ ���� , �ð����
	int dy[8] = { -1,-1,-1,0,1,1,1,0 };
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	for (int tc = 0; tc < t; tc++) {

		//45���� ������ ans�迭�� �߽� + d[i]�ڸ��� arr���� �߽� + d[i-1]���� ä���
		// deg���� ������ d[i-(deg/45)] ���� ä���,
		int n, deg;
		cin >> n >> deg;
		vector<vector<int>> arr(n, vector<int>(n));
		vector<vector<int>> ans(n, vector<int>(n, 0));
		//int arr[500][500];
		//int ans[500][500] = { 0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int c = n / 2;
		ans[c][c] = arr[c][c];
		//�߽� + ȸ���ϴ� ������ ���� ä���ִ´�
		for (int p = 1; p <= c; p++) { //8�� �������
			for (int d = 0; d < 8; d++) {//���⺤�͵�����
				int ny = c + p * dy[d];
				int nx = c + p * dx[d];
				// deg���� ������ d[i-(deg/45)] ���� ä��� ,
				//���� ó�� -> (8+i-(deg/45))%8
				int ay = c + p * dy[(8 + d - (deg / 45)) % 8];
				int ax = c + p * dx[(8 + d - (deg / 45)) % 8];
				ans[ny][nx] = arr[ay][ax];
			}
		}
		//ä������ ���� �ڸ� (���� 0) �� �Է¹��� �� ä���ִ´�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] == 0) {
					ans[i][j] = arr[i][j];
				}
			}
		}
		//���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
}