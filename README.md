# Dynamic Programming : Another Path Finding Case

## Latar Belakang
*Path Finding* adalah masalah yang berfokus untuk mencari langkah paling optimum untuk bergerak dari posisi asal ke posisi akhir dengan batasan-batasan (*constraints*) tertentu. Masalah ini dapat diselesaikan dengan mudah menggunakan pendekatan strategi algoritma *dynamic programming* seperti pada contoh berikut oleh  [GeeksForGeeks](https://www.geeksforgeeks.org/min-cost-path-dp-6/). Banyak penerapan yang memiliki fokus berbeda terkait topik *Path Finding* seperti pada robot, game, image processing serta pengelolahan efisien industri. Semua kasus ini berkutat dalam mengoptimasi dari sisi paling pendek, paling murah, paling cepat dan parameter lainnya. 

Pada tugas kali ini, anda akan bertugas untuk memodifikasi algoritma *path finding* agar sesuai dengan kebutuhan soal. Diharapkan melalui tugas ini, anda dapat lebih memahami penerapan strategi *dynamic programming* yang sering digunakan dalam dunia IT terkhusus filosofi cara berpikir penyelesaian masalah terkait *path finding*. Selamat mengerjakan!

## Kasus Path Finding
Berikut adalah deskripsi kondisi persoalan yang akan diselesaikan.
1. Terdapat sebuah papan catur *N x N* dengan setiap kotaknya berisi bilangan non negatif.
2. Di awal, suatu bidak berada kotak (1, 1) atau yang di pojok kiri atas.
3. Berikutnya secara berulang bidak dapat dipindahkan (1) horizontal ke kanan, atau (2) vertikal ke bawah sekian kotak sebanyak dengan bilangan pada kotak terakhir bidak itu berada, kecuali kalau membawa bidak keluar dari papan.
4. Tujuan akhir adalah kotak (N, N) atau yang pojok kanan bawah.
5. Bila bilangan terakhir adalah 0 dan bukan di pojok maka bidak berhenti (tidak dapat melanjutkan langkah kecuali kalau sudah mencapai tujuan).
1
## Spesifikasi
Lakukan fork terhadap repository ini.

Buatlah dalam bahasa pemrograman **_Python_** atau **_C++_**, sebuah fungsi dalam program berbasis CLI yang dapat menyelesaikan persoalan cerita diatas yang menghitung :
1. Banyaknya cara yang mungkin untuk bisa mencapai tujuan akhir.
2. Waktu yang digunakan untuk mencari semua solusi.

Deklarasi fungsi :
```C++
int pathFinding(papanCatur);
```
Fungsi menampilkan jumlah kemungkinan dan waktu ke layar serta melakukan pengembalian jumlah kemungkinan tersebut.

## Strategi Penyelesaian dengan Dynamic Programming (DP)
Persoalan ini dapat diselesaikan dengan menggunakan dynamic programming. State persoalan ini adalah indeks baris dan kolom yang ada pada papan catur. Kita lalu bisa mendefinisikan ways[i][j] sebagai banyaknya jalan dari petak (1, 1) menuju petak (i, j) dengan aturan yang sudah dijelaskan sebelumnya di atas. 

Untuk mengimplementasikan dynamic programming ini, kita dapat melakukannya dengan teknik bottom-up, yaitu melakukan perhitungan berdasarkan kasus kecil yang kecil (base case) menuju kasus yang lebih besar. Adapun base case dan relasi antar fungsi yang digunakan adalah sebagai berikut

## Base case
ways[1][1] = 1

Obviuos, banyak jalan dari petak (1, 1) ke (1, 1) adalah 1 cara.

## Recurrence
<a href="https://www.codecogs.com/eqnedit.php?latex=ways[i][j]&space;=&space;\sum_{x,&space;y}ways[x][y]" target="_blank"><img src="https://latex.codecogs.com/svg.latex?ways[i][j]&space;=&space;\sum_{x,&space;y}ways[x][y]" title="ways[i][j] = \sum_{x, y}ways[x][y]" /></a>


## Contoh Kasus Uji
### Contoh Kasus Uji 1 
Input :
```
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
```
Output :
```
6
20ms
```
Penjelasan :
jalur yang mungkin adalah
1. [1][1] -> [2][2] -> [2][4] -> [4][4]
2. [1][1] -> [3][1] -> [4][3] -> [4][4]
3. [1][1] -> [3][1] -> [3][4] -> [4][4]
4. [1][1] -> [1][3] -> [1][4] -> [4][4]
5. [1][1] -> [1][3] -> [2][3] -> [3][4] -> [4][4]
6. [1][1] -> [1][3] -> [2][3] -> [4][3] -> [4][4]

### Contoh Kasus Uji 2
Input:
```
2 3 0 1 3 1
1 0 1 3 1 3
0 2 3 1 3 1
3 1 1 0 1 0
1 2 1 3 1 3
3 1 1 0 1 0
```
Output :
```
0
1ms
```

