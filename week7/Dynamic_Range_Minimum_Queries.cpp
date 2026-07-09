#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int Q;
    cin >> N >> Q;

    map<long long, long long> iv;
    long long painted = 0;

    while (Q--) {
        long long L, R;
        cin >> L >> R;

        auto it = iv.upper_bound(L);
        if (it != iv.begin()) {
            --it;
            if (it->second < L - 1) ++it;
        }
        while (it != iv.end() && it->first <= R + 1) {
            L = min(L, it->first);
            R = max(R, it->second);
            painted -= it->second - it->first + 1;
            it = iv.erase(it);
        }
        iv[L] = R;
        painted += R - L + 1;

        cout << N - painted << '\n';
    }
    return 0;
}
