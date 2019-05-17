# ======= Introduction ======= #
''' Path Finding using Dynamic Programming
    Input : Matrix NxN
    Output : Sum of possible path and execution time

    Pandyaka Aptanagi / 13517003 '''

# ======= Import some library ========= #
import time

# ======= Input from file, and make it Matrix ======== #
def makeMatrix(filename) :

    matrix = []
    with open("{}".format(filename)) as f :
        for line in f :
            matrix.append([int(c) for c in line.split()])

    # return matrix from file in array of array form
    return matrix

# ===== Utility that used in pathFinding using DP Algorithm ===== #
def pathUtil(i,j,mat,DPmat,boundary) :

    # Base : if i or j is more than size of the matrix (out of the chessboard)
    if (i >= boundary or j >= boundary) :
        return 0

    # Base : if i and j is the point where the goals is located
    if (i == boundary-1 and j == boundary-1) :
        return 1
        
    # Using the table of memoization, if already calculated then return its value
    if (DPmat[i][j] != -1 ) :
        return DPmat[i][j]

    # Initialize for the DP[i][j]
    DPmat[i][j] = 0

    # The recursion of DP
    for val in range(mat[i][j]+1) :
        DPmat[i][j] = DPmat[i][j] + pathUtil(i+val,j+(mat[i][j]-val),mat,DPmat,boundary)
    
    # Return the value from matriks DPmat[i][j]
    return DPmat[i][j]
    
# ======= mainFunc ===== #
def pathFinding(papanCatur) :
    
    # The boundary for the recursive, using length of the papanCatur
    boundary = len(papanCatur)
    
    # DP matrix initialization
    DPmat = [ [-1 for x in range(boundary)] for y in range(boundary)]

    # Using pathUtil that declared before
    return pathUtil(0,0,papanCatur,DPmat,boundary)

# ======= Main Program ======= #
if __name__ == "__main__":

    mat = makeMatrix("input.txt")
    startTime = time.time()
    temp = pathFinding(mat)
    print(temp)
    endTime = time.time()
    print(float(endTime - startTime))