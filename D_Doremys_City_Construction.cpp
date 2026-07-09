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
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        string s;
        cin >> s;

        vector<int> ans(n + 1, 0);
        vector<char> vis(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            vector<int> cyc;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = 1;
                cyc.push_back(cur);
                cur = p[cur];
            }
            int black = 0;
            for (int node : cyc)
                if (s[node - 1] == '0') black++;
            for (int node : cyc) ans[node] = black;
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
