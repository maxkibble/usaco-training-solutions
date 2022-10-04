/*
ID: shenqi11
TASK: subset
LANG: C++
*/

#include <fstream>
#include <map>

using namespace std;

namespace subset {
ifstream fin("subset.in");
ofstream fout("subset.out");
const int N = 40, S = 800;
int n;
long long f[N][S];  // 1+2+..+39 < 800

void solve() {
    fin >> n;
    int s = (1 + n) * n / 2;
    if (s % 2 != 0) {
        fout << "0\n";
        return;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= i) f[i][j] += f[i - 1][j - i];
        }
    }
    fout << f[n][s / 2] / 2 << "\n";
}
}  // namespace subset

int main() {
    subset::solve();
    return 0;
}
