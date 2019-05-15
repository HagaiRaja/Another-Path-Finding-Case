#Seleksi Calon IRK 2019
#NIM / Nama     : 13517048 / Leonardo
#Topik Program  : Dynamic Programming - Another Path Finding Case

from time import time

def printMatrix(mat):
    for i in mat:
        print(i)

def addUnique(li, elmt):
    #seperti add pada set, namun pada list
    if (elmt not in li): li.append(elmt)

def countTotal(total_move, currentPoint, finalPoint, matrix_of_boolean):
    #pendekatan rekursif, top down
    if (currentPoint == finalPoint):
        #Basis 1: sudah sampai ke poin final, maka 1 buah move ditemukan
        return 1
    elif (not matrix_of_boolean[currentPoint[0]][currentPoint[1]]):
        #Basis 2: stuck di Point yang tidak bisa menuju ke Point solusi
        return 0
    else: #Rekurens
        moves = 0
        for i in total_move:
            if (i[0] == currentPoint):
                moves += countTotal(total_move, i[1], finalPoint, matrix_of_boolean)
        return moves

def DFS(matrix_of_int, matrix_of_boolean, initialPoint, initPoint2, finalPoint, moves, total_move):
    #bentuk initialPoint, finalPoint = [i, j] (Point)
    if (initPoint2 == finalPoint and moves == 0):
        matrix_of_boolean[initialPoint[0]][initialPoint[1]] = True
        addUnique(total_move, [initialPoint, finalPoint])
    elif (initPoint2 == finalPoint and moves != 0):
        return
    elif (initPoint2 != finalPoint and moves == 0):
        return
    else:
        #vertikal ke bawah
        nextPoint = [initPoint2[0]+1, initPoint2[1]]
        if (nextPoint[0] < len(matrix_of_boolean)):
            new_moves = moves - 1
            DFS(matrix_of_int, matrix_of_boolean, initialPoint, nextPoint, finalPoint, new_moves, total_move)
        #horizontal ke kanan
        nextPoint = [initPoint2[0], initPoint2[1]+1]
        if (nextPoint[1] < len(matrix_of_boolean)):
            new_moves = moves - 1
            DFS(matrix_of_int, matrix_of_boolean, initialPoint, nextPoint, finalPoint, new_moves, total_move)

def setInitialBool(matrix_of_int):
    #set semua elemen sebagai False di matrix of boolean, kecuali elemen N,N
    matrix_of_boolean = [[False for i in range(len(matrix_of_int))] for i in range(len(matrix_of_int))]
    matrix_of_boolean[-1][-1] = True
    return matrix_of_boolean

def getTruePoints(matrix_of_boolean):
    #mengembalikan semua Point yang bernilai True di matrix of boolean
    truePoints = []
    for a in range(len(matrix_of_boolean)):
        js = [b for b, v in enumerate(matrix_of_boolean[a]) if v]
        for c in js:
            temp_final = [a, c]
            truePoints.append(temp_final)
    return truePoints
   
def DPAlgorithm(matrix_of_input, matrix_of_boolean, total_move):
    #DYNAMIC PROGRAMMING: memoization dengan pendekatan bottom up
    mat_len = len(matrix_of_boolean)
    #Mengisi matrix of boolean
    truePoints = getTruePoints(matrix_of_boolean)
    while (True):
        truePoints2 = truePoints
        for i in range(mat_len):
            for j in range(len(matrix_of_boolean[0])):
                initialPoint = [i,j]
                moves = matrix_of_input[i][j]
                for truePoint in truePoints:
                    DFS(matrix_of_input, matrix_of_boolean, initialPoint, initialPoint, truePoint, moves, total_move)
                
        #printMatrix(matrix_of_boolean)
        truePoints = getTruePoints(matrix_of_boolean)
        if (truePoints == truePoints2):
            #sudah tidak ada Point yang berubah nilai
            break
    #menghilangkan semua kemunculan [N,N] pada total_move
    total_move = list(filter((([[mat_len-1, mat_len-1], [mat_len-1, mat_len-1]]).__ne__), total_move))
    return countTotal(total_move, [0,0], [mat_len-1, mat_len-1], matrix_of_boolean)

def pathFinding(matrix_of_input):
    matrix_of_boolean = setInitialBool(matrix_of_input)
    start = time()
    total_move = []
    #mengisi matrix of boolean dan menghitung total gerakan yang dibutuhkan
    total = DPAlgorithm(matrix_of_input, matrix_of_boolean, total_move)
    end = time()
    print(total)
    print(str(round((end-start)*1000)) + "ms")
    return total

if __name__ == '__main__':
    initial_input = input()
    #ASUMSI: jika matrix berukuran 1x1, tidak ada path yang ditemukan karena dianggap sudah sampai
    final_input = initial_input.split()
    final_input = [int(i) for i in final_input]
    matrix_of_input = []
    matrix_of_input.append(final_input) #dapat panjang(N) input
    for _ in range(1, len(final_input)):#lakukan input baris sebanyak N-1
        temp_input = input()
        temp_list = temp_input.split()[:len(final_input)]
        temp_list = [int(elem) for elem in temp_list]
        matrix_of_input.append(temp_list)

    total = pathFinding(matrix_of_input)
    
