/*
ID: shenqi11
TASK: maze1
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

namespace maze1 {
ifstream fin("maze1.in");
ofstream fout("maze1.out");
const int W = 40, H = 105, dx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int w, h;
char m[2 * H + 1][2 * W + 1];
bool vis[H][W];

struct node {
    int x, y, d;
};

bool is_exit(int x, int y) {
    return (x == 0 && m[0][2 * y + 1] == ' ') ||
           (x == h - 1 && m[2 * h][2 * y + 1] == ' ') ||
           (y == 0 && m[2 * x + 1][0] == ' ') ||
           (y == w - 1 && m[2 * x + 1][2 * w] == ' ');
}

bool can_pass(int x, int y, int nx, int ny, int d) {
    if (nx < 0 || nx >= h || ny < 0 || ny >= w) return false;
    return m[2 * x + 1 + dx[d][0]][2 * y + 1 + dx[d][1]] == ' ';
}

void solve() {
    fin >> w >> h;
    fin.getline(m[0], 1);
    for (int i = 0; i < 2 * h + 1; i++) fin.getline(m[i], 2 * W + 1);
    queue<node> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (is_exit(i, j)) {
                vis[i][j] = true;
                q.push({i, j, 1});
            }
        }
    }
    int nx, ny, ans = 0;
    while (!q.empty()) {
        node hd = q.front();
        q.pop();
        ans = max(ans, hd.d);
        for (int i = 0; i < 4; i++) {
            nx = hd.x + dx[i][0], ny = hd.y + dx[i][1];
            if (!can_pass(hd.x, hd.y, nx, ny, i) || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx, ny, hd.d + 1});
        }
    }
    fout << ans << "\n";
}

}  // namespace maze1

int main() {
    maze1::solve();
    return 0;
}
