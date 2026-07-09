#include <bits/stdc++.h>
using namespace std;

int n;
int bit[200005];
int LOGN;
void add(int i, int v) { for (; i <= n; i += i & -i) bit[i] += v; }

int kth(int k) {
    int pos = 0;
    for (int pw = LOGN; pw >= 0; pw--) {
        int nxt = pos + (1 << pw);
        if (nxt <= n && bit[nxt] < k) { pos = nxt; k -= bit[nxt]; }
    }
    return pos + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> x(n + 1);
    LOGN = 0;
    while ((1 << (LOGN + 1)) <= n) LOGN++;
    for (int i = 1; i <= n; i++) { cin >> x[i]; add(i, 1); }

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int j = kth(p);
        cout << x[j] << " \n"[i == n - 1];
        add(j, -1);
    }
    return 0;
}
