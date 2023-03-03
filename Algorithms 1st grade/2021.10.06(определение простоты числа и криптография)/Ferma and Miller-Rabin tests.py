def Ferma(p):
    k_true=1
    k_false=0
    f=True
    for a in range(2,p):
        if pow(a,p-1,p)==1:
            k_true+=1
            continue
        else:
            f=False
            k_false+=1
    return f,k_false,k_true

def Miller_Rabin(n):
    k_true1=1
    k_true2=0
    k_false=-1
    s=0
    d=0
    while d%2==0:
        d=(n-1)//pow(2,s)
        s+=1
        
    for a in range(2,n+1):
        f=False
        if pow(a,d,n)==1:
            k_true1+=1
            f=True
            continue
        for r in range(0,s):
            if pow(a,pow(2,r)*d,n)==n-1:
                k_true2+=1
                f=True
                continue
        if f==False:
            k_false+=1

    if k_true1+k_true2==n-1:
        f=True
    else:
        f=False
    return f,k_false,k_true1,k_true2

n=int(input())
print('Miller-Rabin test:',*Miller_Rabin(n))
print('Fermat test:',*Ferma(n))
