n,m=list(map(int, input().split()))
mas=[]
x = y = -1
for i in range(n):
    row = input().split()
    for j in range(len(row)):
        if row[j]!='S':
            row[j] = int(row[j])
        else:
            x, y = i, j
    mas.append(row)

for j in range(y+2,m):
    mas[x][j]+=mas[x][j-1]

for i in range(x+2,n):
    mas[i][y]+=mas[i-1][y]

for i in range(x+1,n):
    for j in range(y+1,m):
        mas[i][j]+=max(mas[i-1][j],mas[i][j-1])

xn = n-1
ym = m-1
coins = mas[xn][ym]

print('Path:')
path=[f'({xn},{ym})']

while xn!=x or ym!=y:
    if xn!=x and ym!=y:
        if mas[xn-1][ym]>=mas[xn][ym-1]:
            path+=[f'({xn-1},{ym})']
            xn-=1
        else:
            path+=[f'({xn},{ym-1})']
            ym-=1
    elif xn==x:
        path+=[f'({xn},{ym-1})']
        ym-=1
    elif ym==y:
        path+=[f'({xn-1},{ym})']
        xn-=1

for i in range(len(path)-1,-1,-1):
    print(path[i], end=' ')
print('\nCoins:', coins)
