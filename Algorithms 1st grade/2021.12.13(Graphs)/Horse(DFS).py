def dfs(v, d):
    global st
    marked[v] = 1
    if d == n**2:
        st += [v]
    for w in N[v]:
        if marked[w] == 0:
            dfs(w, d+1)
            #print(st)
    if len(st) > 0:
        st += [v]
    else:
        marked[v] = 0

n = int(input())
x, y = list(map(int, input().split()))
arr = [[0] * n for i in range(n)]
num = [[0] * n for j in range(n)]
c = 0
for i in range(n):
    for j in range(n):
        num[i][j] = c
        c += 1

N = []
for i in range(n):
    for j in range(n):
        N += [[]]
        if 0 <= i - 2 < n and 0 <= j + 1 < n:
            N[-1] += [num[i-2][j+1]]
        if 0 <= i - 2 < n and 0 <= j - 1 < n:
            N[-1] += [num[i-2][j-1]]
        if 0 <= i + 2 < n and 0 <= j - 1 < n:
            N[-1] += [num[i+2][j-1]]
        if 0 <= i + 2 < n and 0 <= j + 1 < n:
            N[-1] += [num[i+2][j+1]]
        if 0 <= i - 1 < n and 0 <= j - 2 < n:
            N[-1] += [num[i-1][j-2]]
        if 0 <= i - 1 < n and 0 <= j + 2 < n:
            N[-1] += [num[i-1][j+2]]
        if 0 <= i + 1 < n and 0 <= j - 2 < n:
            N[-1] += [num[i+1][j-2]]
        if 0 <= i + 1 < n and 0 <= j + 2 < n:
            N[-1] += [num[i+1][j+2]]
        N[-1].sort()

#print(N)
print('Graph:')
for i in range(len(N)):
    if N[i] != 'None':
        print(i, '-', *N[i])
    else:
        print(i, '-', N[i])

marked = [0] * n**2
edgeTo = [0] * n**2
st = []
visited = []
coords = x * n + y
dfs(coords, 1)
st = st[::-1]
st = st[0:-1]
#print(st)

print('Hamiltonian path:')
if len(st) == n**2:
    k = 0
    for i in range(n):
        for j in range(n):
            arr[i][j] = st.index(k)
            k += 1

    for i in range(len(arr)):
        print(*arr[i], end='\n')
else:
    print('No way')