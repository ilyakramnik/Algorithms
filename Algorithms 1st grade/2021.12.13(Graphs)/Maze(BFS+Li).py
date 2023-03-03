n, m = list(map(int, input().split()))
arr = []
c = 0
num = [[0] * m for i in range(n)]
for i in range(n):
    row = input()
    row = ' '.join(row).split()
    arr += [row]
    for j in range(m):
        if arr[i][j] != '#':
            num[i][j] = c
        else:
            num[i][j] = -1
        if arr[i][j] == 'S':
            s_num = c
        elif arr[i][j] == 'F':
            f_num = c
        c += 1

print('Initial labyrinth:')
for i in range(len(arr)):
    print(*arr[i], sep='', end='\n')

N = []
for i in range(n):
    for j in range(m):
        l50 = 0
        if arr[i][j] == '#':
            N += ['None']
        else:
            if 0 < i < n - 1:
                if 0 < j < m - 1:
                    N += [[x for x in [num[i-1][j], num[i][j-1], num[i][j+1],
                          num[i+1][j]] if x != -1]]
                else:
                    if j == 0:
                        N += [[x for x in [num[i-1][j]] if x != -1]]
                        if m > 1:
                            N[-1] += [x for x in [num[i][j+1]] if x != -1]
                        N[-1] += [x for x in [num[i+1][j]] if x != -1]
                    elif j == m - 1:
                        N += [[x for x in [num[i-1][j]] if x != -1]]
                        if m > 1:
                            N[-1] += [x for x in [num[i][j-1]] if x != -1]
                        N[-1] += [x for x in [num[i + 1][j]] if x != -1]
            else:
                if i == 0:
                    if j == 0:
                        if m > 1:
                            N += [[x for x in [num[i][j+1]] if x != -1]]
                            l50 = 1
                        if n > 1:
                            if l50:
                                N[-1] += [x for x in [num[i+1][j]] if x != -1]
                            else:
                                N += [[x for x in [num[i + 1][j]] if x != -1]]
                    elif 0 < j < m - 1:
                        N += [[x for x in [num[i][j-1], num[i][j+1]] if x != -1]]
                        if n > 1:
                            N[-1] += [x for x in [num[i+1][j]] if x != -1]
                    elif j == m - 1:
                        N += [[x for x in [num[i][j-1]] if x != -1]]
                        if n > 1:
                            N[-1] += [x for x in [num[i+1][j]] if x != -1]
                elif i == n - 1:
                    if j == 0:
                        N += [[x for x in [num[i-1][j]] if x != -1]]
                        if m > 1:
                            N[-1] += [x for x in [num[i][j+1]] if x != -1]
                    elif 0 < j < m - 1:
                        N += [[x for x in [num[i-1][j], num[i][j-1], num[i][j+1]] if x != -1]]
                    elif j == m - 1:
                        N += [[x for x in [num[i-1][j]] if x != -1]]
                        if m > 1:
                            N[-1] += [x for x in [num[i][j-1]] if x != -1]
        if N[-1] == []:
            N[-1] = 'None'

f_none = 0
for i in range(len(N)):
    for j in range(len(N[i])):
        if N[i] != 'None':
            f_none = 1
            break
    if f_none == 1:
        break
if f_none == 0:
    N[s_num] = 'None'
    N[f_num] = 'None'

print('Graph:')
for i in range(len(N)):
    if N[i] != 'None':
        print(i, '-', *N[i])
    else:
        print(i, '-', N[i])

xs = ys = xf = yf = -1
for i in range(n):
    for j in range(m):
        if arr[i][j] == 'S':
            xs, ys = i, j
            arr[i][j] = 0
        else:
            if arr[i][j] == 'F':
                xf, yf = i, j
            arr[i][j] = -1

step = 0
st = [[s_num, 0]]
rep = [s_num]
while True:
    step += 1
    if step == 10**4 or len(st) == 0:
        break
    if N[st[0][0]] != 'None':
        for i in N[st[0][0]]:
            if i not in rep:
                st += [[i, st[0][1]+1]]
                rep += [i]
                f = 0
                for a in range(n):
                    for b in range(m):
                        if num[a][b] == i:
                            f = 1
                            if arr[a][b] == -1:
                                arr[a][b] = st[-1][1]
                            break
                    if f == 1:
                        break

    st.pop(0)
    if len(st) > 0 and st[0][0] == f_num:
        break

print('BFS result is:')
for i in range(len(arr)):
    print(*arr[i], end='\n')