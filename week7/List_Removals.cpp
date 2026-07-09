#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> seg;
vector<long long> h;

void build(int node, int lo, int hi) {
    if (lo == hi) { seg[node] = h[lo]; return; }
    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int assign(int node, int lo, int hi, long long r) {
    if (seg[node] < r) return -1;
    if (lo == hi) { seg[node] -= r; return lo; }
    int mid = (lo + hi) / 2;
    int res;
    if (seg[2 * node] >= r) res = assign(2 * node, lo, mid, r);
    else res = assign(2 * node + 1, mid + 1, hi, r);
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    h.assign(n, 0);
    seg.assign(4 * n, 0);
    for (int i = 0; i < n; i++) cin >> h[i];
    build(1, 0, n - 1);

    for (int g = 0; g < m; g++) {
        long long r;
        cin >> r;
        int hotel = assign(1, 0, n - 1, r);
        cout << (hotel + 1) << " \n"[g == m - 1];
    }
    return 0;
}
