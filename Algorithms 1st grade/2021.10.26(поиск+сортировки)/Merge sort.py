def merge_sort(a):
    left=a[:len(a)//2]
    right=a[len(a)//2:]
    if len(a)==1:
        return a
    elif len(a)>1:
        merge_sort(left)
        merge_sort(right)
        print('Left part:',*left)
        print('Right part:',*right)
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
        print('Merged parts:',*a)
        print()
        return a

n=int(input())
a=[int(n) for n in input().split()]
print('Initial array:')
print(*a)
print()
merge_sort(a)
