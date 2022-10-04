/*
ID: shenqi11
TASK: transform
LANG: C++
*/

#include <fstream>

using namespace std;

namespace transform {
ifstream fin("transform.in");
ofstream fout("transform.out");
int n;
const int maxn = 15;
struct Board {
    char b[maxn][maxn];
} board, target;

// rotate 90 degree clockwise: [r, c] -> [c, n - r]
Board rotate(const Board &board) {
    Board nb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nb.b[j][n - 1 - i] = board.b[i][j];
        }
    }
    return nb;
}

// reflect horizontally, [r, c] -> [r, n - c]
Board reflect(const Board &board) {
    Board nb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nb.b[i][n - 1 - j] = board.b[i][j];
        }
    }
    return nb;
}

bool equal(const Board &b1, const Board &b2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b1.b[i][j] != b2.b[i][j]) return false;
        }
    }
    return true;
}

void solve() {
    fin >> n;
    for (int i = 0; i < n; i++) fin >> board.b[i];
    for (int i = 0; i < n; i++) fin >> target.b[i];

    if (equal(rotate(board), target))
        fout << "1\n";
    else if (equal(rotate(rotate(board)), target))
        fout << "2\n";
    else if (equal(rotate(rotate(rotate(board))), target))
        fout << "3\n";
    else if (equal(reflect(board), target))
        fout << "4\n";
    else if (equal(rotate(reflect(board)), target) ||
             equal(rotate(rotate(reflect(board))), target) ||
             equal(rotate(rotate(rotate(reflect(board)))), target))
        fout << "5\n";
    else if (equal(board, target))
        fout << "6\n";
    else
        fout << "7\n";
}
}  // namespace transform

int main() {
    transform::solve();
    return 0;
}
