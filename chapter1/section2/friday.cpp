/*
ID: shenqi11
TASK: friday
LANG: C++
*/

#include <fstream>

using namespace std;

namespace friday {
ifstream fin("friday.in");
ofstream fout("friday.out");
int n;
const int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                         {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool is_leap(int y) { return y % 100 == 0 ? y % 400 == 0 : y % 4 == 0; }

void solve() {
    fin >> n;
    int cur = 0, ans[7] = {0};  // the first 13th is on Saturday
    for (int i = 1900; i <= 1900 + n - 1; i++) {
        for (int j = 0; j < 12; j++) {
            ans[cur]++;
            cur = (cur + days[is_leap(i)][j]) % 7;
        }
    }
    fout << ans[0];
    for (int i = 1; i < 7; i++) fout << " " << ans[i];
    fout << "\n";
}
}  // namespace friday

int main() {
    friday::solve();
    return 0;
}
