/*
ID: shenqi11
TASK: beads
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace beads {
ifstream fin("beads.in");
ofstream fout("beads.out");
int n;
string s;

int count(const string &str, int pos, int dx) {
    char type = 'w';
    int ret = 0, len = str.length();
    for (int i = pos; i < len && i >= 0; i += dx) {
        if (type != 'w' && str[i] != 'w' && type != str[i]) break;
        ret++;
        if (str[i] != 'w') type = str[i];
    }
    return ret;
}

void solve() {
    fin >> n >> s;
    s += s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = count(s, i, 1), r = count(s, i + n - 1, -1);
        ans = max(ans, l + r);
    }
    fout << min(ans, n) << "\n";
}
}  // namespace beads

int main() {
    beads::solve();
    return 0;
}
