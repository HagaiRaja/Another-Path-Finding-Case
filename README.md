# Dynamic Programming : Another Path Finding Case

## Dynamic Programming
Dynamic Programming adalah metode menyelesaikan masalah dengan cara menguraikan permasalahan menjadi beberapa tahap penyelesaian. Penyelesaian masalah dalam setiap tahapnya diselesaikan dengan menggunakan tabel-tabel. Solusi dari persoalan tersebut merupakan serangkaian keputusan yang saling berkaitan.

Rangkaian keputusan yang optimal dibuat menggunakan prinsip optimalitas. Prinsip Optimalitas adalah jika solusi optimal, maka bagian solusi sampai tahap ke-k juga optimal. 

Dalam solusi yang telah dirancang dalam program ini, tabel yang digunakan hanya ada satu, yaitu tabel yang berisi tentang posisi-posisi yang masih dapat ditelusuri dalam peta.

Pencarian dihentikan ketika posisi berada di N,N atau jika peta berisi 0 pada posisi sekarang. Jika peta berisi 0 tetapi posisi bukan berada di N,N maka pencarian dihentikan

## Path Finding
Path Finding adalah metode penyelesaian sebuah masalah pencarian jalan dari sebuah lokasi ke lokasi tertentu. Path Finding biasanya dilakukan dengan berbagai macam pertimbangan, seperti pencarian jalan terpendek, pencarian jalan dengan bobot terendah, dan lain-lain.

Dalam kasus ini, path finding tidak memerlukan pertimbangan. Solusi yang dihasilkan hanya berupa banyaknya kombinasi jalan dari titik awal (0,0) ke titik (N,N).

## Langkah Program
1. Program akan membaca masukan dari pengguna berupa matriks angka
2. Program melakukan inisialisasi variabel-variabel yang akan digunakan seperti posisi, tabel solusi, dan count
3. Program mencatat waktu dalam sistem sebagai waktu awal
4. Pada awal pencarian jalan, program memasukkan titik 0,0 ke dalam tabel
5. Program kemudian mengambil elemen pertama dari tabel.
6. Program melakukan pemeriksaan terhadap semua kemungkinan perubahan posisi. Jika setiap posisi tersebut tidak melanggar aturan (keluar tabel), program akan memasukkan posisi tersebut ke dalam tabel
7. Jika posisi pada peta yang sedang diperiksa bernilai 0 dan berada di N,N maka program akan menambah jumlah count. Jika bukan berada di N,N, maka pencarian dihentikan.
8. Program mengulangi langkah 5 selama tabel masih memiliki elemen didalamnya

## Screenshot 1
![alt text](https://github.com/timmysutanto/Another-Path-Finding-Case/blob/master/Screenshot%20from%202019-05-20%2012-15-34.png)

## Screenshot 2
![alt text](https://github.com/timmysutanto/Another-Path-Finding-Case/blob/master/Screenshot%20from%202019-05-20%2012-16-14.png)



