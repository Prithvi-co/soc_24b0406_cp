#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> L(n), R(n);
    vector<long long> pts;
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        pts.push_back(L[i]);
        pts.push_back(R[i]);
    }
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    unordered_map<long long, int> cellOfPoint;
    cellOfPoint.reserve(pts.size() * 2);
    vector<int> cellId;
    int cellCount = 0;
    for (size_t i = 0; i < pts.size(); i++) {
        cellOfPoint[pts[i]] = cellCount++;
        if (i + 1 < pts.size() && pts[i + 1] > pts[i] + 1)
            cellCount++;
    }

    vector<int> diff(cellCount + 1, 0);
    for (int i = 0; i < n; i++) {
        int cl = cellOfPoint[L[i]];
        int cr = cellOfPoint[R[i]];
        diff[cl] += 1;
        diff[cr + 1] -= 1;
    }
    vector<int> cov(cellCount);
    int run = 0;
    for (int i = 0; i < cellCount; i++) { run += diff[i]; cov[i] = run; }

    int LOG = 1;
    while ((1 << LOG) < cellCount) LOG++;
    LOG++;
    vector<vector<int>> sp(LOG, vector<int>(cellCount));
    sp[0] = cov;
    for (int j = 1; j < LOG; j++)
        for (int i = 0; i + (1 << j) <= cellCount; i++)
            sp[j][i] = min(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
    auto rmin = [&](int lo, int hi) {
        int k = 31 - __builtin_clz(hi - lo + 1);
        return min(sp[k][lo], sp[k][hi - (1 << k) + 1]);
    };

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int cl = cellOfPoint[L[i]];
        int cr = cellOfPoint[R[i]];
        if (rmin(cl, cr) >= 2) { ans = i + 1; break; }
    }
    cout << ans << '\n';
    return 0;
}
