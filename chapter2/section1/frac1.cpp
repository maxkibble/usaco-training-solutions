/*
ID: shenqi11
TASK: frac1
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

namespace frac1 {
ifstream fin("frac1.in");
ofstream fout("frac1.out");
int n;

typedef pair<int, int> pii;

int gcd(int x, int y) {
    if (x < y) return gcd(y, x);
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

bool cmp(const pii &p1, const pii &p2) {
    return (double)p1.first / p1.second < (double)p2.first / p2.second;
}

void solve() {
    fin >> n;
    vector<pii> ans = {{0, 1}, {1, 1}};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (gcd(i, j) != 1) continue;
            ans.push_back({j, i});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (pii item : ans) {
        fout << item.first << "/" << item.second << "\n";
    }
}
}  // namespace frac1

int main() {
    frac1::solve();
    return 0;
}
