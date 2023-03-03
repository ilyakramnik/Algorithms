def resh(n):    
    a = list(range(n + 1))
    a[1] = 0    
    for i in a:
        if i > 1:
            for j in range(2*i, len(a), i):
                a[j] = 0
    return a

s,f=list(map(int,input().split()))
m=[]
p=[]
odds=[]
c=0
for i in range(s,f+1):
    m+=[i]

print('Start and finish:',s,f)

prime=resh(f)
for i in range(2,f+1):
    itr=[]
    k=1
    if i in prime and i not in p and i in m:
        p+=[i]
        k=2
        
    for j in range(i*k,f+1,i):
        if j in m and j not in odds:
            itr+=[j]
            odds+=[j]
                
    if len(itr)>0:
        c+=1
        print(f'Iteration : {c}')
        print(*itr)

print('Primes :')
if len(p)>0:
    print(*p)
else:
    print("No primes")
    
