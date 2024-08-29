#include <iostream>
#include <vector>
using namespace std;
int arr[50][10];
int vis[10];
int ord[10];
//int v[10];
int Max = 0;
int N;

void score(int ord[]) {
	int ind = 1;
	int sum = 0;
	int gr[4] = { 0,0,0,0 };
	for (int i = 0; i < N; i++) {
		int outCnt = 0;
		for (int i = 1; i <= 3; i++) gr[i] = 0;
		while (outCnt < 3) { //바보니? outCnt<=3으로 하면 어카누,,,
			int player = ord[ind];
			if (arr[i][player] == 0) {
				outCnt++;
				//cout << '\n';
			}
			else if (arr[i][player] == 1) {
				sum += gr[3];
				for (int j = 3; j >=2; j--) {
					gr[j] = gr[j-1];
				}
				gr[1] = 1;
			}
			else if (arr[i][player] == 2) {
				sum += gr[3];
				sum += gr[2];
				gr[3] = gr[1];
				gr[2] = 1;
				gr[1] = 0;
			}
			else if (arr[i][player] == 3) {
				for (int i = 1; i <= 3; i++) {
					sum += gr[i];
					gr[i] = 0;
				}
				gr[3] = 1;
			}
			else {
				for (int i = 1; i <= 3; i++) {
					sum += gr[i];
					gr[i] = 0;
				}
				sum++;
				//cout << 1 << ' ';
			}
			ind++;
			if (ind > 9) ind = 1;
			
		}
		//cout << '\n';
		//cout << sum << '\n';
		/*for (int j = 1; j <= 9; j++) {
			int player = ord[j];
			arr[i][j]
		}*/
		
	}
	if (Max < sum) {
		Max = sum;
		/*for (int i = 1; i <= 9; i++) {
			cout << ord[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < 4; i++) cout << gr[i] << " ";
		cout << "stop\n";*/
	}
	//Max = max(Max, sum);
}
int tot = 0; 

void func(int cnt) {
	if (cnt == 10) {
		score(ord);
		//for (int i = 1; i <= 9; i++) cout << ord[i] << " ";
		//cout << '\n';
		tot++;
		return;
	}
	if (cnt == 4) {
		ord[cnt] = 1;
		func(cnt + 1);
	}
	else {
		for (int i = 2; i <= 9; i++) {
			if (vis[i] == 1) continue;
			ord[cnt] = i;
			vis[i] = 1;
			/*if (cnt + 1 == 4) cnt++;*/
			func(cnt + 1);
			vis[i] = 0;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;
	ord[4] = 1;
	vis[1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
		}
	}
	func(1);
	
	cout << Max;
}
