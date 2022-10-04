/*
ID: shenqi11
TASK: milk
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

namespace milk {
ifstream fin("milk.in");
ofstream fout("milk.out");
int n, m;
typedef pair<int, int> pii;
vector<pii> p;

void solve() {
    fin >> n >> m;
    p.resize(m);
    for (int i = 0; i < m; i++) fin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int ans = 0, amt;
    for (int i = 0; i < m; i++) {
        amt = min(p[i].second, n);
        ans += p[i].first * amt;
        n -= amt;
    }
    fout << ans << "\n";
}
}  // namespace milk

int main() {
    milk::solve();
    return 0;
}
