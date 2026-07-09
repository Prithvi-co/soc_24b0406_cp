#include <bits/stdc++.h>
using namespace std;

int n;
long long w[100005];
double tree[100005];

void upd(int i, double val) { for (; i <= n; i += i & -i) tree[i] = max(tree[i], val); }
double qry(int i) { double m = 0; for (; i > 0; i -= i & -i) m = max(m, tree[i]); return m; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long r, h;
        cin >> r >> h;
        w[i] = r * r * h;
    }

    vector<long long> vals(w + 1, w + n + 1);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto rankOf = [&](long long x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };

    double best = 0;
    for (int i = 1; i <= n; i++) {
        int r = rankOf(w[i]);
        double cur = qry(r - 1) + (double)w[i];
        upd(r, cur);
        best = max(best, cur);
    }

    const double PI = acos(-1.0);
    cout << fixed << setprecision(9) << best * PI << '\n';
    return 0;
}
