/*
ID: shenqi11
TASK: sprime
LANG: C++
*/

#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

namespace sprime {
ifstream fin("sprime.in");
ofstream fout("sprime.out");
int n;
vector<int> ans;

bool is_prime(int x) {
    if (x <= 1) return false;
    int lim = sqrt(x);
    for (int i = 2; i <= lim; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void dfs(int cur, int depth) {
    if (depth == n) {
        ans.push_back(cur);
        return;
    }
    int nxt;
    for (int i = 0; i < 10; i++) {
        nxt = cur * 10 + i;
        if (is_prime(nxt)) {
            dfs(nxt, depth + 1);
        }
    }
}

void solve() {
    fin >> n;
    dfs(0, 0);
    for (int num : ans) fout << num << "\n";
}
}  // namespace sprime

int main() {
    sprime::solve();
    return 0;
}
