#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<long long> seg;
const long long INF = LLONG_MAX;

void update(int pos, long long val) {
    pos += n;
    seg[pos] = val;
    for (pos >>= 1; pos >= 1; pos >>= 1)
        seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
}
long long query(int l, int r) {
    long long res = INF;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    seg.assign(2 * n, INF);
    for (int i = 0; i < n; i++) cin >> seg[n + i];
    for (int i = n - 1; i >= 1; i--) seg[i] = min(seg[2 * i], seg[2 * i + 1]);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            update(k - 1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b - 1) << '\n';
        }
    }
    return 0;
}
