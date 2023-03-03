n=int(input())
a=[int(n) for n in input().split()]

print('Initial array:')
print(*a)
print()

start=0
end=len(a)-1
f=0
rep_l=rep_r=0
def qsort(a,start,end):
    global rep_l
    global rep_r
    while rep_r<2:
        global f
        left=[]
        right=[]
        index=(start+end)//2
        pivot=a[index]
        print('Pivot index:',index,',','pivot element:', pivot)
        for i in range(0,index):
            if a[i]<=pivot:
                left+=[a[i]]
            else:
                right+=[a[i]]
        for i in range(index+1,len(a)):
            if a[i]<=pivot:
                left+=[a[i]]
            else:
                right+=[a[i]]

        a=left+[pivot]+right
        print('Array after partition:',*a)
        print()
        
        if start<end and rep_l<1:
            if start==0 and f==0:
                end=len(left)-1
                f=1
                print(start,end)
                input()
            elif f:
                start=index
                if end-start==1:
                    rep_l+=1
                print(start,end)
                input()
            elif end==len(a)-1:
                start=index
                if end-start==1:
                   rep_r+=1
                print(start,end)
                input()    
        else:
            start=len(left)+2
            end=len(a)-1
            f=0
            rep_l=0
            if end-start==1:
                rep_r+=1
                
        print(rep_l)
        qsort(a,start,end)
        #qsort(left,start,end)
        #qsort(right,start,end)  
    #return a

qsort(a,start,end)
