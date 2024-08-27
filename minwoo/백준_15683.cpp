#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int>> _map;
vector<pair<int, int>> cctvs;  // cctv의 위치를 저장하는 2차원 pair벡터
int min_blind = 1e9;

const vector<vector<vector<int>>> ccti_directions = {
    {},  // 0번 인덱스는 사용하지 않음
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}, {0, 2}, {1, 3}},
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
    {{0, 1, 2, 3}}
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    cin >> N >> M;
    _map.resize(N, vector<int>(M));  // 사무실 벡터 크기 조정 -> ...왜?
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> _map[i][j];
            if (_map[i][j] >= 1 && _map[i][j] <= 5) {
                cctvs.push_back({ i, j });
            }
        }
    }

    dfs(0, _map);
    cout << min_blind;
    return 0;
}


// GG,,,,
