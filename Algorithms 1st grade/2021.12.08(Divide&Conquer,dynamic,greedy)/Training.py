n=int(input())
k=int(input())
c=0
for x in range(k**(n-1),k**n):
    f=lol=0
    t=x
    while t>0:
        if f==0 and t%k==0:
            f=1
        elif f==1 and t%k==0:
            lol=1
            break
        elif f==1 and t%k!=0:
            f=0
        t//=k
    if lol==0:
        c+=1
print(c)
