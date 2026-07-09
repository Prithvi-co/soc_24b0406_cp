#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());

        long long best = n / 2;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] != a[i]) {
                long long cand = (long long)i * (n - i);
                best = max(best, cand);
            }
        }
        cout << best << '\n';
    }
    return 0;
}
