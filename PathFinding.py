import time

def pathFinding(matriks,x,y,n):
    if (x == n-1 and y == n-1):
        return 1
    else:
        i = 0
        j = matriks[y][x]
        jumlah = 0
        if (matriks[y][x]!=0):
            for i in range(matriks[y][x]+1):
                if (x+j<n) and (y+i<n):
                    jumlah += pathFinding(matriks,x+j,y+i,n)
                j-=1
            # print("x ="+str(x)+" y = "+str(y)+" jumlah : "+str(jumlah))
        return jumlah

def main():
    matriks = []
    n = input("Masukan N : ")
    n = int(n)
    i = 0
    while (i<n):
        ipt = input()
        iptParse = ipt.split(" ")
        matriks.insert(i,[])
        for el in iptParse:
            matriks[i].append(int(el))
        i+=1
    start = time.time()
    print(pathFinding(matriks,0,0,n))
    end = time.time()
    print(str((end-start)*1000)+" ms")

if __name__ == "__main__":
    main()