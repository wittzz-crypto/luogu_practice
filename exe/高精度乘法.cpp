#include <bits/stdc++.h>
using namespace std;

vector<int> read_num(string s) {
    vector<int> num;
    for (int i = s.size() - 1; i >= 0; --i)
        num.push_back(s[i] - '0'); // 把低位放在前面
    return num;
}

void print_num(vector<int> num) {
    for (int i = num.size() - 1; i >= 0; --i) // 倒序输出
        cout << num[i];
    cout << "\n";
}

vector<int> mul(vector<int> n1, vector<int> n2) {
    int size1 = n1.size(), size2 = n2.size();
    vector<int> c(size1 + size2, 0);  // 结果数组，最大长度是 n1.size + n2.size

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            c[i + j] += n1[i] * n2[j];  // 对应位置相乘并累加
            c[i + j + 1] += c[i + j] / 10;  // 处理进位
            c[i + j] %= 10;  // 当前位保持在0-9范围
        }
    }

    // 去掉多余的前导零
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }

    return c;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    vector<int> a = read_num(str1);
    vector<int> b = read_num(str2);

    vector<int> sum = mul(a, b);
    print_num(sum);

    return 0;
}