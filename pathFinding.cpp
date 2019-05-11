#include <assert.h>
#include <math.h>
#include <ctime>
#include <iostream>
#include <queue>
using namespace std;
const int NMax = 10000;

int C[NMax + 1][NMax + 1];  // memo
int comb(int n, int k) {    // count
    assert(0 <= n && n <= NMax && 0 <= k && k <= n);
    if (C[n][k] != 0) return C[n][k];  // return from memo
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            C[i][j] = (j == 0 || j == i)
                          ? 1
                          : C[i - 1][j - 1] + C[i - 1][j];  // memoize
    return C[n][k];
}

int papanCatur[NMax][NMax];
int waysTo[NMax][NMax];
int N;  // N * N == sizeof(papanCatur)
void waysFromCell(int papanCatur[NMax][NMax], int r, int c) {
    if ((r < N && c <= N) || (r <= N && c < N)) {
        for (int k = 0; k <= papanCatur[r][c]; k++) {
            int num = papanCatur[r][c];
            int row = r + k;
            int col = c + num - k;
            if (row <= N && col <= N) {
                if (1 <= num && num <= (N - r) + (N - c)) {
                    waysTo[row][col] += comb(num, k);
                    waysFromCell(papanCatur, row, col);
                }
            }
        }
    }
}

int pathFinding(int papanCatur[NMax][NMax]) {
    waysFromCell(papanCatur, 1, 1);
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
int main(int argc, char** argv) {
    // Preparing Data
    freopen(argv[1], "r", stdin);
    // freopen("output.txt", "w", stdout);
    readPapanCatur(papanCatur);

    // Start Measure Time
    clock_t start = clock();
    int countPath = pathFinding(papanCatur);
    clock_t end = clock();
    // End Measure Time

    // Output answer
    cout << countPath << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}
