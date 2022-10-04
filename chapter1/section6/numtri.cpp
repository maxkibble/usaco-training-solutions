/*
ID: shenqi11
TASK: numtri
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace numtri {
ifstream fin("numtri.in");
ofstream fout("numtri.out");
const int N = 1005;
int n, a[N][N], f[N][N];

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            fin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        f[n - 1][i] = a[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
        }
    }
    fout << f[0][0] << "\n";
}
}  // namespace numtri

int main() {
    numtri::solve();
    return 0;
}
