/*
ID: shenqi11
TASK: humble
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace humble {
ifstream fin("humble.in");
ofstream fout("humble.out");
const int K = 105, N = 1e5 + 5, Inf = 0x7fffffff;
int k, n, p[K], pindex[K], humbles[N];

void solve() {
    fin >> k >> n;
    for (int i = 0; i < k; i++) {
        fin >> p[i];
    }
    humbles[0] = 1;
    int min_val, min_idx, tmp;
    for (int i = 0; i < n; i++) {
        humbles[i + 1] = Inf;
        for (int j = 0; j < k; j++) {
            while (humbles[pindex[j]] * p[j] <= humbles[i]) {
                pindex[j]++;
            }
            humbles[i + 1] = min(humbles[i + 1], humbles[pindex[j]] * p[j]);
        }
    }
    fout << humbles[n] << "\n";
}
}  // namespace humble

int main() {
    humble::solve();
    return 0;
}
