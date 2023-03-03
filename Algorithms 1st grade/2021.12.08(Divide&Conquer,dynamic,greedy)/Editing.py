def d(n,m):
    mas=[[0]*(m+1) for i in range(n+1)]
    for i in range(n+1):
        mas[i][0]=i
    for j in range(m+1):
        mas[0][j]=j
    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i-1]==s2[j-1]:
                mas[i][j]=mas[i-1][j-1]
            else:
                mas[i][j]=min(mas[i-1][j],mas[i][j-1],mas[i-1][j-1])+1
    return mas[n][m]            

s1=input()
n=int(input())
length=[]
ans=[]
for i in range(n):
    s2=input()
    ans+=[s2]
    length+=[d(len(s1),len(s2))]
k=0    
min_op=min(length)
#print(length)
#print(ans)
for i in range(n):
    if length[i]==min_op:
        k+=1

print('Most similar words =',k)
print('Minimal operations needed =',min_op)
for i in range(n):
    if length[i]==min_op:
        print(ans[i])    
