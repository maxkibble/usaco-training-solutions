/*
ID: shenqi11
TASK: inflate
LANG: C++
*/

#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

namespace inflate {
ifstream fin("inflate.in");
ofstream fout("inflate.out");
const int M = 10005, N = 10005;
int m, n, p[N], t[N];
long long f[2][M];

void solve() {
    fin >> m >> n;
    for (int i = 0; i < n; i++) fin >> p[i] >> t[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[1][j] = f[0][j];
            if (j >= t[i - 1]) {
                f[1][j] = max(f[1][j], f[1][j - t[i - 1]] + p[i - 1]);
            }
        }
        memcpy(f[0], f[1], sizeof(f[0]));
    }
    fout << f[1][m] << "\n";
}
}  // namespace inflate

int main() {
    inflate::solve();
    return 0;
}
