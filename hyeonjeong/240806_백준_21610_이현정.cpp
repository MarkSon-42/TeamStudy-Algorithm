#include <iostream>
#include <queue>

using namespace std;

int N, M;
int MAP[50][50] = { 0, };
int visited_MAP[50][50] = { 0, };// �̹� �� �Դ� ���� ǥ��

// �Է�
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
}

// ������ ������ ��ǥ
queue<int> clouds;
int cloud_init[8] = { N - 1, 0, N - 1, 1, N - 2, 0, N - 2, 1 };
// ������ ������ ��ǥ
queue<int> moved_clouds;
// ��°� ��ǥ
queue<int> rained;

// �̵��� ���� �ʱ�ȭ
void visited_init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visited_MAP[i][j] = 0;
		}
	}
	moved_clouds.empty();
	rained.empty();
}

// �ʱ� ���� ��ǥ ����
void c_init() {
	for (int i = 0; i < 8; i++) {
		clouds.push(cloud_init[i]);
	}
}

// ����迭
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

// ���� �����̱�
void c_move(int dir, int a) {
	while (!clouds.empty()) {
		int y = clouds.front(); clouds.pop();
		int x = clouds.front(); clouds.pop();

		int ny = (y + dy[dir] * a);
		while (ny < 0) {
			ny += N;
		}
		int nx = (x + dx[dir] * a);
		while (nx < 0) {
			nx += N;
		}
		ny %= N;
		nx %= N;
		moved_clouds.push(ny);
		moved_clouds.push(nx);
	}
}

/*�׽�Ʈ��
for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cout << MAP[y][x] << " ";
			}
			cout << endl;
		}
*/

// ��� �� ä���ֱ�
void c_rain() {
	while (!moved_clouds.empty()) {
		int y = moved_clouds.front(); moved_clouds.pop();
		int x = moved_clouds.front(); moved_clouds.pop();

		MAP[y][x]++;
		rained.push(y);
		rained.push(x);
	}
}


// ������ ���׸� ���� �밢�� �迭
int rdy[4] = { -1, -1, 1, 1 };
int rdx[4] = { 1, -1, -1, 1 };

// ������ ����
void water_copy() {
	// üũ
	while (!rained.empty()) {
		int y = rained.front(); rained.pop();
		int x = rained.front(); rained.pop();
		int cnt = 0; // �ֺ� ���ٱ��� üũ

		for (int i = 0; i < 4; i++) {
			int ry = y + rdy[i];
			int rx = x + rdx[i];

			if (ry < 0 or rx < 0 or ry >= N or rx >= N) continue;
			if (MAP[ry][rx] != 0) cnt++;
		}

		visited_MAP[y][x] = cnt;
		if (cnt == 0) visited_MAP[y][x] = -1;

	}

	// ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited_MAP[i][j] > 0) {
				MAP[i][j] += visited_MAP[i][j];
			}
		}
	}
}

// ���� ����
void c_make() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j] >= 2 and visited_MAP[i][j] == 0) {
				MAP[i][j] -= 2;
				clouds.push(i);
				clouds.push(j);
			}
		}
	}
}

// �� ���ϱ�
long long count_ans() {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += MAP[i][j];
		}
	}
	return ans;
}

int main() {
	input();
	c_init();
	for (int i = 0; i < M; i++) {
		int dir, a;
		cin >> dir >> a;
		dir -= 1;
		c_move(dir, a);
		c_rain();
		water_copy();
		c_make();

		visited_init();
	}
	cout << count_ans();
}