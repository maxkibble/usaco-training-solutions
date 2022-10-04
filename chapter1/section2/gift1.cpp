/*
ID: shenqi11
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <map>
#include <vector>

using namespace std;

namespace gift1 {
ifstream fin("gift1.in");
ofstream fout("gift1.out");
int n;
vector<string> names;

void solve() {
    fin >> n;
    names.resize(n);
    for (int i = 0; i < n; i++) {
        fin >> names[i];
    }
    string from, to;
    int amt, num;
    map<string, int> res;
    for (int i = 0; i < n; i++) {
        fin >> from >> amt >> num;
        for (int j = 0; j < num; j++) {
            fin >> to;
            res[from] -= amt / num;
            res[to] += amt / num;
        }
    }
    for (string name : names) {
        fout << name << " " << res[name] << "\n";
    }
}
}  // namespace gift1

int main() {
    gift1::solve();
    return 0;
}
