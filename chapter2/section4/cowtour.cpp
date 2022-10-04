/*
ID: shenqi11
TASK: cowtour
LANG: C++
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

namespace cowtour {
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
const int N = 155;
const double inf = 1e18;
int n, x[N], y[N], mark[N];
char g[N][N];
double ans = inf, d[N][N], far[N], diam[N];

double distance(int s, int t) {
    return sqrt((x[s] - x[t]) * (x[s] - x[t]) + (y[s] - y[t]) * (y[s] - y[t]));
}

void floyd() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) d[i][j] = inf;
            if (g[i][j] == '1') d[i][j] = distance(i, j);
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void dfs(int cur, int idx) {
    mark[cur] = idx;
    diam[idx] = max(diam[idx], far[cur]);
    for (int i = 0; i < n; i++) {
        if (mark[i] || d[cur][i] == inf) continue;
        dfs(i, idx);
    }
}

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) fin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) fin >> g[i];
    floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] != inf && d[i][j] > far[i]) far[i] = d[i][j];
        }
    }
    int idx = 1;
    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) dfs(i, idx++);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] != inf) continue;
            ans = min(ans, max(far[i] + far[j] + distance(i, j),
                               max(diam[mark[i]], diam[mark[j]])));
        }
    }
    fout << fixed << setprecision(6) << ans << "\n";
}
}  // namespace cowtour

int main() {
    cowtour::solve();
    return 0;
}
