s,f=list(map(int,input().split()))
a=[]
c=0
kick=set()
for i in range(s,f+1):
    a+=[i]

print('Start and finish:',s,f)

for i in range(2,3):
    itr=[]
    for j in range(2*i,f+1,i):
        if j in a and j not in kick:
            kick.add(j)
            itr+=[j]
            
    if len(itr)>0:
        c+=1
        print(f'Iteration : {c}')
        print(*itr)
    
for i in range(3,f+1):
    itr=[]
    k3=0
    #for j in range(i*i,f+1,i*k3):
    j=0
    while j<=f:
        j=i*i+i*k3
        if j in a and j not in kick:
            kick.add(j)
            itr+=[j]
        k3+=1
        
    if len(itr)>0:
        c+=1
        print(f'Iteration : {c}')
        print(*itr)
    
#final=sorted(set(a)-set(kick))
final=[]
for x in a:
    if x not in kick:
        final+=[x]        

print('Primes :')
if len(final)>0:
    print(*final)
else:
    print("No primes")
        
    
    
