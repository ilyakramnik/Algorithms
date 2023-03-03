n,x=list(map(int,input().split()))
m=[int(n) for n in input().split()]
index=[]

print('Initial array:')
print(*m)
print('Target element:', x)

for i in range(len(m)):
    if m[i]==x:
        index+=[i]
        
if len(index)==0:
    print('No targets')
else:
    print('Target is found at:', *index)
