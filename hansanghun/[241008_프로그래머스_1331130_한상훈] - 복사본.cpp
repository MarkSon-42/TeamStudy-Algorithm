#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int t, s;
    bool operator<(const Node& a) const {
        if (t == a.t)
            return s > a.s;
        return t > a.t;
    }
};
// SJF (shortest job first 구현) 우선순위 큐 이용
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int Sum = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Node> pq;
    int now = 0;
    for (auto job : jobs)
    {
        while (!pq.empty() && now < job[0]) {
            Node nj = pq.top();
            pq.pop();
            Sum += (now - nj.s) + nj.t;
            now += nj.t;
        }
        if (now < job[0])
        {
            now = job[0];
        }
        pq.push({ job[1],job[0] });
    }
    while (!pq.empty()) {
        Node nj = pq.top();
        pq.pop();
        Sum += (now - nj.s) + nj.t;
        now += nj.t;
    }
    return Sum / jobs.size();
}