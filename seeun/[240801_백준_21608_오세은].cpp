#include <iostream>
#include <vector>
using namespace std;

// 입력받을 학생 정보
struct student {
	int num;
	int f[4];
};

int N;	// 전체 크기 정보
int Count;	// 앉은 학생 수
student s[4000];	// 학생 정보 배열
int map[25][25] = { 0 };	// 자리 배치
int close[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };		// 인접되어있는 좌표
int sit[4000] = { 0 };		// 앉은 학생(visited)
vector<int> my;		// 앉을 수 있는 자리의 y좌표
vector<int> mx;		// 앉을 수 있는 자리의 x좌표
vector<int> like[4000];		// index : 학생번호, value : 좋아하는 학생 수

// 인접해있는 곳에 좋아하는 친구가 많은 경우
bool closeFriend(int index) {
	int MAX = 0;
	int flag = 0;
	int F[401] = { 0 };
	vector<int> MY;
	vector<int> MX;
	// 특정 학생이 좋아하는 학생 저장
	// index : 학생 번호
	// value : 좋아하는 학생이면 1, 아니면 0
	for (int i = 0; i < 4; i++) {
		F[s[index].f[i]] = 1;
	}

	// 한명도 앉아있는 친구가 없으면 (1,1)
	if (Count == 0) {
		my.push_back(1);
		mx.push_back(1);
		return true;
	}

	// 한 자리씩 돌면서 확인
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			// 빈자리가 아니면 continue
			if (map[y][x] != 0)
				continue;
			int cnt = 0;

			// close 배열에 들어있는 값을 활용하여 인접 배열 확인
			for (int i = 0; i < 4; i++) {
				int dy = y + close[i][0];
				int dx = x + close[i][1];

				// dy, dx가 배열 범위를 벗어나는 경우는 continue
				if (dy < 0 || dx < 0 || dy >= N || dx >= N)
					continue;

				// 인접 자리에 좋아하는 친구가 있으면 count 증가
				if (F[(map[dy][dx])] == 1)
					cnt++;
			}

			// 카운트 값이 max 값보다 큰 경우
			// 저장되어있는 값을 초기화하고 현재 나의 위치를 저장해준다.
			if (cnt > MAX) {
				MAX = cnt;
				MY.clear(); MX.clear();
				MY.push_back(y);
				MX.push_back(x);
			}
			// 카운트 값이랑 max 값이 같은 경우
			// 현재 나의 위치를 저장해준다.
			else if (cnt == MAX) {
				MY.push_back(y);
				MX.push_back(x);
			}
		}
	}

	// 전역 변수에 저장
	my.clear();
	mx.clear();
	for (int i = 0; i < MY.size(); i++) {
		my.push_back(MY[i]);
		mx.push_back(MX[i]);
	}

	// 저장되어 있는 index가 하나이면 무조건 그자리에 앉는다.(return true)
	if (my.size() == 1)
		return true;

	// 저장되어 있는 index가 둘 이상이면 주변 빈자리를 확인한다.(return false)
	else
		return false;
}

// 주변의 빈자리를 확인한다.
void empty() {
	int MAX = 0;
	vector<int> MY;
	vector<int> MX;

	// 기존에 closeFriend 함수에서 저장된 위치만 확인한다.
	for (int i = 0; i < my.size(); i++) {
		int cnt = 0;
		int y = my[i];
		int x = mx[i];
		// 빈자리가 아니면 continue
		if (map[y][x] != 0)
			continue;

		// close 배열에 들어있는 값을 활용하여 인접 배열 확인
		for (int j = 0; j < 4; j++) {
			int dy = y + close[j][0];
			int dx = x + close[j][1];

			// dy, dx가 배열 범위를 벗어나는 경우는 continue
			if (dy < 0 || dx < 0 || dy >= N || dx >= N)
				continue;

			// 인접 자리가 비었으면 count 증가
			if (map[dy][dx] == 0)
				cnt++;
		}

		// 카운트 값이 max 값보다 큰 경우
		// 저장되어있는 값을 초기화하고 현재 나의 위치를 저장해준다.
		if (cnt > MAX) {
			MAX = cnt;
			MY.clear(); MX.clear();
			MY.push_back(y);
			MX.push_back(x);
		}

		// 카운트 값이랑 max 값이 같은 경우
		// 현재 나의 위치를 저장해준다
		if (cnt == MAX) {
			MY.push_back(y);
			MX.push_back(x);
		}
	}
	// 전역 변수에 저장
	my.clear();
	mx.clear();
	for (int i = 0; i < MY.size(); i++) {
		my.push_back(MY[i]);
		mx.push_back(MX[i]);
	}
}

// 앉히는 함수
void seat(int n) {
	// closeFriend의 리턴값이 false이면 empty 함수 실행(저장된 값이 여러개)
	if (closeFriend(n) == false) {
		empty();
	}
	// 저장된 값 중 가장 처음 저장된 자리에 앉는다.
	// 왼쪽 위 부터 순서대로 확인했기 때문에 무조건 0번에 저장된 값이 우선순위이다.
	map[my[0]][mx[0]] = s[n].num;
	sit[s[n].num] = 1;	// n번째 입력된 학생이 앉았음을 저장
	Count++;		// 앉은 학생 수 증가
}

// 만족도 계산하는 함수
void result() {
	int sum = 0;
	// 전체 자리를 하나씩 확인
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int I = map[y][x];
			int cnt = 0;
			// 해당 자리의 인접 자리 확인
			for (int d = 0; d < 4; d++) {
				int dy = y + close[d][0];
				int dx = x + close[d][1];
				// 인접 자리가 범위를 벗어나면 continue
				if (dy < 0 || dx < 0 || dy >= N || dx >= N)
					continue;

				// 인접 자리에 좋아하는 학생이 있으면 카운트 증가
				int F = map[dy][dx];
				for (int i = 0; i < like[I].size(); i++) {
					if (F == like[I][i])
						cnt++;
				}
			}
			// 카운트 값에 대해 최종 만족도 계산
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
	// 만족도 출력
	cout << sum;
}

int main() {
	// 입력
	cin >> N;
	for (int i = 0; i < N * N; i++) {
		cin >> s[i].num;
		for (int j = 0; j < 4; j++) {
			cin >> s[i].f[j];
			// 특정 학생이 좋아하는 학생 저장
			// index : 특정 학생의 번호, value : 좋아하는 학생의 번호
			like[s[i].num].push_back(s[i].f[j]);
		}
		// 앉히는 함수 실행
		seat(i);
	}
	// 결과 계산 함수 실행
	result();
	return 0;
}