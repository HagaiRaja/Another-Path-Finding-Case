from time import time

def printMatrix(mat):
    for i in mat:
        print(i)

def addUnique(li, elmt):
    if (elmt not in li):
        li.append(elmt)

def countTotal(total_move, currentPoint, finalPoint, matrix_of_boolean):
    if (currentPoint == finalPoint):
        return 1
    elif (not matrix_of_boolean[currentPoint[0]][currentPoint[1]]):
        return 0
    else:
        moves = 0
        for i in total_move:
            if (i[0] == currentPoint):
                moves += countTotal(total_move, i[1], finalPoint, matrix_of_boolean)
        return moves

def DFS(matrix_of_int, matrix_of_boolean, initialPoint, initPoint2, finalPoint, moves, total_move):
    #initialPoint, finalPoint = [i, j]
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
    matrix_of_boolean = [[False for i in range(len(matrix_of_int))] for i in range(len(matrix_of_int))]
    matrix_of_boolean[-1][-1] = True
    return matrix_of_boolean

def getFinalPoints(matrix_of_boolean):
    finalPoints = []
    for a in range(len(matrix_of_boolean)):
        js = [b for b, v in enumerate(matrix_of_boolean[a]) if v]
        for c in js:
            temp_final = [a, c]
            finalPoints.append(temp_final)
    return finalPoints
   
def DPAlgorithm(matrix_of_input, matrix_of_boolean, total_move):
    #DYNAMIC PROGRAMMING: memoization dengan pendekatan bottom up
    mat_len = len(matrix_of_boolean)
    #mengisi matrix of boolean
    finalPoints2 = getFinalPoints(matrix_of_boolean)
    while (True):
        finalPoints = finalPoints2
        for i in range(mat_len):
            for j in range(len(matrix_of_boolean[0])):
                initialPoint = [i,j]
                moves = matrix_of_input[i][j]
                for truePoint in finalPoints:
                    DFS(matrix_of_input, matrix_of_boolean, initialPoint, initialPoint, truePoint, moves, total_move)
        
        #printMatrix(matrix_of_boolean)
        finalPoints2 = getFinalPoints(matrix_of_boolean)
        if (finalPoints == finalPoints2):
            break

    total_move = list(filter((([[mat_len-1, mat_len-1], [mat_len-1, mat_len-1]]).__ne__), total_move))
    return countTotal(total_move, [0,0], [mat_len-1, mat_len-1], matrix_of_boolean)

def pathFinding(matrix_of_input):
    matrix_of_boolean = setInitialBool(matrix_of_input)
    start = time()
    total_move = []
    total = DPAlgorithm(matrix_of_input, matrix_of_boolean, total_move)
    end = time()
    print(total)
    print(str(round((end-start)*1000)) + "ms")
    return total

if __name__ == '__main__':
    initial_input = input()
    final_input = initial_input.split()
    final_input = [int(i) for i in final_input]
    matrix_of_input = []
    matrix_of_input.append(final_input)
    for i in range(1, len(final_input)):
        temp_input = input()
        temp_list = temp_input.split()[:len(final_input)]
        temp_list = [int(i) for i in temp_list]
        matrix_of_input.append(temp_list)

    total = pathFinding(matrix_of_input)
    
