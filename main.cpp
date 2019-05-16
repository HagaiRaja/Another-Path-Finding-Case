#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <unistd.h>
#include <string.h>
using namespace std;

int n; // dimensi array
int rekurensFinding(int **pd, int **papanCatur, int brsAwal, int kolAwal)
{
    // fungsi rekursif dengan metode dynamic programming untuk mencari jumlah path yang mungkin
    if (brsAwal == n - 1 && kolAwal == n - 1)
    {
        // jika di pojok kanan bawah maka menjadi 1 path
        return 1;
    }
    else if (pd[brsAwal][kolAwal] != -1)
    {
        // jika sudah pernah dilewati
        return pd[brsAwal][kolAwal];
    }
    else if (papanCatur[brsAwal][kolAwal] != 0)
    {
        // jika elemen papanCatur bukan bernilai 0
        int count = papanCatur[brsAwal][kolAwal]; // nilai element sekarang
        // ubah menjadi 0, artinya pernah dicek
        pd[brsAwal][kolAwal] = 0;
        // mencoba semua kemungkinan jalur dengan nilai count dari petak sekarang
        for (int i = 0; i <= count; i++)
        {
            if (brsAwal + i < n)
            {
                // jika i tidak melewati batas baris
                int j = count - i;

                if (kolAwal + j < n)
                {
                    // jika j tidak melewati batas kolom
                    int brs = brsAwal + i;
                    int kol = kolAwal + j;
                    // menghitung jumlah path dari jalur tersebut ke final
                    // jumlahkan semua kemungkinannya
                    pd[brsAwal][kolAwal] += rekurensFinding(pd, papanCatur, brs, kol);
                }
            }
        }
        return pd[brsAwal][kolAwal];
    }
}

int pathFinding(int **papanCatur)
{
    // fungsi yang mereturn jumlah path yang mungkin dari pojok kiri atas ke pojok kanan bawah
    // inisialisasi vektor pd sebagai memory pemrograman dinamis, inisialisasi dengan -1
    // sebagai tanda belum dicek
    int **pd;
    pd = new int *[n];
    for (int i = 0; i < n; i++)
    {
        pd[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            pd[i][j] = -1;
        }
    }
    chrono::time_point<chrono::system_clock> start, end;
    // start timer
    start = chrono::system_clock::now();
    // hitung jumlah path secara rekursif
    int path = rekurensFinding(pd, papanCatur, 0, 0);
    // stop timer
    end = chrono::system_clock::now();
    // hitung durasi
    chrono::duration<double> durasi = end - start;
    // print jumlah path
    cout << path << endl;
    // print durasi waktu dalam ms
    cout << durasi.count() * 1000 << "ms" << endl;
    // return jumlah path
    return path;
}

int main()
{
    // Main program
    int input;              // variabel sementara menyimpan input user
    vector<int> tempVector; // array 1 D
    while (cin >> input)
        // menerima input hingga habis
        tempVector.push_back(input);
    // mencari dimensi
    n = sqrt(tempVector.size());
    int **papanCatur; // array 2D
    papanCatur = new int *[n];
    // convert dari 1D ke 2D
    for (int i = 0; i < n; i++)
    {
        papanCatur[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            papanCatur[i][j] = tempVector[i * n + j];
        }
    }
    // hitung path yang mungkin
    int path = pathFinding(papanCatur);
    return 0;
}