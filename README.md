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

## Aplikasi Dynamic Programming pada Kasus Path Finding
Pada kasus ini, digunakan algoritma Dynamic Programming dengan fungsi sebagai berikut :

1. f(i,j) = 1 , i = N dan j = N (basis ketika nilai i dan j ada pada titik akhir)
2. f(i,j) = 0 , i > N dan j > N (basis ketika nilai i dan j keluar matriks)
3. f(i,j) = ![Capture](https://user-images.githubusercontent.com/38171936/57959167-a7aa7980-792c-11e9-8a22-2b201d20b553.JPG)

## Spesifikasi Perangkat Keras
1. Intel Core i7-7700 HQ
2. RAM 16 GB
3. Windows 10 Single Language

## Uji Kasus

### Uji Kasus 1
Input :
```
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
```

Output : ![test1](https://user-images.githubusercontent.com/38171936/57958741-07078a00-792b-11e9-895d-e6f420d4ac21.JPG)

### Uji Kasus 2
Input :
```
2 3 0 1 3 1
1 0 1 3 1 3
0 2 3 1 3 1
3 1 1 0 1 0
1 2 1 3 1 3
3 1 1 0 1 0
```

Output : ![tes2](https://user-images.githubusercontent.com/38171936/57958744-0e2e9800-792b-11e9-8fdb-0277dd8da95f.JPG)

### Uji Kasus 3
Input :
```
2 1 3 1 3 1 1 2
3 3 1 3 1 3 2 0
3 2 3 1 2 2 4 0
3 1 1 0 1 3 2 3
1 1 2 3 0 1 2 1
2 1 1 3 2 1 1 4
4 2 1 3 2 2 1 2
0 2 3 0 1 2 3 3
```

Output : ![tes3](https://user-images.githubusercontent.com/38171936/57958751-138be280-792b-11e9-8410-54f4ed80b1b8.JPG)
