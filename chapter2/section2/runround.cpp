/*
ID: shenqi11
TASK: runround
LANG: C++
*/

#include <cstring>
#include <fstream>

using namespace std;

namespace runround {
ifstream fin("runround.in");
ofstream fout("runround.out");
int n;
bool vis[10];

bool ok(int x) {
    string s = to_string(x);
    int len = s.length(), cur = 0, nxt;
    while (s[cur] != 'A') {
        nxt = (cur + s[cur] - '0') % len;
        s[cur] = 'A';
        cur = nxt;
    }
    if (cur != 0) return false;
    for (int i = 0; i < len; i++) {
        if (s[i] != 'A') return false;
    }
    return true;
}

void dfs(int dep, int max_dep, int num) {
    if (dep == max_dep) {
        if (ok(num) && num > n) {
            fout << num << "\n";
            exit(0);
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(dep + 1, max_dep, num * 10 + i);
        vis[i] = false;
    }
}

void solve() {
    fin >> n;
    for (int i = 1; i <= 9; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(0, i, 0);
    }
}
}  // namespace runround

int main() {
    runround::solve();
    return 0;
}
