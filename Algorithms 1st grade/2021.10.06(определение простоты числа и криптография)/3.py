def GCD(x,y):
    if y==0:
        return x
    else:
        return GCD(y,x%y)

def gcd_boost(a,b):
    if a==0:
        return 0,1
    else:
        x,y=gcd_boost(b%a,a)
    return (y-(b//a)*x),x

p,q,e_start=list(map(int,input().split()))
s=input()
s=[x for x in s]
#print(s)
n=p*q
r=(p-1)*(q-1)
#print(97**5%n)

for e in range(e_start, r):
    if GCD(r,e)==1:
        break

d=gcd_boost(e,r)[0]%r
'''d=1
while 1:
    if (e*d)%r==1:
        break
    d+=1'''

initial_bytes=[]
for i in range(len(s)):
    initial_bytes+=[ord(s[i])]

#print(d,n,e,*s1)

encrypted_bytes=[]
for i in range(len(initial_bytes)):
    encrypted_bytes+=[pow(initial_bytes[i],e,n)]

#print(d,n,e,*initial_bytes,*encrypted_bytes)
'''ecp=[]
for x in encrypted_bytes:
    if x>=256:
        t=x
        k=0
        while t>256:
            t//=256
            k+=1
        ecp+=[k,t]'''

'''ecp=[encrypted_bytes[0]]
for i in range(1,len(encrypted_bytes)):
    ecp+=[(encrypted_bytes[i]+encrypted_bytes[i-1])%n]'''

print('Private:',d,n)
print('Public:',e,n)
print('Initial bytes:',*initial_bytes)
print('Encrypted bytes:',*encrypted_bytes)

'''if len(ecp)>0:
    print('Encrypted bytes:',*ecp)
else:
    print('Encrypted bytes:',*encrypted_bytes)'''
