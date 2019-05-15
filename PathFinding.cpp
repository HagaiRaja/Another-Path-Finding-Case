/* Nim / Nama : 13517078 / Irfan Sofyana Putra
   Nama File  : PathFinding.cpp
   Deskripsi  : program untuk mencari solusi dari permasalahan path finding 
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

/*Deklarasi variabel persoalan*/
int size; /*ukuran papan catur */
vector<vector<int> > ways; /*tabel dp*/
vector<vector<int> > chessBoard; /*papan catur */


/*mendapatkan input (papan catur) */
void getInput(){
    int dummy;
    vector<int> tmpInput;
    //ukuran tidak diketahui, masukkan ke variabel sementara saja
    while (scanf("%d", &dummy) != EOF)
        tmpInput.push_back(dummy); 
    //ukuran papan = sqrt(banyak bilangan pada input)
    size = (int)sqrt((int)tmpInput.size());
    int idx = 0;
    for (int i = 0; i < size; i++){
        vector<int> tmp;
        for (int j = 0; j < size; j++){
            tmp.push_back(tmpInput[idx]);
            idx++;
        }
        chessBoard.push_back(tmp);
    }
}

/*fungsi untuk mengecek apakah suatu koordinat masih
  ada di dalam papan catur atau tidak */
bool isValid(int row,int column,int size){
    return (row >= 0 && row < size && 
            column >= 0 && column < size);
}

/* prosedur penyelesaian */
int pathFinding(vector<vector<int> > chessBoard){
    /*inisialisasi tabel dp*/
    for (int i = 0; i < size; i++){
        vector<int> tmp;
        for (int j = 0; j < size; j++){
            tmp.push_back(0);
        }
        ways.push_back(tmp);
    }
    
    /*melakukan dynamic programming secara bottom up*/
    ways[0][0] = 1;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (chessBoard[i][j] > 0){
                for (int k = 0; k <= chessBoard[i][j]; k++){
                    //menggunakan k langkah untuk berjalan vertikal
                    int nextRow = i + k;
                    //menggunakan (chessBoard[i][j]-k) langkah untuk berjalan horizontal
                    int nextColumn = j + chessBoard[i][j] - k;
                    if (isValid(nextRow, nextColumn, size)){
                        ways[nextRow][nextColumn]+=ways[i][j];
                    }            
                }
            }
        }
    }
    /* mengembalikan banyaknya jalur menuju petak NxN */
    return ways[size-1][size-1];
}

/*prosedur untuk menyelesaikan permasalahan "another path finding case" */
void Solve(){
    /*mendapatkan papan catur dari input*/
    getInput();
    
    /*memanggil prosedur penyelesaian dan menghitung waktu eksekusi-nya*/
    clock_t timeStart = clock();
    printf("%d\n", pathFinding(chessBoard));
    printf("%.3lf ms\n", (double)(clock() - timeStart)/(CLOCKS_PER_SEC/1000));
}

int main(){
    //memanggil prosedur penyelesaian masalah
    Solve();
    return 0;
}