#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);
        long long ans = 0;
        for (int s = 1; s <= n; s++) {
            if (color[s] != -1) continue;

            vector<int> comp;
            queue<int> q;
            q.push(s);
            color[s] = 0;
            bool bipartite = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                for (int w : adj[u]) {
                    if (color[w] == -1) {
                        color[w] = color[u] ^ 1;
                        q.push(w);
                    } else if (color[w] == color[u]) {
                        bipartite = false;
                    }
                }
            }
            if (bipartite) ans += (long long)comp.size();
        }
        cout << ans << '\n';
    }
    return 0;
}
