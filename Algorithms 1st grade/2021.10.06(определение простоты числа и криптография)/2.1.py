s,f = map(int,(input().split()))

arr=[]
for i in range(2,f+1):
    arr+=[i]
k1=0
print("Start and finish:",s,f)
pose=1
sq=[]
while k1<len(arr):
    if arr[k1]==2:
        k2=0
        while (k2<len(arr)):
            if arr[k2]%2==0 and arr[k2]!=2:
                if arr[k2]>=s:
                    sq.append(arr[k2])
                arr.remove(arr[k2])
            else:
                k2+=1
        if len(sq)>0:
            print("Iteration :", pose)
            print(*sq)
        pose += 1
    else:
        z1=0
        sq=[]
        k3=0
        x=(arr[k1])
        while ((x**2)+k3*x) <= arr[len(arr)-1]:
            if (x**2)+k3*x in arr:
                if (x**2)+k3*x>=s:
                    sq.append((x**2)+k3*x)
                arr.remove((x**2)+k3*x)
                k3+=1
            else:
                k3+=1
        if len(sq)>0:
            print("Iteration :", pose)
            print(*sq)
        pose+=1
    if arr[k1]<s:
        arr.remove(arr[k1])
    else:
        k1+=1
if len(arr)>0:
    print("Primes :")
    print(*arr)
else:
    print("Primes :")
    print("No primes")
