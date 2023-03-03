def float_format(arr):
    narr=arr[:]
    for i in range(len(narr)):
        narr[i]="{:4.2f}".format(narr[i])
    print(*narr)

def Insertion_sort(m):
    for i in range(1,len(m)):
        for j in range(i,0,-1):
            if m[j]<m[j-1]:
                m[j],m[j-1]=m[j-1],m[j]
            else:
                break
    return m

n=int(input())
m=[float(n) for n in input().split()]

print('Initial array:')
m_copy=m.copy()
for i in range(len(m_copy)):
    m_copy[i]=format(m_copy[i], '.2f')
print(*m_copy,'\n')

bucks=2*len(m) #кол-во вёдер
buck_len=(max(x for x in m)-min(x for x in m))/bucks #длина каждого ведра

borders=[]
for i in range(1,bucks+1):
    borders+=[min(x for x in m)+buck_len*i] #заполняем массив с границами

baskets=[[]*bucks for i in range(bucks)] #сами вёдра
for i in range(len(m)):
    for j in range(len(borders)):
        if m[i]<borders[j]:
            baskets[j]+=[m[i]] #заполняем вёдра
            break
        if m[i]==max(x for x in m):
            baskets[-1]+=[m[i]] #если наше число самое большое(отдельный случай)
            break

for i in range(len(baskets)):
    if len(baskets[i])>0:
            print('Bucket:')
            float_format(baskets[i])
            baskets[i]=Insertion_sort(baskets[i]) #сортируем ведро
            print('Sorted bucket:')
            float_format(baskets[i])
            print()

print('Final array:')
for i in range(len(baskets)):
    for j in range(len(baskets[i])):
        baskets[i][j]=format(baskets[i][j], '.2f')
    if len(baskets[i])>0:
        print(*baskets[i], end=' ') #выводим отсортированный массив



