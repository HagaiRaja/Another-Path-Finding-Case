#include <bits/stdc++.h>
#include <ctime>
using namespace std;
  
struct Point{
    int x;
    int y;
};
int N;

int pathFinding(int **M){
    queue<Point> q;
    int result[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            result[i][j] = 0;
        }
    }

    Point p; p.x = 0; p.y = 0;
    q.push(p);
    while (!q.empty()){
        Point temp = q.front();
        q.pop();
        int el = M[temp.x][temp.y]; 
        if (el != 0){
            for (int i=0; i<=el; i++){
                Point next;
                next.x = temp.x+i;
                next.y = temp.y+el-i;
                if (!(next.x >= N || next.y >= N)){
                    q.push(next);
                    result[next.x][next.y]++;
                }
            }
        }
    }
    return result[N-1][N-1];
}

int main() { 
    cin >> N;
    int **M = new int*[N];
    for (int i=0; i<N; i++){
        M[i] = new int[N];
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> M[i][j];
        }
    }
    clock_t start = clock();
    cout << pathFinding(M) << endl;
    clock_t end = clock();

    cout << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms\n";
    
    return 0; 
}