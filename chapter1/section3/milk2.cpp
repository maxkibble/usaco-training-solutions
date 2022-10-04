/*
ID: shenqi11
TASK: milk2
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

namespace milk2 {
ifstream fin("milk2.in");
ofstream fout("milk2.out");
int n;
vector<pair<int, int> > segs;

void solve() {
    fin >> n;
    segs.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> segs[i].first >> segs[i].second;
    }
    sort(segs.begin(), segs.end());
    int max_len = segs[0].second - segs[0].first, max_idle = 0,
        cur_st = segs[0].first, cur_ed = segs[0].second;
    for (int i = 1; i < n; i++) {
        if (segs[i].first > cur_ed) {
            max_idle = max(max_idle, segs[i].first - cur_ed);
            cur_st = segs[i].first, cur_ed = segs[i].second;
        } else {
            cur_ed = max(cur_ed, segs[i].second);
        }
        max_len = max(max_len, cur_ed - cur_st);
    }
    fout << max_len << " " << max_idle << "\n";
}
}  // namespace milk2

int main() {
    milk2::solve();
    return 0;
}
