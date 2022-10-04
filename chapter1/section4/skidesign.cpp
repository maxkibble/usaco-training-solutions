/*
ID: shenqi11
TASK: skidesign
LANG: C++
*/

#include <algorithm>
#include <climits>
#include <fstream>
#include <vector>

using namespace std;

namespace skidesign {
ifstream fin("skidesign.in");
ofstream fout("skidesign.out");
const int maxh = 100, delta = 17;
int n;
vector<int> h;

void solve() {
    fin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) fin >> h[i];
    int ans = INT_MAX, can;
    for (int i = 0; i <= maxh; i++) {
        can = 0;
        for (int j : h) {
            if (j < i) can += (i - j) * (i - j);
            if (j > i + delta) can += (i + delta - j) * (i + delta - j);
        }
        ans = min(ans, can);
    }
    fout << ans << "\n";
}
}  // namespace skidesign

int main() {
    skidesign::solve();
    return 0;
}
