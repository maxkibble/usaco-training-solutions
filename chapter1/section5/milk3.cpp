/*
ID: shenqi11
TASK: milk3
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

namespace milk3 {
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int sz[3];
struct State {
    int amt[3];
    bool operator<(const State &rhs) const {
        if (amt[0] != rhs.amt[0]) return amt[0] < rhs.amt[0];
        if (amt[1] != rhs.amt[1]) return amt[1] < rhs.amt[1];
        return amt[2] < rhs.amt[2];
    }
} init;

State pour(const State &now, int from, int to) {
    int d = min(now.amt[from], sz[to] - now.amt[to]);
    State ret = now;
    ret.amt[from] -= d;
    ret.amt[to] += d;
    return ret;
}

void solve() {
    fin >> sz[0] >> sz[1] >> sz[2];
    init.amt[2] = sz[2];
    queue<State> q;
    q.push(init);
    set<State> vis;
    set<int> ans;
    while (!q.empty()) {
        State hd = q.front();
        q.pop();
        vis.insert(hd);
        if (hd.amt[0] == 0) ans.insert(hd.amt[2]);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                State nxt = pour(hd, i, j);
                if (vis.find(nxt) != vis.end()) continue;
                q.push(nxt);
            }
        }
    }
    fout << *ans.begin();
    set<int>::iterator it = ++ans.begin();
    while (it != ans.end()) {
        fout << " " << *it;
        it++;
    }
    fout << "\n";
}
}  // namespace milk3

int main() {
    milk3::solve();
    return 0;
}
