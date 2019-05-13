#include <bits/stdc++.h>
#include <ctime>
using namespace std;
 
int N;
int **result;

int find(int **M, int i, int j){
    // BASIS
    if (i == N-1 && j == N-1)return 1;
    if (i >= N || j >= N) return 0;
    if (M[i][j] == 0) return 0;
    if (result[i][j] != 0) return result[i][j];
    // REKURSIF
    for (int x=0; x<=M[i][j]; x++){
        result[i][j] += find(M,i+x,j+M[i][j]-x);
    }
    return result[i][j];
}

int pathFinding(int **M){
    int temp = find(M,0,0);
    return temp;
}

int main() { 
    cin >> N;
    int **M = new int*[N];
    result = new int*[N];
    for (int i=0; i<N; i++){
        M[i] = new int[N];
        result[i] = new int[N];
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> M[i][j];
            result[i][j] = 0;
        }
    }
    clock_t start = clock();
    cout << pathFinding(M) << endl;
    clock_t end = clock();

    cout << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
    
    return 0; 
}