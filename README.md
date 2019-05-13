# Dynamic Programming : Another Path Finding Case

## Kasus Path Finding
Berikut adalah deskripsi kondisi persoalan yang akan diselesaikan.
1. Terdapat sebuah papan catur *N x N* dengan setiap kotaknya berisi bilangan non negatif.
2. Di awal, suatu bidak berada kotak (1, 1) atau yang di pojok kiri atas.
3. Berikutnya secara berulang bidak dapat dipindahkan (1) horizontal ke kanan, atau (2) vertikal ke bawah sekian kotak sebanyak dengan bilangan pada kotak terakhir bidak itu berada, kecuali kalau membawa bidak keluar dari papan.
4. Tujuan akhir adalah kotak (N, N) atau yang pojok kanan bawah.
5. Bila bilangan terakhir adalah 0 dan bukan di pojok maka bidak berhenti (tidak dapat melanjutkan langkah kecuali kalau sudah mencapai tujuan).

## Dynamic Programming Pada Kasus Path Finding
Untuk papan catur M dengan ukuran NxN, persoalan Dynamic Programming pada petak i,j dinotasikan sebagai pathFinding(i,j) di mana pathFinding adalah fungsi yang mengembalikan berapa banyak cara yang mungkin bisa mencapai titik N,N dari i,j.

Secara matematis, persoalan ini dapat dirumuskan menjadi

![alt text](https://raw.githubusercontent.com/juniardiakbar/Another-Path-Finding-Case/master/pict/equation.jpg)

## Contoh Kasus Uji
### Contoh Kasus Uji 1 
Input :
```
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0
```
Output:

![alt text](https://raw.githubusercontent.com/juniardiakbar/Another-Path-Finding-Case/master/pict/1.jpg)

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
Output:

![alt text](https://raw.githubusercontent.com/juniardiakbar/Another-Path-Finding-Case/master/pict/2.jpg)

### Contoh Kasus Uji 3
```
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
```
Output:

![alt text](https://raw.githubusercontent.com/juniardiakbar/Another-Path-Finding-Case/master/pict/3.jpg)

### Contoh Kasus Uji 4
```
3 0 1 4 0 3 2 1
2 1 2 0 1 0 4 2
1 0 1 3 3 2 1 2
1 2 1 1 2 1 2 3
0 3 2 1 1 3 3 0
0 2 4 0 1 3 2 0
1 2 0 1 3 2 0 4
3 2 0 4 3 1 2 2
```
Output:

![alt text](https://raw.githubusercontent.com/juniardiakbar/Another-Path-Finding-Case/master/pict/4.jpg)

## Spesifikasi Mesin
- Linux Ubuntu 18.04
- RAM 4 GB
- Processor : Intel Core I5
