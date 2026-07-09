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
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            long long x, y;
            cin >> u >> v >> x >> y;
            if (x >= y) {

                adj[v].push_back(u);
                indeg[u]++;
            } else {

                adj[u].push_back(v);
                indeg[v]++;
            }
        }

        vector<int> p(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0) q.push(i);
        int val = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            p[cur] = val++;
            for (int nxt : adj[cur])
                if (--indeg[nxt] == 0) q.push(nxt);
        }

        for (int i = 1; i <= n; i++)
            cout << p[i] << " \n"[i == n];
    }
    return 0;
}
