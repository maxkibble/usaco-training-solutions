/*
ID: shenqi11
TASK: money
LANG: C++
*/

#include <fstream>

using namespace std;

namespace money {
ifstream fin("money.in");
ofstream fout("money.out");
const int V = 30, N = 1e4 + 5;
int v, n, a[V];
long long f[V][N];

void solve() {
    fin >> v >> n;
    for (int i = 1; i <= v; i++) fin >> a[i];
    f[0][0] = 1;
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) f[i][j] += f[i][j - a[i]];
        }
    }
    fout << f[v][n] << "\n";
}
}  // namespace money

int main() {
    money::solve();
    return 0;
}
