/*
ID: shenqi11
TASK: pprime
LANG: C++
*/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace pprime {
ifstream fin("pprime.in");
ofstream fout("pprime.out");
int a, b;
vector<int> ans;

bool is_prime(int x) {
    int lim = sqrt(x);
    for (int i = 2; i <= lim; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void gen_odd(int x) {
    string s = to_string(x), t = s;
    reverse(t.begin(), t.end());
    string res;
    int y;
    for (int i = 0; i < 10; i++) {
        res = s;
        res.push_back('0' + i);
        res += t;
        y = stoi(res);
        if (y >= a && y <= b && is_prime(y)) ans.push_back(y);
    }
}

void gen_even(int x) {
    string s = to_string(x), t = s;
    reverse(t.begin(), t.end());
    int y = stoi(s + t);
    if (y >= a && y <= b && is_prime(y)) ans.push_back(y);
}

void solve() {
    fin >> a >> b;
    if (a <= 5) ans.push_back(5);
    if (a <= 7) ans.push_back(7);
    for (int i = 1; i <= 999; i++) gen_odd(i);
    for (int i = 1; i <= 9999; i++) gen_even(i);
    sort(ans.begin(), ans.end());
    for (int num : ans) fout << num << "\n";
}
}  // namespace pprime

int main() {
    pprime::solve();
    return 0;
}
