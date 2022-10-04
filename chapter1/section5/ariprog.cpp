/*
ID: shenqi11
TASK: ariprog
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

namespace ariprog {
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
int n, m;

void solve() {
    fin >> n >> m;
    const int inf = 2 * m * m;
    vector<bool> is_square(inf + 1);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            is_square[i * i + j * j] = true;
        }
    }
    bool has_sol = false, ok;
    int maxi = inf / (n - 1), maxj;
    for (int i = 1; i <= maxi; i++) {
        maxj = inf - i * (n - 1);
        for (int j = 0; j <= maxj; j++) {
            ok = true;
            for (int k = 0; k < n; k++) {
                if (!is_square[j + i * k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                has_sol = true;
                fout << j << " " << i << "\n";
            }
        }
    }
    if (!has_sol) fout << "NONE\n";
}
}  // namespace ariprog

int main() {
    ariprog::solve();
    return 0;
}
