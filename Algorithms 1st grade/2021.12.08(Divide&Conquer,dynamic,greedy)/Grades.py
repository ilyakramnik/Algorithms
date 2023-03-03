n=int(input())
mas=[int(n) for n in input().split()]
index=[]
for i in range(n):
    index+=[i]

for i in range(len(mas)):
    for j in range(len(mas)-1-i):
        if mas[j]>mas[j+1]:
            mas[j],mas[j+1]=mas[j+1],mas[j]
            index[j],index[j+1]=index[j+1],index[j]

print(mas)
print(index)
min_total=10**10
combo_total=[mas[0]]
for i in range(len(mas)-1):
    combo=[mas[i]]
    min_sum=mas[i]
    j_last=i
    for j in range(i+1,len(mas)):
        if index[j]>index[j_last]:
            combo+=[mas[j]]
            min_sum+=mas[i]
            j_last=j
    print(combo)

    if min_sum<min_total and len(combo)>=len(combo_total) and len(set(combo))>1:
        min_total=min_sum
        combo_total=combo

print('Best length =',len(combo_total))
print('Best combo is: ',*combo_total)


        
