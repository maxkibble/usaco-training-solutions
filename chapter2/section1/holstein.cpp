/*
ID: shenqi11
TASK: holstein
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace holstein {
ifstream fin("holstein.in");
ofstream fout("holstein.out");
const int N = 30, M = 20;
int n, t[N], m, s[M][N], ans = M;
bool sol[M], mask[M];

void dfs(int depth) {
    if (depth == m) {
        int cnt = 0, now[N] = {0};
        for (int i = 0; i < m; i++) {
            if (!mask[i]) continue;
            for (int j = 0; j < n; j++) {
                now[j] += s[i][j];
            }
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            if (now[i] < t[i]) return;
        }
        if (cnt <= ans) {
            ans = cnt;
            for (int i = 0; i < m; i++) sol[i] = mask[i];
        }
        return;
    }
    mask[depth] = 0;
    dfs(depth + 1);
    mask[depth] = 1;
    dfs(depth + 1);
}

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) fin >> t[i];
    fin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> s[i][j];
        }
    }
    dfs(0);
    fout << ans;
    for (int i = 0; i < m; i++) {
        if (sol[i]) fout << " " << i + 1;
    }
    fout << "\n";
}
}  // namespace holstein

int main() {
    holstein::solve();
    return 0;
}
