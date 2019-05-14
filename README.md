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

**Setelah program dan laporan pada Readme.md anda sudah selesai, lakukan pull request kembali pada branch ini.**

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

## Penilaian
- Kebenaran keluaran fungsi - 40%
- Pemahaman tentang dynamic programming dan path finding (jelaskan langkah yang digunakan secara singkat) - 30%
- Kecepatan eksekusi program (lampirkan screenshot pada readme beserta spesifikasi mesin yang dipakai untuk testing) - 20%
- Kecepatan Pull Request - 10%

Nilai maksimum yang bisa didapatkan adalah **700** poin. _(Tujuh Ratus)_

## Submisi
Nama : M. Khairul Makirin  
NIM : 13517088

### Penjelasan
Dalam mencari berapa banyak solusi dari suatu point, bisa dicari dengan menyimpan berapa banyak jalur yang dapat dilewati dari suatu point ke point tujuan, sehingga tidak harus meng-expand simpul/point yang sudah sebelumnya di-expand mis.
```
1 1
1 0
```

dictionary-nya berbentuk:  
{ (0, 0): 0,   
  (0, 1): 1,  
  (1, 0): 1}}  
  
sedangkan untuk matriks seperti,
```
2 3 0 1 3 1
1 0 1 3 1 3
0 2 3 1 3 1
3 1 1 0 1 0
1 2 1 3 1 3
3 1 1 0 1 0
```
dictionary-nya berbentuk:  
{ (0, 0): 0,  
  (0, 2): 0,  
  (1, 1): 0,  
  (2, 0): 0}

```
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
```

dictionary-nya berbentuk:  
{ (0, 0): 0,  
  (0, 2): 0,  
  (2, 3): 1,  
  (3, 2): 1,  
  (1, 1): 0,  
  (1, 3): 0,  
  (2, 2): 0,  
  (3, 1): 1,  
  (2, 0): 0,  
  (2, 1): 2,  
  (3, 0): 1}  

sehingga kita tinggal menghitung berapa banyak solusi yang ditemukan dengan menambahkan semua value dari semua key di dictionary.  

### Test Case
```
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
```
6  
1.4369487762451172 ms  

```
2 3 0 1 3 1
1 0 1 3 1 3
0 2 3 1 3 1
3 1 1 0 1 0
1 2 1 3 1 3
3 1 1 0 1 0
```
0  
1.6489028930664062 ms  

### Spesifikasi Komputer
Model : Dell Inspiron 7472 2018  
CPU : Intel Core i5-8250U  
GPU : Nvidia MX150  
RAM : 4 GB  
OS : Linux Mint 19.1 Tessa  
