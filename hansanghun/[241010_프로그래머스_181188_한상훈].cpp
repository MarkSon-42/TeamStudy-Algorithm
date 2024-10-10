#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// 빨리 끝나는 것을 기준으로 정렬
bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second < b.second;
}


int solution(vector<vector<int>> targets) {
	int answer = 0;
	vector<pair<int, int>> t;
	vector < pair<int, int>> x;

	for (int i = 0; i < targets.size(); i++)
	{
		pair<int, int> temp = make_pair(targets[i][0], targets[i][1]);
		t.push_back(temp);
		x.push_back(temp);

	}
	sort(t.begin(), t.end(), compare); // 정렬
	int s = -1;
	for (auto i : t)
	{
		if (s <= i.first)// 새로운 끝이 나면 +=1해주고 끝자리 갱신
		{
			answer += 1;
			s = i.second;
		}
	}

	return answer;
}