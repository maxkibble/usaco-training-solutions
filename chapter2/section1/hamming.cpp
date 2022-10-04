/*
ID: shenqi11
TASK: hamming
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

namespace hamming {
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int n, b, d;

int hamming_distance(int x, int y) {
    int z = x ^ y, ret = 0;
    while (z) {
        ret += 1;
        z = z & (z - 1);
    }
    return ret;
}

void solve() {
    fin >> n >> b >> d;
    vector<int> ans;
    int cur = 0, inf = 1 << b;
    bool ok;
    for (int i = 0; i < n; i++) {
        ans.push_back(cur);
        for (int j = cur + 1; j < inf; j++) {
            ok = true;
            for (int k = 0; k <= i; k++) {
                if (hamming_distance(j, ans[k]) >= d) continue;
                ok = false;
                break;
            }
            if (ok) {
                cur = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 10 == 9 || i == n - 1)
            fout << ans[i] << "\n";
        else
            fout << ans[i] << " ";
    }
}
}  // namespace hamming

int main() {
    hamming::solve();
    return 0;
}

