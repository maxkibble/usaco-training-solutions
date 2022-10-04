/*
ID: shenqi11
TASK: crypt1
LANG: C++
*/

#include <fstream>
#include <vector>

using namespace std;

namespace crypt1 {
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
int n, ans = 0;
vector<int> digits, sol(5);

bool check(int x) {
    while (x) {
        int y = x % 10;
        bool legal = false;
        for (int digit : digits) {
            if (y == digit) {
                legal = true;
                break;
            }
        }
        if (!legal) return false;
        x /= 10;
    }
    return true;
}

bool ok() {
    int a = sol[0] * 100 + sol[1] * 10 + sol[2], b = sol[3] * 10 + sol[4],
        c = a * sol[4], d = a * sol[3], e = a * b;
    return c >= 100 && c < 1000 && d >= 100 && d < 1000 && e >= 1000 &&
           e < 10000 && check(c) && check(d) && check(e);
}

void dfs(int depth) {
    if (depth == 5) {
        if (ok()) ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        sol[depth] = digits[i];
        dfs(depth + 1);
    }
}

void solve() {
    fin >> n;
    digits.resize(n);
    for (int i = 0; i < n; i++) fin >> digits[i];
    dfs(0);
    fout << ans << "\n";
}
}  // namespace crypt1

int main() {
    crypt1::solve();
    return 0;
}
