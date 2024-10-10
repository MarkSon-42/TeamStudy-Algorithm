#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
// ������

bool visited[10] = { false };
int ans[100];
bool ft[100] = { false };
//���ڿ� split �Լ�
vector<string> split(string& a, char del) {
    vector<string> result;
    stringstream ss(a);
    string temp;

    while (getline(ss, temp, del)) {
        result.push_back(temp);
    }
    return result;
}
//����ū ���ڸ� ���ϴ� �Լ�
int check(vector<string> ex) {
    int result = 0;
    for (auto a : ex) {
        for (auto i : a) {
            if ('0' <= i && i <= '9') {
                if (result < i - '0') {
                    result = i - '0';
                }
            }
        }
    }
    return result;
}
// n���� ���ڿ��� ������ ��ȯ
int change(string a, int n) {
    int result = 0;
    int s = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        int temp = a[i] - '0';
        result += s * temp;
        s *= n;
    }
    return result;
}
// ���� n���� ����� �´��� Ȯ���ϴ� �Լ�
bool pass(string a, int n) {
    vector<string> temp = split(a, ' ');
    int b = change(temp[0], n);
    int c = change(temp[2], n);
    int d = change(temp[4], n);
    if (temp[1] == "+") {
        return (b + c) == d;
    }
    else {
        return (b - c) == d;
    }
}
//X�� ����� ������ ��Ÿ���ִ� �Լ�
int value(string a, int n) {
    vector<string> temp = split(a, ' ');
    int b = change(temp[0], n);
    int c = change(temp[2], n);
    if (temp[1] == "+") {
        return (b + c);
    }
    else {
        return (b - c);
    }
}
// ������ n������ ���� �ٲ��ִ� �Լ�.
int change_to(int a, int b) {
    int result = 0;
    int s = 1;
    while (a > 0) {
        result += (a % b) * s;
        a /= b;
        s *= 10;
    }
    return result;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> A, B;
    int N = check(expressions);
    for (auto str : expressions) {
        if (str.back() == 'X') {
            B.push_back(str);
        }
        else {
            A.push_back(str);
        }
    }
    vector<int> t;
    // ����ϴ� �������� ��󳽴�.
    for (int i = N + 1; i < 10; i++) {
        visited[i] = true;
        for (auto str : A) {
            if (!pass(str, i)) {
                visited[i] = false;
                break;
            }
        }
        if (visited[i]) {
            t.push_back(i);
        }
    }

    for (int i = 0; i < B.size(); i++) {
        ans[i] = change_to(value(B[i], t[0]), t[0]);
    }

    for (int i = 1; i < t.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            if (!ft[j]) {
                int temp = change_to(value(B[j], t[i]), t[i]);
                if (ans[j] != temp) {
                    ft[j] = true;
                }
            }

        }
    }
    for (int i = 0; i < B.size(); i++) {
        if (ft[i]) {
            B[i].back() = '?';
        }
        else {
            string temp = to_string(ans[i]);
            B[i].pop_back();
            B[i] += temp;
        }
    }

    return B;
}