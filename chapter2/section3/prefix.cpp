/*
ID: shenqi11
TASK: prefix
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

namespace prefix {
ifstream fin("prefix.in");
ofstream fout("prefix.out");
vector<string> p;
string t;

void solve() {
    string s;
    while (true) {
        fin >> s;
        if (s == ".") break;
        p.push_back(s);
    }
    while (fin >> s) t += s;
    int n = t.length();
    vector<bool> f(n + 1, false);
    f[0] = true;
    int ans = 0, l;
    for (int i = 1; i <= n; i++) {
        for (string pi : p) {
            l = pi.length();
            if (i < l || t.substr(i - l, l) != pi) continue;
            f[i] = f[i] || f[i - l];
        }
        if (f[i]) ans = i;
    }
    fout << ans << "\n";
}
}  // namespace prefix

int main() {
    prefix::solve();
    return 0;
}
