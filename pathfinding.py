import time

peta = []

#Isi Matriks
masukan = input()
temp = masukan.split()
for i in range(0,len(temp)):
    temp[i] = int(temp[i])
peta.append(temp)

#Rubah peta ke integer
for i in range(0,len(temp)-1):
    masukan = input()
    temp = masukan.split()
    for j in range(0,len(temp)):
        temp[j] = int(temp[j])
    peta.append(temp)

# #Prosedur pencarian
# def pathFinding(papanCatur):
#     posisi = (0,0)
#     array = []
#     count = 0

#     array.append((0,0))
#     while(len(array) > 0):
#         temp = array.pop(0)
#         if(papanCatur[temp[0]][temp[1]] > 0):
#             for i in range(0,papanCatur[temp[0]][temp[1]]+1):
#                 geserBaris = i
#                 geserKolom = papanCatur[temp[0]][temp[1]] - geserBaris
#                 if((geserBaris + temp[0] < N) and (geserKolom + temp[1] < N)):
#                     array.append((geserBaris + temp[0], geserKolom + temp[1]))
#         else:
#             if(papanCatur[temp[0]][temp[1]] == 0):
#                 if(temp[0] == N-1 and temp[1] == N-1):
#                     count = count + 1
#     return count

#Prosedur pencarian
def pathFinding(papanCatur):
    global N
    stageArray = []
    count = 0
    posisi = [(0,0)]
    stageArray.append(posisi)
    while(len(stageArray) > 0):
        temp = stageArray.pop(0)
        tempArray = []
        for i in range (0,len(temp)):
            titik = temp[i]
            if(papanCatur[titik[0]][titik[1]] > 0): # Jika nilai pada peta lebih dari 0
                if(titik[0] == N-1 and titik[1] == N-1):
                    count = count + 1
                for j in range(0,papanCatur[titik[0]][titik[1]]+1):
                    geserBaris = j
                    geserKolom = papanCatur[titik[0]][titik[1]] - geserBaris
                    if((geserBaris + titik[0] < N) and (geserKolom + titik[1] < N)):
                        tempArray.append((geserBaris + titik[0], geserKolom + titik[1]))
            elif(papanCatur[titik[0]][titik[1]] == 0):
                if(titik[0] == N-1 and titik[1] == N-1):
                    count = count + 1
        if(len(tempArray) > 0):
            stageArray.append(tempArray)
    return count


#Isi Matriks
global N
N = int(len(peta[0]))

start_time = time.time()
print(pathFinding(peta))
print("%s ms" % ((time.time() - start_time)*1000))

