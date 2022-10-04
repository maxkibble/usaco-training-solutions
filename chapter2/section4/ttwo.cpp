/*
ID: shenqi11
TASK: ttwo
LANG: C++
*/

#include <fstream>
#include <set>

using namespace std;

namespace ttwo {
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
const int n = 10, N = 15, inf = 400 * 400,
          dx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int ans, t;
char m[N][N];

struct status {
    int x, y, d;
} farmer, cow;

void move(status &s) {
    status tmp = s;
    s.x = tmp.x + dx[s.d][0], s.y = tmp.y + dx[s.d][1];
    if (m[s.x][s.y] != '*') return;
    s.d = (s.d + 1) % 4;
    s.x = tmp.x, s.y = tmp.y;
}

void solve() {
    for (int i = 0; i <= n + 1; i++) m[0][i] = m[n + 1][i] = '*';
    for (int i = 1; i <= n; i++) {
        fin >> (m[i] + 1);
        m[i][0] = m[i][n + 1] = '*';
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == 'F') farmer.x = i, farmer.y = j;
            if (m[i][j] == 'C') cow.x = i, cow.y = j;
        }
    }
    while (t < inf) {
        if (farmer.x == cow.x && farmer.y == cow.y) {
            ans = t;
            break;
        }
        t++;
        move(farmer);
        move(cow);
    }
    fout << ans << "\n";
}
}  // namespace ttwo

int main() {
    ttwo::solve();
    return 0;
}
