/*
ID: shenqi11
TASK: dualpal
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace dualpal {
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
int n, s;

string to_base(int num, int base) {
    string ret = "";
    while (num) {
        ret.push_back('0' + num % base);
        num /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool is_pal(string s) {
    int l = s.length();
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - 1 - i]) return false;
    }
    return true;
}

void solve() {
    fin >> n >> s;
    for (int i = s + 1; n > 0; i++) {
        int cnt = 0;
        for (int j = 2; j <= 10; j++) {
            if (is_pal(to_base(i, j))) cnt++;
        }
        if (cnt >= 2) {
            n--;
            fout << i << "\n";
        }
    }
}
}  // namespace dualpal

int main() {
    dualpal::solve();
    return 0;
}
