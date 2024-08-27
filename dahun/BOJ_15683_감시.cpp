#include <iostream>
#include <vector>
using namespace std;

int N, M;
int world[8][8];
int next_w[8][8];
int dx[] = {1, 0, -1, 0}; // 아래, 오른쪽, 위, 왼쪽
int dy[] = {0, 1, 0, -1};
int ans = 65;
vector<pair<int, int>> cors;
int zeros = 0;

void init() {
    cin >> N >> M;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> world[x][y];
            if (!world[x][y]) zeros++;
        }
    }
}

void find() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (1 <= world[x][y] && world[x][y] <= 5) {
                cors.push_back({x, y});
            }
        }
    }
}

void check() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (next_w[i][j] == 0 && world[i][j] == 0) {
                cnt++;
            }
        }
    }
    ans = min(ans, cnt);
}

void dfs(int idx) {
    if (idx == cors.size()) {
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << next_w[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
        check();
        return;
    }
    
    pair<int, int> now = cors[idx];
    int x = now.first; 
    int y = now.second;
    int trial = world[x][y];

    for (int dir = 0; dir < 4; dir++) {
        int backup[8][8];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                backup[i][j] = next_w[i][j];
            }
        }

        if (trial == 1) {
            int c = 0;
            while (true) {
                int nx = x + dx[dir] * c;
                int ny = y + dy[dir] * c;
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || world[nx][ny] == 6) break;
                next_w[nx][ny] = 1;
                c++;
            }
        } 
        else if (trial == 2) {
            for (int d = 0; d <= 2; d+=2) {
                int c = 0;
                while (true) {
                    int nx = x + dx[(dir + d) % 4] * c;
                    int ny = y + dy[(dir + d) % 4] * c;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || world[nx][ny] == 6) break;
                    next_w[nx][ny] = 1;
                    c++;
                }
            }
        }
        else if (trial == 3) {
            for (int d = 0; d < 2; d++) {
                int c = 0;
                while (true) {
                    int nx = x + dx[(dir + d) % 4] * c;
                    int ny = y + dy[(dir + d) % 4] * c;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || world[nx][ny] == 6) break;
                    next_w[nx][ny] = 1;
                    c++;
                }
            }
        }
        else if (trial == 4) {
            for (int d = 0; d < 3; d++) {
                int c = 0;
                while (true) {
                    int nx = x + dx[(dir + d) % 4] * c;
                    int ny = y + dy[(dir + d) % 4] * c;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || world[nx][ny] == 6) break;
                    next_w[nx][ny] = 1;
                    c++;
                }
            }
        }
        else if (trial == 5) {
            for (int d = 0; d < 4; d++) {
                int c = 0;
                while (true) {
                    int nx = x + dx[d] * c;
                    int ny = y + dy[d] * c;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || world[nx][ny] == 6) break;
                    next_w[nx][ny] = 1;
                    c++;
                }
            }
        }
        dfs(idx + 1);

         //next_w를 backup배열로 다시 변경
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                next_w[i][j] = backup[i][j];
            }
        }
    }
}

int main() {
    init();
    find();
    dfs(0);
    cout << ans << endl;
    return 0;
}

