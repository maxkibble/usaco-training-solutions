/*
ID: shenqi11
TASK: preface
LANG: C++
*/

#include <fstream>
#include <map>

using namespace std;

namespace preface {
ifstream fin("preface.in");
ofstream fout("preface.out");
int n;

string roman_rule(int x, string one, string five, string ten) {
    switch (x) {
        case 0:
            return "";
        case 1:
            return one;
        case 2:
            return one + one;
        case 3:
            return one + one + one;
        case 4:
            return one + five;
        case 5:
            return five;
        case 6:
            return five + one;
        case 7:
            return five + one + one;
        case 8:
            return five + one + one + one;
        case 9:
            return one + ten;
    }
    return "";
}

string to_roman(int x) {
    string ret = "";
    // 1000:M
    ret += roman_rule(x / 1000, "M", "NO", "CARE");
    x %= 1000;
    // 100:C, 500:D, 1000:M
    ret += roman_rule(x / 100, "C", "D", "M");
    x %= 100;
    // 10:X, 50:L, 100:C
    ret += roman_rule(x / 10, "X", "L", "C");
    x %= 10;
    // 1:I, 5:V, 10:X
    ret += roman_rule(x, "I", "V", "X");
    return ret;
}

void solve() {
    fin >> n;
    map<char, int> m;
    for (int i = 0; i <= n; i++) {
        string s = to_roman(i);
        for (char c : s) m[c]++;
    }
    const string output_order = "IVXLCDM";
    for (char c : output_order) {
        if (m[c] == 0) continue;
        fout << c << " " << m[c] << "\n";
    }
}
}  // namespace preface

int main() {
    preface::solve();
    return 0;
}
