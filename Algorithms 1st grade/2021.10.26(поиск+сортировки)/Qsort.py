def qsort(a,start,end):
   if abs(end-start)>=2:
        p=partition(a,start,end)
        qsort(a,start,p)
        qsort(a,p+1,end)
        
def partition(a,start,end):
    index=start+(end-start-1)//2
    left=[]
    right=[]
    pivots=[]
    #a_new=[]
    pivot=a[index]
    print('Pivot index:',index,',','pivot element:', pivot)
    for i in range(start,index):
        if a[i]<pivot:
            left+=[a[i]]
        elif a[i]==pivot:
            pivots+=[a[i]]
        elif a[i]>pivot:
            right+=[a[i]]
    for i in range(index,end):
        if a[i]<pivot:
            left+=[a[i]]
        elif a[i]==pivot:
            pivots+=[a[i]]
        elif a[i]>pivot:
            right+=[a[i]]

    #print(left)
    #print(pivots)
    #print(right)
    a_new=left+[pivot]+right
    #index_new=len(left)
    #print(start,end)
    c=start
    #a1=[]
    while start<end:
        a[start]=a_new[start-c]
        if a[start]==pivot:
            index_new=start
        #a1+=[a[start]]
        start+=1
        
    #print(a1)
    #index_new=len(a1)-1-a1[::-1].index(pivot)
    #print(index_new)
        
    print('Array after partition:',*a)
    print()
    #input()
    #print(index_new)
    #input()
    return index_new

n=int(input())
a=[int(n) for n in input().split()]

print('Initial array:')
print(*a)
print()

qsort(a,0,len(a))
