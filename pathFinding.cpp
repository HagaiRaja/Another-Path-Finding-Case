#include <bits/stdc++.h>
using namespace std;
const int NMax = 100;
inline void IOFILE() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int C[NMax + 1][NMax + 1];
int comb(int n, int k) {
    if (C[n][k] != 0) return C[n][k];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            C[i][j] = (j == 0 || j == i) ? 1 : C[i - 1][j - 1] + C[i - 1][j];
    return C[n][k];
}

int papanCatur[NMax][NMax], waysTo[NMax][NMax], N;
void waysFromCell(int r, int c) {
    if ((r < N && c <= N) || (r <= N && c < N)) {
        for (int k = 0; k <= papanCatur[r][c]; k++) {
            int row = r + k;
            int col = c + papanCatur[r][c] - k;
            if (row <= N && col <= N && papanCatur[r][c] != 0) {
                waysTo[row][col] += comb(papanCatur[r][c], k);
                waysFromCell(row, col);
            }
        }
    }
}

int pathFinding(int papanCatur[NMax][NMax]) {
    waysFromCell(1, 1);
    return waysTo[N][N];
}

void readPapanCatur(int papanCatur[NMax][NMax]) {
    int x;
    queue<int> inputs;
    while (cin >> x) inputs.push(x);
    N = (int)sqrt(inputs.size());
    // assert: inputs.size() always perfect square
    assert(N * N == inputs.size());
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            papanCatur[i][j] = inputs.front();
            inputs.pop();
        }
    }
}
int main() {
    IOFILE();
    readPapanCatur(papanCatur);
    cout << pathFinding(papanCatur) << endl;
}
