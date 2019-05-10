#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
using namespace std;

int N,data[1000005],dp[1005][1005],papanCatur[1005][1005];
int f(int i,int j,int papanCatur[1005][1005]){
  int right,bottom;
  //Jika diluar petak NxN keluarkan nilai 0
  if(i >= N || j >= N) return 0;
  //Jika sudah ada di petak kanan bawah, keluarkan 1
  if(i == N-1 && j == N-1) return 1;
  //Memoisasi DP apabila udah pernah dicari keluarkan saja nilainya
  if(dp[i][j] != -1) return dp[i][j];
  //Inisialisasi dp[i][j]
  dp[i][j] = 0;
  for(int right = 0;right <= papanCatur[i][j];right++){
    bottom = papanCatur[i][j] - right;
    //Proses Rekursif
    dp[i][j] += f(i+right,j+bottom,papanCatur);
  }
  return dp[i][j];
}

int pathFinding(int papanCatur[1005][1005]){
  return f(0,0,papanCatur);
}

int main(){
  int i = 0;
  //Masukan inputan, karena diawal nilai N tidak diketahui, disimpan di array 1 dimensi dulu, nanti baru dipandah ke array 2 dimensi
  while(cin >> data[i]) i++;
  N = (int)sqrt(i);
  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
      papanCatur[i][j] = data[j*N+i];
    }
  }
  clock_t tStart = clock();
  //Inisialisasi semua petak dengan -1
  memset(dp,-1,sizeof dp);

  cout << pathFinding(papanCatur) << endl;
  cout << (double)(clock() - tStart)/CLOCKS_PER_SEC*1000 << "ms" << endl;
}