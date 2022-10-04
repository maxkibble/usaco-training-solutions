/*
ID: shenqi11
TASK: ride
LANG: C++
*/

#include <fstream>

using namespace std;

namespace ride {
ifstream fin("ride.in");
ofstream fout("ride.out");
string s, t;

int mod47(const string &str) {
    int res = 1;
    for (char c : str) {
        res = res * (c - 'A' + 1) % 47;
    }
    return res;
}

void solve() {
    fin >> s >> t;
    if (mod47(s) == mod47(t))
        fout << "GO";
    else
        fout << "STAY";
    fout << "\n";
}
}  // namespace ride

int main() {
    ride::solve();
    return 0;
}
