/*
ID: shenqi11
TASK: contact
LANG: C++
*/

#include <algorithm>
#include <fstream>

using namespace std;

namespace contact {
ifstream fin("contact.in");
ofstream fout("contact.out");

int a, b, n;
string s;

void solve() {
    fin >> a >> b >> n;
    string tmp;
    while (fin >> tmp) s += tmp;
    int l = s.length();
    string ss;
    for (int i = 0; i < l; i++) {
        for (int j = a; j <= b; j++) {
            if (i - j + 1 < 0) break;
            ss = s.substr(i - j + 1, j);
        }
    }
}
}  // namespace contact

int main() {
    contact::solve();
    return 0;
}
