#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        bool exists;
        long long dmin = 0;

        if (n == 1) {
            exists = (m == 0);
            dmin = 0;
        } else {
            long long maxEdges = n * (n - 1) / 2;
            if (m < n - 1 || m > maxEdges) {
                exists = false;
            } else {
                exists = true;
                if (n == 2)                 dmin = 1;
                else if (m == maxEdges)     dmin = 1;
                else                        dmin = 2;
            }
        }

        bool yes = exists && (dmin < k - 1);
        cout << (yes ? "YES" : "NO") << '\n';
    }
    return 0;
}
