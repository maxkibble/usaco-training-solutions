/*
ID: shenqi11
TASK: nocows
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

namespace nocows {
ifstream fin("nocows.in");
ofstream fout("nocows.out");
const int N = 205, K = 105, mod = 9901;
int n, k, f[K][N], g[K][N];

void solve() {
    fin >> n >> k;
    f[1][1] = 1, g[1][1] = 1;
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j += 2) {
            for (int l = 1; l <= j - 2; l += 2) {
                int r = j - 1 - l;
                f[i][j] +=
                    f[i - 1][l] * g[i - 2][r] * 2 + f[i - 1][l] * f[i - 1][r];
                f[i][j] %= mod;
            }
            g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
        }
    }
    fout << f[k][n] << "\n";
}
}  // namespace nocows

int main() {
    nocows::solve();
    return 0;
}
