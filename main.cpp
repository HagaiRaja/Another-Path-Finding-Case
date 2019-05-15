#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <unistd.h>
using namespace std;

void printPapan(vector<vector<int>> papanCatur)
{
    // fungsi menampilkan array 2D ke layar
    for (int i = 0; i < papanCatur.size(); i++)
    {
        for (int j = 0; j < papanCatur[i].size() - 1; j++)
        {
            cout << papanCatur[i][j] << " ";
        }
        cout << papanCatur[i][papanCatur[i].size() - 1] << endl;
    }
}
void rekurensFinding(vector<vector<int>> *pd, vector<vector<int>> papanCatur, int brsAwal, int kolAwal)
{
    // fungsi rekursif dengan metode dynamic programming untuk mencari jumlah path yang mungkin
    if (papanCatur[brsAwal][kolAwal] == 0)
    {
        // jika ditemukan elemen dengan nilai 0
        if (brsAwal == papanCatur.size() - 1 && kolAwal == papanCatur[brsAwal].size() - 1)
        {
            // jika di pojok kanan bawah maka ubah menjadi 1
            ((*pd)[brsAwal][kolAwal]) = 1;
        }
    }
    else
    {
        // jika elemen bukan bernilai 0
        int count = papanCatur[brsAwal][kolAwal]; // nilai element sekarang
        // mencoba semua kemungkinan jalur dengan nilai count dari petak sekarang
        for (int i = 0; i <= count; i++)
        {
            if (brsAwal + i < papanCatur.size())
            {
                // jika i tidak melewati batas baris
                int j = count - i;

                if (kolAwal + j < papanCatur[i].size())
                {
                    // jika j tidak melewati batas kolom
                    int brs = brsAwal + i;
                    int kol = kolAwal + j;
                    if (((*pd)[brs][kol]) == 0)
                    {
                        // menghitung jumlah path dari jalur tersebut ke final
                        rekurensFinding(pd, papanCatur, brs, kol);
                    }
                    // jumlahkan semua kemungkinannya
                    ((*pd)[brsAwal][kolAwal]) += (*pd)[brs][kol];
                }
            }
        }
    }
}

int pathFinding(vector<vector<int>> papanCatur)
{
    // fungsi yang mereturn jumlah path yang mungkin dari pojok kiri atas ke pojok kanan bawah
    vector<vector<int>> pd(papanCatur.size(), vector<int>(papanCatur.size()));

    rekurensFinding(&pd, papanCatur, 0, 0);

    return pd[0][0];
}

int main()
{
    // Main program
    int n;                  // dimensi array
    int input;              // variabel sementara menyimpan input user
    vector<int> tempVector; // array 1 D
    while (cin >> input)
        // menerima input hingga habis
        tempVector.push_back(input);
    // mencari dimensi
    n = sqrt(tempVector.size());
    vector<vector<int>> papanCatur(n, vector<int>(n)); // array 2D
    // convert dari 1D ke 2D
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            papanCatur[i][j] = tempVector[i * n + j];
        }
    }
    chrono::time_point<chrono::system_clock> start, end;
    // start timer
    start = chrono::system_clock::now();
    // hitung path yang mungkin
    int path = pathFinding(papanCatur);
    // stop timer
    end = chrono::system_clock::now();
    // hitung durasi
    chrono::duration<double> durasi = end - start;
    // print jumlah path
    cout << path << endl;
    // print durasi waktu dalam ms
    cout << durasi.count() * 1000 << "ms" << endl;
    return 0;
}