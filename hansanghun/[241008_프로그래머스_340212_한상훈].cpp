#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// dfs 단순구현후 정렬
bool visited[100] = { false };
int cnt = 0;
void dfs(int now, vector<int>& cards) {
    visited[now] = true;
    cnt++;
    if (visited[cards[now] - 1])
        return;
    else
        dfs(cards[now] - 1, cards);
}
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> ans;
    for (int i = 0; i < cards.size(); i++) {
        if (!visited[i]) {
            cnt = 0;
            dfs(i, cards);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() > 1)
        answer = ans[ans.size() - 1] * ans[ans.size() - 2];

    return answer;
}