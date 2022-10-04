/*
ID: shenqi11
TASK: combo
LANG: C++
*/

#include <fstream>

using namespace std;

namespace combo {
ifstream fin("combo.in");
ofstream fout("combo.out");
int n, a[3], b[3];

bool ok(int x, int y) {
    int z = abs(x - y);
    return z <= 2 || z >= n - 2;
}

bool check(int x, int y, int z) {
    return (ok(x, a[0]) && ok(y, a[1]) && ok(z, a[2])) ||
           (ok(x, b[0]) && ok(y, b[1]) && ok(z, b[2]));
}

void solve() {
    fin >> n;
    for (int i = 0; i < 3; i++) fin >> a[i];
    for (int i = 0; i < 3; i++) fin >> b[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (check(i, j, k)) ans++;
            }
        }
    }
    fout << ans << "\n";
}
}  // namespace combo

int main() {
    combo::solve();
    return 0;
}
