/*
ID: shenqi11
TASK: fracdec
LANG: C++
*/

#include <fstream>
#include <map>
#include <vector>

using namespace std;

namespace fracdec {
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
int n, d;
string ans;

void solve() {
    fin >> n >> d;
    int x = n % d * 10;
    vector<char> v;
    map<int, int> m;
    while (x && m.find(x) == m.end()) {
        m[x] = v.size();
        v.push_back(x / d + '0');
        x = x % d * 10;
    }
    ans = to_string(n / d) + ".";
    if (n % d == 0)
        ans += "0";
    else {
        if (m.find(x) == m.end()) {
            for (int i = 0; i < v.size(); i++) ans.push_back(v[i]);
        } else {
            for (int i = 0; i < m[x]; i++) ans.push_back(v[i]);
            ans += "(";
            for (int i = m[x]; i < v.size(); i++) ans.push_back(v[i]);
            ans += ")";
        }
    }
    for (int i = 0; i < ans.length(); i++) {
        fout << ans[i];
        if (i % 76 == 75) fout << "\n";
    }
    if (ans.length() % 76 != 75) fout << "\n";
}
}  // namespace fracdec

int main() {
    fracdec::solve();
    return 0;
}
