/*
ID: shenqi11
TASK: wormhole
LANG: C++
*/

#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

namespace wormhole {
ifstream fin("wormhole.in");
ofstream fout("wormhole.out");
const int maxn = 15;
int n;
struct Point {
    int x, y;
    bool operator<(const Point &rhs) const {
        if (y == rhs.y) return x < rhs.x;
        return y < rhs.y;
    }
};
Point ps[maxn];
bool vis[maxn];
int ans = 0, next[maxn], wormhole[maxn];

bool ok() {
    for (int i = 0; i < n; i++) {
        int cur = i;
        memset(vis, 0, sizeof(vis));
        while (cur != -1) {
            vis[cur] = true;
            cur = next[wormhole[cur]];
            if (vis[cur]) return true;
        }
    }
    return false;
}

void make_wormhole(int depth) {
    if (depth == n / 2) {
        if (ok()) ans++;
        return;
    }
    int s;
    for (int i = 0; i < n; i++) {
        if (wormhole[i] == -1) {
            s = i;
            break;
        }
    }
    for (int i = s + 1; i < n; i++) {
        if (wormhole[i] == -1) {
            wormhole[s] = i, wormhole[i] = s;
            make_wormhole(depth + 1);
            wormhole[s] = -1, wormhole[i] = -1;
        }
    }
}

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) fin >> ps[i].x >> ps[i].y;
    sort(ps, ps + n);
    memset(next, -1, sizeof(next));
    memset(wormhole, -1, sizeof(wormhole));
    for (int i = 0; i < n - 1; i++) {
        if (ps[i].y == ps[i + 1].y) next[i] = i + 1;
    }
    make_wormhole(0);
    fout << ans << "\n";
}
}  // namespace wormhole

int main() {
    wormhole::solve();
    return 0;
}
