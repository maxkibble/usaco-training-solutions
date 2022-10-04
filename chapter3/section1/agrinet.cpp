/*
ID: shenqi11
TASK: agrinet
LANG: C++
*/

#include <fstream>

using namespace std;

namespace agrinet {
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
// small data size, and the graph is dense,
// O(n^2) mst algorithm implemention
const int N = 105, inf = 0x7fffffff;
int n, g[N][N], d[N], vis[N], ans;

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> g[i][j];
        }
    }
    vis[0] = 1;
    for (int i = 0; i < n; i++) d[i] = g[0][i];
    d[0] = inf;
    int min_dis, min_id;
    for (int i = 0; i < n - 1; i++) {
        min_dis = inf;
        for (int j = 0; j < n; j++) {
            if (d[j] < min_dis) {
                min_dis = d[j];
                min_id = j;
            }
        }
        ans += min_dis;
        vis[min_id] = 1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            d[j] = min(d[j], g[min_id][j]);
        }
        d[min_id] = inf;
    }
    fout << ans << "\n";
}
}  // namespace agrinet

int main() {
    agrinet::solve();
    return 0;
}
