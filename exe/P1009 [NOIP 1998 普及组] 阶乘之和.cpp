#include <bits/stdc++.h>
using namespace std;

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> res;
    int carry = 0;
    size_t n = max(a.size(), b.size());
    for (size_t i = 0; i < n; ++i) {
        int x = carry;
        if (i < a.size()) x += a[i];
        if (i < b.size()) x += b[i];
        res.push_back(x % 10);
        carry = x / 10;
    }
    if (carry) res.push_back(carry);
    return res;
}

// multiply big-integer (digits low->high) by small int m (m <= 50)
vector<int> mul_int(const vector<int>& a, int m) {
    if (m == 0) return vector<int>{0};
    vector<int> res;
    long long carry = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        long long cur = 1LL * a[i] * m + carry;
        res.push_back(int(cur % 10));
        carry = cur / 10;
    }
    while (carry > 0) {
        res.push_back(int(carry % 10));
        carry /= 10;
    }
    // remove leading zeros (shouldn't be needed, but safe)
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

void print_num(const vector<int>& num) {
    for (int i = (int)num.size() - 1; i >= 0; --i) cout << num[i];
    cout << "\n";
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) { cout << 0 << "\n"; return 0; }

    // 使用 1..n 下标更直观
    vector<vector<int>> num(n + 1), sum(n + 1);
    num[1] = vector<int>{1}; // 1! = 1
    sum[1] = vector<int>{1}; // 1! 的和

    for (int i = 2; i <= n; ++i) {
        num[i] = mul_int(num[i - 1], i);     // i! = (i-1)! * i
        sum[i] = add(sum[i - 1], num[i]);    // 累加到和
    }

    print_num(sum[n]);
    return 0;
}

