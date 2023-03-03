s,f=list(map(int,input().split()))
a=[]
primes=[]
c=1
for i in range(0,f+1):
    a+=[i]
a[1]=0

print('Start and finish:',s,f)

for i in range(2,f+1):
    f=0
    itr=[]
    if i==a[i]:
        #print(i)
        if i>=s:
            primes+=[i]
            #c+=1
            #f=1
       
        for j in range(2*i,len(a),i):
            if a[j]!=0 and j>=s:
                itr+=[a[j]]
                a[j]=0
            elif a[j]!=0:
                a[j]=0
        
    if len(itr)>0:
        print(f'Iteration : {c}')
        print(*itr)
        #if f==0:
            #c+=1
    #print(i)
    #input()
    if i==a[i] and a[i]!=0:
        c+=1

print('Primes :')
if len(primes)>0:
    print(*primes)
else:
    print("No primes")



        
