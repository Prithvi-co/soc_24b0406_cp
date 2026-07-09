#include <bits/stdc++.h>
using namespace std;

int n;
long long bit[1000006];
void upd(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
long long qry(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> Lv(n + 1), Rv(n + 1);
    {
        unordered_map<int, int> cnt;
        cnt.reserve(n * 2);
        for (int i = 1; i <= n; i++) Lv[i] = ++cnt[a[i]];
    }
    {
        unordered_map<int, int> cnt;
        cnt.reserve(n * 2);
        for (int j = n; j >= 1; j--) Rv[j] = ++cnt[a[j]];
    }

    long long ans = 0;
    for (int j = 1; j <= n; j++) {

        long long inserted = j - 1;
        long long leq = qry(Rv[j]);
        ans += inserted - leq;
        upd(Lv[j], 1);
    }
    cout << ans << '\n';
    return 0;
}
