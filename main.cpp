/* Nim / Nama : 13517078 / Irfan Sofyana Putra
   Nama File  : main.cpp
   Deskripsi  : program untuk mencari solusi dari permasalahan path finding 
*/

#include <cstdio>

using namespace std;


/*Deklarasi variabel persoalan*/

/* ukuran petak */
int n;
/* petak yang digunakan, asumsi ukuran maksimum petak : 5000x5000 */
int arr[5005][5005]; 

/*mendapatkan input dari pengguna*/
void getInput(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
}



int main(){

    return 0;
}