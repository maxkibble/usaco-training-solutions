/*
ID: shenqi11
TASK: namenum
LANG: C++
*/

#include <fstream>

using namespace std;

namespace namenum {
ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream fin2("dict.txt");
string s;
const int d[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6,
                   6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

string hash(const string &t) {
    string res = "";
    for (char c : t) {
        res.push_back(d[c - 'A'] + '0');
    }
    return res;
}

void solve() {
    fin >> s;
    bool exists = false;
    string t;
    while (fin2 >> t) {
        if (hash(t) == s) {
            fout << t << "\n";
            exists = true;
        }
    }
    if (!exists) fout << "NONE\n";
}
}  // namespace namenum

int main() {
    namenum::solve();
    return 0;
}
