/*
ID: shenqi11
TASK: barn1
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

namespace barn1 {
ifstream fin("barn1.in");
ofstream fout("barn1.out");
int m, s, c;
vector<int> v;

void solve() {
    fin >> m >> s >> c;
    v.resize(c);
    for (int i = 0; i < c; i++) fin >> v[i];
    sort(v.begin(), v.end());
    priority_queue<int> q;
    for (int i = 1; i < c; i++) q.push(v[i] - v[i - 1]);
    int gap = m - 1, ans = v[c - 1] - v[0] + 1;
    while (gap-- && !q.empty()) {
        ans -= q.top() - 1;
        q.pop();
    }
    fout << ans << "\n";
}
}  // namespace barn1

int main() {
    barn1::solve();
    return 0;
}
