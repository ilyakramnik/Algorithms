n=int(input())

def qsort(a,n):
    a+=[n]
    for i in range(len(a)-1,(len(a)-1)//2-1,-1):
        a[i]=a[i-1]
    a[(len(a)-1)//2]=n
    return a


a=[1]
for i in range(2,n+1):
    qsort(a,i)

print(*a)
