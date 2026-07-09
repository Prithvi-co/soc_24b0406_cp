#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000001;
int D[MAXV];

int n, m;
long long bit[300005];
void upd(int i, long long delta) { for (; i <= n; i += i & -i) bit[i] += delta; }
long long qry(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < MAXV; i++)
        for (int j = i; j < MAXV; j += i)
            D[j]++;

    cin >> n >> m;
    vector<int> a(n + 1);
    set<int> active;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i, a[i]);
        if (a[i] > 2) active.insert(i);
    }

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {

            auto it = active.lower_bound(l);
            while (it != active.end() && *it <= r) {
                int pos = *it;
                int nv = D[a[pos]];
                upd(pos, (long long)nv - a[pos]);
                a[pos] = nv;
                if (nv <= 2) it = active.erase(it);
                else ++it;
            }
        } else {
            cout << qry(r) - qry(l - 1) << '\n';
        }
    }
    return 0;
}
