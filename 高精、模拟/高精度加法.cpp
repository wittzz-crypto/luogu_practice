#include <bits/stdc++.h>
using namespace std;

vector<int> read_num(string s) {
    vector<int> num;
    for (int i = s.size() - 1; i >= 0; --i)
        num.push_back(s[i] - '0'); // 把低位放在前面
    return num;
}

vector<int> add(vector<int> n1, vector<int> n2) {
    vector<int> n3;
    int carry = 0;
    int size1 = n1.size(), size2 = n2.size();
    int maxlen = max(size1, size2);

    for (int i = 0; i < maxlen; i++) {
        int x = carry;
        if (i < size1) x += n1[i];
        if (i < size2) x += n2[i];
        n3.push_back(x % 10);  // 当前位
        carry = x / 10;        // 进位
    }
    if (carry > 0) n3.push_back(carry);
    return n3;
}

void print_num(vector<int> num) {
    for (int i = num.size() - 1; i >= 0; --i) // 倒序输出
        cout << num[i];
    cout << "\n";
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    vector<int> a = read_num(str1);
    vector<int> b = read_num(str2);

    vector<int> sum = add(a, b);
    print_num(sum);

    return 0;
}