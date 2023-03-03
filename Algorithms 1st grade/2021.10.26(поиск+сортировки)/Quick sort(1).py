n=int(input())
m=[int(n) for n in input().split()]

def quick_sort(m):
    if len(m)<2:
        return m
    else:
        l=0
        r=len(m)-1
        index=(len(m)-1)//2
        if index==0:
            index=1
        pivot=m[index]
        while l<r:
            if m[l]>=pivot and m[r]<=pivot:
                m[l],m[r]=m[r],m[l]
                l+=1
                r-=1
                #print(1)
            elif m[l]>=pivot and m[r]>pivot:
                if m[l]>m[r]:
                    m[l],m[r]=m[r],m[l]
                r-=1
                #print(2)
            elif m[l]<=pivot and m[r]<pivot:
                if m[l]>m[r]:
                    m[l],m[r]=m[r],m[l]
                l+=1
                #print(3)
            elif m[l]<=pivot and m[r]>=pivot:
                l+=1
                r-=1
                #print('---')
            #print(m,l,r)
            #input()
        if len(m)==2:
            less=m[:index]
            more=m[index:]
        else:
            less=m[:index+1]
            more=m[index+1:]
        print(less)
        print(more)
        
    return quick_sort(less) + quick_sort(more)

print(quick_sort(m))
