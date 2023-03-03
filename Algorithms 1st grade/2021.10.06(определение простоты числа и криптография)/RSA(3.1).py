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

n=p*q
r=(p-1)*(q-1)


for e in range(e_start, r):
    if GCD(r,e)==1:
        break

d=gcd_boost(e,r)[0]%r

initial_bytes=[]
for i in range(len(s)):
    initial_bytes+=[ord(s[i])]

enc=[]
for i in range(len(initial_bytes)):
    enc+=[bin(initial_bytes[i])[2::]]
    while len(enc[i])<8:
        enc[i]='0'+enc[i]

s_enc=''
for x in enc:
    s_enc+=x

encry1=int(s_enc,2)

encry2=pow(encry1,e,n)

ecp=[]
k=0
if encry2>256:
    while encry2>0:
        ost=encry2%256
        ecp+=[ost]
        encry2//=256
ecp=ecp[::-1]

print('Private:',d,n)
print('Public:',e,n)
print('Initial bytes:',*initial_bytes)
if len(ecp)>0:
    print('Encrypted bytes:',*ecp)
else:
    print('Encrypted bytes:',encry2)
