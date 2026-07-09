#include <bits/stdc++.h>
using namespace std;

int n, q;
long long bit[200005];
void add(int i, long long v) { for (; i <= n; i += i & -i) bit[i] += v; }
long long pre(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            long long u;
            cin >> l >> r >> u;
            add(l, u);
            add(r + 1, -u);
        } else {
            int k;
            cin >> k;
            cout << a[k] + pre(k) << '\n';
        }
    }
    return 0;
}
