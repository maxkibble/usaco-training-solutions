/*
ID: shenqi11
TASK: palsquare
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace palsquare {
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
int b;

string to_base(int num, int base) {
    string ret = "";
    while (num) {
        int digit = num % base;
        if (digit >= 10)
            ret.push_back('A' + num % base - 10);
        else
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
    fin >> b;
    for (int i = 1; i <= 300; i++) {
        string square = to_base(i * i, b);
        if (is_pal(square)) {
            fout << to_base(i, b) << " " << square << "\n";
        }
    }
}
}  // namespace palsquare

int main() {
    palsquare::solve();
    return 0;
}
