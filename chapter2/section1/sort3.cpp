/*
ID: shenqi11
TASK: sort3
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace sort3 {
ifstream fin("sort3.in");
ofstream fout("sort3.out");
const int N = 1005;
int n, a[N], cnt[4], m[4][4];

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < cnt[1]; i++) m[1][a[i]]++;
    for (int i = cnt[1]; i < cnt[1] + cnt[2]; i++) m[2][a[i]]++;
    for (int i = cnt[1] + cnt[2]; i < n; i++) m[3][a[i]]++;
    int x1 = max(m[1][2], m[2][1]), y1 = min(m[1][2], m[2][1]),
        x2 = max(m[1][3], m[3][1]), y2 = min(m[1][3], m[3][1]),
        x3 = max(m[2][3], m[3][2]), y3 = min(m[2][3], m[3][2]);
    fout << y1 + y2 + y3 + (x1 - y1 + x2 - y2 + x3 - y3) / 3 * 2 << "\n";
}
}  // namespace sort3

int main() {
    sort3::solve();
    return 0;
}
