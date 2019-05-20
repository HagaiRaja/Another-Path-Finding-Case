import time

# file = open('input.txt', 'r')

peta = []
masukan = input()
temp = masukan.split()
for i in range(0,len(temp)):
    temp[i] = int(temp[i])
peta.append(temp)
for i in range(0,len(temp)-1):
    masukan = input()
    temp = masukan.split()
    for j in range(0,len(temp)):
        temp[j] = int(temp[j])
    peta.append(temp)

def pathFinding(papanCatur):
    posisi = (0,0)
    array = []
    count = 0

    array.append((0,0))
    while(len(array) > 0):
        temp = array.pop(0)
        if(papanCatur[temp[0]][temp[1]] > 0):
            for i in range(0,papanCatur[temp[0]][temp[1]]+1):
                geserBaris = i
                geserKolom = papanCatur[temp[0]][temp[1]] - geserBaris
                if((geserBaris + temp[0] < N) and (geserKolom + temp[1] < N)):
                    array.append((geserBaris + temp[0], geserKolom + temp[1]))
        else:
            if(papanCatur[temp[0]][temp[1]] == 0):
                if(temp[0] == N-1 and temp[1] == N-1):
                    count = count + 1
    return count


#Isi Matriks
N = int(len(peta[0]))

# for i in range(0,N):
#     baris = file.readline()
#     temp = baris.split()
#     peta.append(temp)

# file.close()

#Rubah peta ke integer
# for i in range(0,N):
#     for j in range(0,N):
#         peta[i][j] = int(peta[i][j])

start_time = time.time()
print(pathFinding(peta))
print("%s ms" % ((time.time() - start_time)*1000))

