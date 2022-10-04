/*
ID: shenqi11
TASK: zerosum
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

namespace zerosum {
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n;
vector<string> ans;

int calc(const string &s) {
    int l = s.length(), ret = 0, cur = 0, flag = 1;
    for (int i = 0; i < l; i++) {
        if (s[i] == '+')
            ret += cur * flag, cur = 0, flag = 1;
        else if (s[i] == '-')
            ret += cur * flag, cur = 0, flag = -1;
        else if (s[i] == ' ')
            cur = cur * 10;
        else
            cur += s[i] - '0';
    }
    ret += cur * flag;
    return ret;
}

void dfs(int dep, string s) {
    if (dep == n + 1) {
        if (calc("+" + s) == 0) {
            ans.push_back(s);
        }
        return;
    }
    dfs(dep + 1, s + " " + to_string(dep));
    dfs(dep + 1, s + "+" + to_string(dep));
    dfs(dep + 1, s + "-" + to_string(dep));
}

void solve() {
    fin >> n;
    dfs(2, "1");
    for (string s : ans) {
        fout << s << "\n";
    }
}
}  // namespace zerosum

int main() {
    zerosum::solve();
    return 0;
}
