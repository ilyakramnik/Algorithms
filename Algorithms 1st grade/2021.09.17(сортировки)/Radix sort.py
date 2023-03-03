n=int(input())
m=[]
digit=[[]]*16
for i in range(n):
    x=int(input())
    m+=[x]

for i in range(7,-1,-1):
    for i in range(n):
        if m[i]<16**i:
            digit[0]+=m[i]
        else:
            digit[m[i]%10]+
