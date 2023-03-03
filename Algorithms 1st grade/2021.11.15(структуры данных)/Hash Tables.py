def hashlol(q,p,n):
    n_new=[]
    for i in range(len(n)):
        n_new+=[ord(n[i])-ord('a')+1]
    stepen=[]
    for i in range(len(n)):
        stepen+=[p**i]
    key_final=0
    for i in range(len(n)):
        key_final+=n_new[i]*stepen[i]
    return (key_final)%q

def put(key,ch,key_str):
    i=key
    linear_probing=-1
    if mas[i]==[-1,0,0] or mas[i]==[-1,0,1]:
        mas[i]=[key_str,ch,0]
        result=f'inserted value={ch}'
    else:
        i=(key+1)%q
        result='overflow' #изначально сделаем overflow
        while i!=key:
            if mas[i]==[-1,0,0] or mas[i]==[-1,0,1]:
                mas[i]=[key_str,ch,0]
                result='collision'
                linear_probing=i
                value=ch
                break
            i=(i+1)%q

    print(f'hash={key} operation=PUT',end=' ')
    if linear_probing==-1:
        print(f'result={result}')
    else:
        print(f'result={result} linear_probing={linear_probing} value={value}') 
    

def get(key,key_str):
    i=key
    linear_probing=-1
    if mas[i][0]==key_str:
        result=f'found value={mas[i][1]}'
        value=mas[i][1]
    elif mas[i]==[-1,0,0]:
        result='no_key'
    else:
        i=(key+1)%q
        while i!=key:
            if mas[i]==[-1,0,0]:
                result='collision'
                linear_probing=i
                value='no_key'
                break
            elif mas[i][0]==key_str:
                result='collision'
                linear_probing=i
                value=mas[i][1]
                break
            i=(i+1)%q

    print(f'hash={key} operation=GET',end=' ')
    if linear_probing==-1:
        print(f'result={result}')
    else:
        print(f'result={result} linear_probing={linear_probing} value={value}') 
    
        
def _del_(key,key_str):
    i=key
    linear_probing=-1
    if mas[i][0]==key_str:
        mas[key]=[-1,0,1]
        result='removed'
    elif mas[i]==[-1,0,0]:
        result='no_key'
    else:
        i=(key+1)%q
        while i!=key:
            if mas[i]==[-1,0,0]:
                result='collision'
                linear_probing=i
                value='no_key'
                break
            elif mas[i][0]==key_str:
                mas[i]=[-1,0,1]
                result='collision'
                linear_probing=i
                value='removed'
                break
            i=(i+1)%q

    print(f'hash={key} operation=DEL',end=' ')
    if linear_probing==-1:
        print(f'result={result}')
    else:
        print(f'result={result} linear_probing={linear_probing} value={value}') 
    
q,p,n=list(map(int,input().split()))
mas=[[-1,0,0]]*q

for i in range(n):
    s=input().split()
    if s[0]=='PUT':
        print(f'key={s[1]}',end=' ')
        put(hashlol(q,p,s[1]),s[2],s[1])
    elif s[0]=='GET':
        print(f'key={s[1]}',end=' ')
        get(hashlol(q,p,s[1]),s[1])
    elif s[0]=='DEL':
        print(f'key={s[1]}',end=' ')
        _del_(hashlol(q,p,s[1]),s[1])
