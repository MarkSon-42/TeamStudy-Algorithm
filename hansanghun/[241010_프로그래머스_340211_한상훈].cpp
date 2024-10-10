#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int collision[101][101] = { 0 }; //충돌확인
struct Point {
    int x, y;
};
//로봇 구조체
struct Robot {
    int x, y, d, num;
};
// 로봇의 이동
void move(int& nowx, int& nowy, Point go) {
    if (go.x > nowx) {
        nowx += 1;
    }
    else if (go.x < nowx) {
        nowx -= 1;
    }
    else {
        if (nowy > go.y)
        {
            nowy -= 1;
        }
        else if (nowy < go.y) {
            nowy += 1;
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    N = points.size();
    M = routes[0].size();
    queue<Robot> q;
    for (int i = 0; i < routes.size(); i++) {
        int p = routes[i][0] - 1;
        int x = points[p][0];
        int y = points[p][1];
        int num = i;
        q.push({ x,y,1,num });
        collision[x][y] += 1;
    }
    while (!q.empty()) {
        for (int i = 1; i <= 100; i++) { //충돌확인 및 충돌 초기화
            for (int j = 1; j <= 100; j++) {
                if (collision[i][j] > 1)
                    answer += 1;
                collision[i][j] = 0;
            }
        }
        int rest = q.size();
        //로봇들 이동
        for (int i = 0; i < rest; i++) {
            Robot now = q.front();
            q.pop();
            int x = now.x;
            int y = now.y;
            int d = now.d;
            int num = now.num;
            int pn = routes[num][d] - 1;
            int px = points[pn][0];
            int py = points[pn][1];
            if (px == x && py == y && d == M - 1) //다 이동했으면 종료
                continue;
            if (px == x && py == y) { //도착지 이동하면 다음 도착지로 조정
                d += 1;
                pn = routes[num][d] - 1;
                px = points[pn][0];
                py = points[pn][1];
            }
            move(x, y, { px,py }); //이동
            collision[x][y] += 1; // 로봇위치 표시
            q.push({ x,y,d,num }); // 다음 대기준비.
        }
    }
    return answer;
}