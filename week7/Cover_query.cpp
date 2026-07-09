#include <bits/stdc++.h>
using namespace std;

const int V = 500000;
const int SZ = V + 2;

long long cntBIT[SZ + 1];
long long sumBIT[SZ + 1];

void addCnt(int i, long long d) { for (; i <= SZ; i += i & -i) cntBIT[i] += d; }
void addSum(int i, long long d) { for (; i <= SZ; i += i & -i) sumBIT[i] += d; }
long long preCnt(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += cntBIT[i]; return s; }
long long preSum(int i) { long long s = 0; for (; i > 0; i -= i & -i) s += sumBIT[i]; return s; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        int idx = A[i] + 1;
        addCnt(idx, 1);
        addSum(idx, A[i]);
        total++;
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            int oldIdx = A[x] + 1;
            addCnt(oldIdx, -1);
            addSum(oldIdx, -A[x]);
            A[x] = y;
            int newIdx = y + 1;
            addCnt(newIdx, 1);
            addSum(newIdx, y);
        } else {
            long long l, r;
            cin >> l >> r;

            long long cntLess = preCnt((int)l);

            long long sumMid = preSum((int)r + 1) - preSum((int)l);
            long long cntGreater = total - preCnt((int)r + 1);
            long long ans = l * cntLess + sumMid + r * cntGreater;
            cout << ans << '\n';
        }
    }
    return 0;
}
