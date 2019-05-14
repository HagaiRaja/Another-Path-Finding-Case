from sys import argv
import numpy as np
import time

""" IDE Dynamic Programming :
(Memoization) Tiap point yang sudah dikunjungi disimpan berapa banyak
jalur dari point tersebut ke goal point, jadi tidak usah meng-expand
point yang sudah dikunjungi
 """

def RecursiveDP(currPoint, goalPoint, pointSolution, matriks):
    if currPoint not in pointSolution:
        pointSolution[currPoint] = 0

        bottomNumber = matriks[currPoint[0]][currPoint[1]]

        if bottomNumber > 0:
            nextPoints = []

            for i in range(bottomNumber+1):
                nextPointRow = currPoint[0] + i
                nextPointCol = currPoint[1] + bottomNumber - i

                if nextPointRow < matriks.shape[0] and nextPointCol < matriks.shape[1]:
                    nextPoints += [(nextPointRow, nextPointCol)]

            for point in nextPoints:
                if point == goalPoint:
                    pointSolution[currPoint] += 1
                elif point in pointSolution:
                    pointSolution[currPoint] += pointSolution[point]
                else:
                    RecursiveDP(point, goalPoint, pointSolution, matriks)
                
def main():
    ##Memulai timer
    start = time.time()

    ##Baca file matriks
    matriks = np.loadtxt(argv[1], dtype='int')
    row, col = matriks.shape

    ##Persiapkan dictionary untuk DP
    pointSolution = dict()

    ##Mulai berjalan dari point 1,1
    currPoint = (0, 0)
    goalPoint = (row-1, col-1)

    ##Jika goal point tidak bernilai 0
    if matriks[goalPoint[0]][goalPoint[1]] != 0:
        print(0)
    else:
        RecursiveDP(currPoint, goalPoint, pointSolution, matriks)

        totalSolution = 0
        for i in pointSolution:
            totalSolution += pointSolution[i]

        print(totalSolution)

    ##Menghentikan timer
    end = time.time()
    print((end-start)*1000, "ms")

if __name__ == "__main__":
    main()