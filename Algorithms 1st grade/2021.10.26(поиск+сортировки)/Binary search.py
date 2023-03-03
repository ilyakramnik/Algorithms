def merge_sort(a):
    left=a[:len(a)//2]
    right=a[len(a)//2:]
    if len(a)==1:
        return a
    elif len(a)>1:
        merge_sort(left)
        merge_sort(right)
        c=[]
        n1=n2=0
        while n1<len(left) and n2<len(right):
            c+=[min(left[n1],right[n2])]
            if left[n1]<=right[n2]:
                n1+=1
            else:
                n2+=1
                
            if n1==len(left):
                for i in range(n2,len(right)):
                    c+=[right[i]]
            elif n2==len(right):
                for i in range(n1,len(left)):
                    c+=[left[i]]

        for i in range(len(c)):
            a[i]=c[i]
        return a


def binary_search(a,x):
    global index
    global el
    global sr
    global f
    f=0
    index=[]
    el=[]
    start=0
    end=len(a)-1
    while start<=end:
        sr=(end+start)//2
        if a[sr]==x:
            index+=[sr]
            el+=[a[sr]]
            f=1
            return sr
        elif a[sr]>x:
            index+=[sr]
            el+=[a[sr]]
            end=sr-1
        elif a[sr]<x:
            index+=[sr]
            el+=[a[sr]]
            start=sr+1
    #return 'No targets'


n,x=list(map(int,input().split()))
a=[int(n) for n in input().split()]
merge_sort(a)
s_h=''

print('Initial array:')
print(*a)
print('Target element:', x)
binary_search(a, x)
for i in range(len(index)):
    s_h+=str(el[i])
    s_h+='('
    s_h+=str(index[i])
    s_h+=') '
print('Search history:', s_h)
if f:
    print('Target is found at:', sr)
else:
    print('No targets')
