#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long n = x + y;

        bool nEven = (n % 2 == 0);

        bool ok = true;
        if (y < 1) ok = false;
        if (x > y) ok = false;
        if (nEven && x == 0) ok = false;

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        long long k = x - (nEven ? 1 : 0);
        long long m = n - 1 - 2 * k;

        cout << "YES\n";
        int next = 2;

        for (long long i = 0; i < k; i++) {
            int b = next++;
            int c = next++;
            cout << 1 << ' ' << b << '\n';
            cout << b << ' ' << c << '\n';
        }

        for (long long i = 0; i < m; i++) {
            int leaf = next++;
            cout << 1 << ' ' << leaf << '\n';
        }
    }
    return 0;
}
