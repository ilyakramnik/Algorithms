n = int(input())
mas = [int(n) for n in input().split()]

d = [0]*n
res = [[]*n for i in range(n)]
for i in range(n):
    d[i] = 1
    for j in range(0, i):
        if mas[j] <= mas[i]:
            d[i] = max(d[i], d[j] + 1)

    j_last = i
    res[i] += [mas[i]]
    for j in range(i-1, -1, -1):
        if mas[j] <= mas[j_last] and d[j_last] - d[j] == 1:
            res[i] += [mas[j]]
            j_last = j

    res[i] = res[i][::-1]

#print(d)
#print(res)

d_max = max(d)
sum_min = 10**10
output = []
for i in range(len(res)):
    if len(res[i]) == d_max:
        if sum(res[i]) < sum_min:
            sum_min = sum(res[i])
            output = res[i]

print('Best length =', len(output))
print('Best combo is: ', *output)





