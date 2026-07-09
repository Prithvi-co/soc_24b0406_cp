#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string good;
    int k;
    cin >> s >> good >> k;
    int n = (int)s.size();

    const unsigned long long MOD1 = 1000000007ULL, MOD2 = 998244353ULL;
    const unsigned long long B1 = 131, B2 = 137;

    vector<unsigned long long> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1), p2(n + 1, 1);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a' + 1;
        h1[i + 1] = (h1[i] * B1 + c) % MOD1;
        h2[i + 1] = (h2[i] * B2 + c) % MOD2;
        p1[i + 1] = p1[i] * B1 % MOD1;
        p2[i + 1] = p2[i] * B2 % MOD2;
    }
    auto sub1 = [&](int l, int r) {
        return (h1[r + 1] + MOD1 - h1[l] * p1[r - l + 1] % MOD1) % MOD1;
    };
    auto sub2 = [&](int l, int r) {
        return (h2[r + 1] + MOD2 - h2[l] * p2[r - l + 1] % MOD2) % MOD2;
    };

    unordered_set<unsigned long long> seen;
    seen.reserve(1 << 20);
    for (int i = 0; i < n; i++) {
        int bad = 0;
        for (int j = i; j < n; j++) {
            if (good[s[j] - 'a'] == '0') bad++;
            if (bad > k) break;
            unsigned long long key = (sub1(i, j) << 31) ^ sub2(i, j);
            seen.insert(key);
        }
    }
    cout << seen.size() << '\n';
    return 0;
}
