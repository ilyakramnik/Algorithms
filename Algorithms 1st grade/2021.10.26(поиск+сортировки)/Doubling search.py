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
    global f1
    global index1
    global el1
    f1=0
    index1=[]
    el1=[]
    start=0
    end=len(a)-1
    while start<=end:
        sr=(end+start)//2
        if a[sr]==x:
            index1+=[left+sr]
            el1+=[a[sr]]
            f1=1
            return sr
        elif a[sr]>x:
            index1+=[left+sr]
            el1+=[a[sr]]
            end=sr-1
        elif a[sr]<x:
            index1+=[left+sr]
            el1+=[a[sr]]
            start=sr+1
    return 'No targets'

def doubling_search(a,x):
    global index
    global el
    global f
    global ans
    global use_of_bs
    global left
    use_of_bs=0
    f=0
    index=[]
    el=[]

    index+=[0]
    el+=[a[0]]
    if a[0]>x:
        return 'No targets'
    elif a[0]==x:
        ans=0
        f=1
        return ans

    k=0
    while True:
        if 2**k>len(a)-1:
            if k==0:
                left=0
            else:
                left=2**(k-1)+1
            right=len(a)-1
            break
        elif a[2**k]>x:
            if k==0:
                left=0
            else:
                left=2**(k-1)+1
            index+=[2**k]
            el+=[a[2**k]]
            right=2**k-1
            break
        elif a[2**k]==x:
            index+=[2**k]
            el+=[a[2**k]]
            f=1
            ans=2**k
            return 2**k
        index+=[2**k]
        el+=[a[2**k]]
        k+=1
        
    if binary_search(a[left:right+1],x)!='No targets':
        f=1
    else:
        use_of_bs=1

    if f:
        ans= left + binary_search(a[left:right+1],x)
        use_of_bs=1
        return ans
    else:
        return 'No targets'


n,x=list(map(int,input().split()))
a=[int(n) for n in input().split()]
merge_sort(a)
s_h=''
b_h=''

print('Initial array:')
print(*a)
print('Target element:', x)
doubling_search(a,x)

for i in range(len(index)):
    b_h+=str(el[i])
    b_h+='('
    b_h+=str(index[i])
    b_h+=') '
print('Bounds history:', b_h)

if use_of_bs:
    if len(index1)>0:
        for i in range(len(index1)):
            s_h+=str(el1[i])
            s_h+='('
            s_h+=str(index1[i])
            s_h+=') '
        print('Search history:', s_h)
        
if f:
    print('Target is found at:', ans)
else:
    print('No targets')
