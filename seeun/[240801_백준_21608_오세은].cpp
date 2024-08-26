#include <iostream>
#include <vector>
using namespace std;

// �Է¹��� �л� ����
struct student {
	int num;
	int f[4];
};

int N;	// ��ü ũ�� ����
int Count;	// ���� �л� ��
student s[4000];	// �л� ���� �迭
int map[25][25] = { 0 };	// �ڸ� ��ġ
int close[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };		// �����Ǿ��ִ� ��ǥ
int sit[4000] = { 0 };		// ���� �л�(visited)
vector<int> my;		// ���� �� �ִ� �ڸ��� y��ǥ
vector<int> mx;		// ���� �� �ִ� �ڸ��� x��ǥ
vector<int> like[4000];		// index : �л���ȣ, value : �����ϴ� �л� ��

// �������ִ� ���� �����ϴ� ģ���� ���� ���
bool closeFriend(int index) {
	int MAX = 0;
	int flag = 0;
	int F[401] = { 0 };
	vector<int> MY;
	vector<int> MX;
	// Ư�� �л��� �����ϴ� �л� ����
	// index : �л� ��ȣ
	// value : �����ϴ� �л��̸� 1, �ƴϸ� 0
	for (int i = 0; i < 4; i++) {
		F[s[index].f[i]] = 1;
	}

	// �Ѹ� �ɾ��ִ� ģ���� ������ (1,1)
	if (Count == 0) {
		my.push_back(1);
		mx.push_back(1);
		return true;
	}

	// �� �ڸ��� ���鼭 Ȯ��
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// ���ڸ��� �ƴϸ� continue
			if (map[y][x] != 0)
				continue;
			int cnt = 0;

			// close �迭�� ����ִ� ���� Ȱ���Ͽ� ���� �迭 Ȯ��
			for (int i = 0; i < 4; i++) {
				int dy = y + close[i][0];
				int dx = x + close[i][1];

				// dy, dx�� �迭 ������ ����� ���� continue
				if (dy < 0 || dx < 0 || dy >= N || dx >= N)
					continue;

				// ���� �ڸ��� �����ϴ� ģ���� ������ count ����
				if (F[(map[dy][dx])] == 1)
					cnt++;
			}

			// ī��Ʈ ���� max ������ ū ���
			// ����Ǿ��ִ� ���� �ʱ�ȭ�ϰ� ���� ���� ��ġ�� �������ش�.
			if (cnt > MAX) {
				MAX = cnt;
				MY.clear(); MX.clear();
				MY.push_back(y);
				MX.push_back(x);
			}
			// ī��Ʈ ���̶� max ���� ���� ���
			// ���� ���� ��ġ�� �������ش�.
			else if (cnt == MAX) {
				MY.push_back(y);
				MX.push_back(x);
			}
		}
	}

	// ���� ������ ����
	my.clear();
	mx.clear();
	for (int i = 0; i < MY.size(); i++) {
		my.push_back(MY[i]);
		mx.push_back(MX[i]);
	}

	// ����Ǿ� �ִ� index�� �ϳ��̸� ������ ���ڸ��� �ɴ´�.(return true)
	if (my.size() == 1)
		return true;

	// ����Ǿ� �ִ� index�� �� �̻��̸� �ֺ� ���ڸ��� Ȯ���Ѵ�.(return false)
	else
		return false;
}

// �ֺ��� ���ڸ��� Ȯ���Ѵ�.
void empty() {
	int MAX = 0;
	vector<int> MY;
	vector<int> MX;

	// ������ closeFriend �Լ����� ����� ��ġ�� Ȯ���Ѵ�.
	for (int i = 0; i < my.size(); i++) {
		int cnt = 0;
		int y = my[i];
		int x = mx[i];
		// ���ڸ��� �ƴϸ� continue
		if (map[y][x] != 0)
			continue;

		// close �迭�� ����ִ� ���� Ȱ���Ͽ� ���� �迭 Ȯ��
		for (int j = 0; j < 4; j++) {
			int dy = y + close[j][0];
			int dx = x + close[j][1];

			// dy, dx�� �迭 ������ ����� ���� continue
			if (dy < 0 || dx < 0 || dy >= N || dx >= N)
				continue;

			// ���� �ڸ��� ������� count ����
			if (map[dy][dx] == 0)
				cnt++;
		}

		// ī��Ʈ ���� max ������ ū ���
		// ����Ǿ��ִ� ���� �ʱ�ȭ�ϰ� ���� ���� ��ġ�� �������ش�.
		if (cnt > MAX) {
			MAX = cnt;
			MY.clear(); MX.clear();
			MY.push_back(y);
			MX.push_back(x);
		}

		// ī��Ʈ ���̶� max ���� ���� ���
		// ���� ���� ��ġ�� �������ش�
		if (cnt == MAX) {
			MY.push_back(y);
			MX.push_back(x);
		}
	}
	// ���� ������ ����
	my.clear();
	mx.clear();
	for (int i = 0; i < MY.size(); i++) {
		my.push_back(MY[i]);
		mx.push_back(MX[i]);
	}
}

// ������ �Լ�
void seat(int n) {
	// closeFriend�� ���ϰ��� false�̸� empty �Լ� ����(����� ���� ������)
	if (closeFriend(n) == false) {
		empty();
	}
	// ����� �� �� ���� ó�� ����� �ڸ��� �ɴ´�.
	// ���� �� ���� ������� Ȯ���߱� ������ ������ 0���� ����� ���� �켱�����̴�.
	map[my[0]][mx[0]] = s[n].num;
	sit[s[n].num] = 1;	// n��° �Էµ� �л��� �ɾ����� ����
	Count++;		// ���� �л� �� ����
}

// ������ ����ϴ� �Լ�
void result() {
	int sum = 0;
	// ��ü �ڸ��� �ϳ��� Ȯ��
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int I = map[y][x];
			int cnt = 0;
			// �ش� �ڸ��� ���� �ڸ� Ȯ��
			for (int d = 0; d < 4; d++) {
				int dy = y + close[d][0];
				int dx = x + close[d][1];
				// ���� �ڸ��� ������ ����� continue
				if (dy < 0 || dx < 0 || dy >= N || dx >= N)
					continue;

				// ���� �ڸ��� �����ϴ� �л��� ������ ī��Ʈ ����
				int F = map[dy][dx];
				for (int i = 0; i < like[I].size(); i++) {
					if (F == like[I][i])
						cnt++;
				}
			}
			// ī��Ʈ ���� ���� ���� ������ ���
			if (cnt == 1)
				sum += 1;
			else if (cnt == 2)
				sum += 10;
			else if (cnt == 3)
				sum += 100;
			else if (cnt == 4)
				sum += 1000;
		}
	}
	// ������ ���
	cout << sum;
}

int main() {
	// �Է�
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> s[i].num;
		for (int j = 0; j < 4; j++) {
			cin >> s[i].f[j];
			// Ư�� �л��� �����ϴ� �л� ����
			// index : Ư�� �л��� ��ȣ, value : �����ϴ� �л��� ��ȣ
			like[s[i].num].push_back(s[i].f[j]);
		}
		// ������ �Լ� ����
		seat(i);
	}
	// ��� ��� �Լ� ����
	result();
	return 0;
}