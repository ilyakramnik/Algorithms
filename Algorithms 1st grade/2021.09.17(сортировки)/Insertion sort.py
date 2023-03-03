n=int(input())
m=[int(n) for n in input().split()]
k=1

print('Initial array:')
print(*m)
for i in range(1,n):
    for j in range(i,0,-1):
        if m[j]<m[j-1]:
            m[j],m[j-1]=m[j-1],m[j]
        else:
            print(f'Insertion - Element #{k}')
            print(*m)
            k+=1
            break
        if j==1:
            print(f'Insertion - Element #{k}')
            print(*m)
            k+=1
            

