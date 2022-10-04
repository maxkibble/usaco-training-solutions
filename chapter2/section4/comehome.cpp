/*
ID: shenqi11
TASK: comehome
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace comehome {
ifstream fin("comehome.in");
ofstream fout("comehome.out");
const int N = 55, inf = 1e9, T = 51;  // get_id('Z') == 51
int p, d[N][N];

int get_id(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

void solve() {
    fin >> p;
    char s, t;
    int si, ti, w;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            d[i][j] = (i == j ? 0 : inf);
        }
    }
    while (p--) {
        fin >> s >> t >> w;
        si = get_id(s), ti = get_id(t);
        d[si][ti] = d[ti][si] = min(d[si][ti], w);
    }
    // floyd
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    char label;
    int dis = inf;
    for (int i = 0; i < N; i++) {
        if (i == T) continue;
        if (d[T][i] < dis && i >= 26) {
            label = 'A' + i - 26;
            dis = d[T][i];
        }
    }
    fout << label << " " << dis << "\n";
}
}  // namespace comehome

int main() {
    comehome::solve();
    return 0;
}
