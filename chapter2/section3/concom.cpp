/*
ID: shenqi11
TASK: concom
LANG: C++
*/

#include <fstream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

namespace concom {
typedef pair<int, int> pii;
ifstream fin("concom.in");
ofstream fout("concom.out");
const int N = 105;
int n, pct[N][N];
vector<vector<pii>> g(N);
vector<set<int>> ans(N);

void dijkstra(int s) {
    priority_queue<pii> q;
    for (pii nxt : g[s]) {
        q.push(nxt);
        pct[s][nxt.second] = nxt.first;
    }
    while (!q.empty()) {
        pii hd = q.top();
        q.pop();
        if (hd.first <= 50) break;
        if (ans[s].find(hd.second) != ans[s].end() || hd.second == s) continue;
        ans[s].insert(hd.second);
        for (pii nxt : g[hd.second]) {
            pct[s][nxt.second] += nxt.first;
            q.push({pct[s][nxt.second], nxt.second});
        }
    }
}

void solve() {
    fin >> n;
    int s, t, w;
    for (int i = 0; i < n; i++) {
        fin >> s >> t >> w;
        g[s].push_back({w, t});
    }
    for (int i = 1; i < N; i++) {
        dijkstra(i);
        for (int j : ans[i]) fout << i << " " << j << "\n";
    }
}
}  // namespace concom

int main() {
    concom::solve();
    return 0;
}
