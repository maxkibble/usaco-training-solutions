/*
ID: shenqi11
TASK: castle
LANG: C++
*/

#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

namespace castle {
ifstream fin("castle.in");
ofstream fout("castle.out");
const int N = 55, mask[4] = {1, 2, 4, 8}, op[4] = {2, 3, 0, 1},
          dx[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
const char direction[4] = {'W', 'N', 'E', 'S'};
int n, m, c[N][N], vis[N][N];

void dfs(int x, int y, int &cnt, int &cur_sz, int &max_sz) {
    if (vis[x][y]) return;
    vis[x][y] = true;
    if (cur_sz == 0) cnt++;
    cur_sz++;
    max_sz = max(max_sz, cur_sz);
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        if ((c[x][y] & mask[i]) != 0) continue;
        nx = x + dx[i][0], ny = y + dx[i][1];
        if (nx > m || nx < 1 || ny > n || ny < 1) continue;
        dfs(nx, ny, cnt, cur_sz, max_sz);
    }
}

void try_remove(int &can) {
    memset(vis, 0, sizeof(vis));
    int no_care = 0, tmp;
    can = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tmp = 0;
            dfs(i, j, no_care, tmp, can);
        }
    }
}

void solve() {
    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> c[i][j];
        }
    }
    int ans1 = 0, tmp, ans2 = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            tmp = 0;
            dfs(i, j, ans1, tmp, ans2);
        }
    }
    fout << ans1 << "\n" << ans2 << "\n";

    int can, ni, nj, x, y, z;
    // iteration order matters
    for (int j = n; j >= 1; j--) {
        for (int i = 1; i <= m; i++) {
            for (int k = 4; k > 0; k--) {
                if (k == 0 || k == 3) continue;
                if ((c[i][j] & mask[k]) == 0) continue;
                ni = i + dx[k][0], nj = j + dx[k][1];
                c[i][j] ^= mask[k];
                c[ni][nj] ^= mask[op[k]];
                try_remove(can);
                c[ni][nj] ^= mask[op[k]];
                c[i][j] ^= mask[k];
                if (can >= ans2) ans2 = can, x = i, y = j, z = k;
            }
        }
    }
    fout << ans2 << "\n" << x << " " << y << " " << direction[z] << "\n";
}
}  // namespace castle

int main() {
    castle::solve();
    return 0;
}
