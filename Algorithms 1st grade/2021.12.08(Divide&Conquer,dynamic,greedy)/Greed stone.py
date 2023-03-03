n=int(input())
mas=[]
for i in range(n):
    row = input().split()
    for j in range(len(row)):
        row[j] = int(row[j])
    mas.append(row)

path_final=[]
cost_final=[]
for i in range(n):
    cost=0
    path=[i]
    r=i
    town=-1
    while True:
        if len(path)==n:
            if mas[r][i]!=0:
                cost+=mas[r][i]
                path+=[i]
            else:
                path=['lost']
            break
        else:
            j=r+1
            min_coin=10**10
            while j%n!=r:
                if 0<mas[r][j%n]<min_coin and j%n not in path:
                    min_coin=mas[r][j%n]
                    town=j%n
                elif j%n<town and 0<mas[r][j%n]<=min_coin and j%n not in path:
                    min_coin=mas[r][j%n]
                    town=j%n
                j+=1
        if min_coin==10**10:
            path=['lost']
            break
        path+=[town]
        cost+=min_coin
        r=town
    path_final+=[path]
    cost_final+=[cost]

print(path_final)
print(cost_final)

cost_res=10**10
path_res=[]
check=0
for i in range(len(path_final)):
    if path_final[i]!=['lost']:
        check=1
        break
if check==0:
    print('Lost')
else:
    for i in range(len(cost_final)):
        if cost_final[i]<cost_res and path_final[i]!=['lost']:
            cost_res=cost_final[i]
            path_res=path_final[i]

    print('Path:')
    print(*path_res)
    print('Cost:',cost_res)
