#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//ÀÌÁøÅ½»ö
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int l = 1;
    int r = 100000;
    while (l <= r) {
        int mid = (l + r) / 2;
        int pre = 0;
        long long total = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] > mid) {
                total += (long long)(pre + times[i]) * (diffs[i] - mid);
            }
            total += times[i];
            pre = times[i];
        }
        if (total <= limit)
        {
            answer = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return answer;
}