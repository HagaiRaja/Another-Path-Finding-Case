# Dynamic Programming : Another Path Finding Case

## Path Finding
Path finding dalam permasalahan kali ini ialah mencari suatu jalan dari petak 1,1 menuju petak N,N dengan catatan disetiap langkahnya hanya boleh berjalan kekanan atau kebawah sebanyak jumlah angka di petak yang terakhir ditempati.

## Dynamic Programming
Permasalahan path finding ini dapat diselesaikan dengan Dynamic Programming (DP). DP adalah teknik pemecahan masalah dengan memecah perseolan besar menjadi persoalan yang lebih kecil sehingga perseolan yang besar dapat diselesaikan. Kebanyakan program DP bisa juga diselesaikan dengan cara rekursif. DP ini dianggap sebagai teknik efesiensi waktu dari teknik pemecahan masalah secara rekursif karena dengan DP dapat memoisasi hasil pencarian dari STEP yang sudah dijalankan sehingga tidak perlu dicari kembali. 

### Ide Dynamic Programming

Persoalan Dynamic Programming pada petak i,j dinotasikan sebagai pathDP(i,j). Setiap pathDP(i,j) pada rekursif mencari banyaknya macam cara yang dapat ditempuh dari petak (i,j) menuju petak (N,N). Dengan basis pada pathDP(N,N) secara trivia kita bisa tahu bahwa banyaknya cara dari petak (N,N) menuju petak (N,N) adalah 1. Selain itu kita harus menghitung jumlah macam cara dari semua petak yang dapat dijadikan petak selanjutnya. Ini bisa dilakukan dengan cara rekursif.

Secara matematika bisa dinotasikan sebagai berikut :


untuk i = N-1 dan j = N-1, f(i,j) = 1 																		---Basis <br />
untuk i >= N atau j > N,   f(i,j) = 0																		---Basis <br />
selain itu, 		       f(i,j) = <img src="img/sigma.jpg" width="150" height="30" /> 												---Rekursif <br />

## Keterangan
1. Gerak ke kanan ditandai dengan nilai i yang bertambah, sedangkan gerak kebawah ditandakan dengan nilai j yang bertambah

## Spesifikasi Mesin

Processor : Intel Core I5-6200U <br />
RAM : 4 GB <br />
Sistem Operasi : Ubuntu 18.04 <br />

## Cara Menjalankan 
Compile : g++ path-finding.cpp -o path-finding <br />
Run : ./path-finding <br />

## Contoh Inputan / Keluaran

### Inputan 1
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

### Keluaran 1
6
6.748ms

### Masukan 2
2 3 0 1 3 1
1 0 1 3 1 3
0 2 3 1 3 1
3 1 1 0 1 0
1 2 1 3 1 3
3 1 1 0 1 0

### Keluaran 2
0
8.081ms