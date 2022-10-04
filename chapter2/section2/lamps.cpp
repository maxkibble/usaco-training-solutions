/*
ID: shenqi11
TASK: lamps
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

namespace lamps {
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n, c;
vector<int> on, off, masks[4];
vector<vector<int>> res;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
    for (int i = 1; i <= n; i++) {
        if (v1[i] == v2[i]) continue;
        return v1[i] < v2[i];
    }
    return false;
}

bool ok(const vector<int> &v) {
    for (int idx : on) {
        if (!v[idx]) return false;
    }
    for (int idx : off) {
        if (v[idx]) return false;
    }
    return true;
}

void dfs(int depth, int op, vector<int> &cur) {
    if (depth == 4) {
        if (ok(cur) && op <= c && (c - op) % 2 == 0)
            res.push_back(cur);  // n>=10
        return;
    }
    dfs(depth + 1, op, cur);
    for (int i = 1; i <= n; i++) cur[i] ^= masks[depth][i];
    dfs(depth + 1, op + 1, cur);
    for (int i = 1; i <= n; i++) cur[i] ^= masks[depth][i];
}

void solve() {
    fin >> n >> c;
    int id;
    while (true) {
        fin >> id;
        if (id == -1) break;
        on.push_back(id);
    }
    while (true) {
        fin >> id;
        if (id == -1) break;
        off.push_back(id);
    }
    for (int i = 0; i < 4; i++) masks[i].resize(n + 1);
    for (int i = 1; i <= n; i++) masks[0][i] = 1;
    for (int i = 1; i <= n; i += 2) masks[1][i] = 1;
    for (int i = 2; i <= n; i += 2) masks[2][i] = 1;
    for (int i = 1; i <= n; i += 3) masks[3][i] = 1;
    vector<int> cur(n + 1, 1);
    dfs(0, 0, cur);
    sort(res.begin(), res.end(), cmp);
    for (auto sol : res) {
        for (int i = 1; i <= n; i++) fout << sol[i];
        fout << "\n";
    }
    if (res.size() == 0) fout << "IMPOSSIBLE\n";
}
}  // namespace lamps

int main() {
    lamps::solve();
    return 0;
}
