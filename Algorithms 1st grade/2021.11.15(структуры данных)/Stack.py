operations=[]
brackets_open=[]
brackets_close=[]
output=[]
end=0
a_final=''
x=input()
print('Expression:')
print(x)
for a in x:
    if a=='+' or a=='-':
        if a_final!='':
            output+=[a_final] #добавляем наше n-значное число
            a_final='' #обнуляем a_final
        operations+=[a]
        if len(operations)>1:
            while operations[-2]=='+' or operations[-2]=='-' or operations[-2]=='*' or operations[-2]=='/':
                output+=[operations[-2]]
                operations.pop(-2)
                if len(operations)<=1:
                    break
                
    elif a=='*' or a=='/':
        if a_final!='':
            output+=[a_final]
            a_final=''
        operations+=[a]
        if len(operations)>1:
            if operations[-2]=='*' or operations[-2]=='/':
                output+=[operations[-2]]
                operations.pop(-2)

    elif a=='(':
        brackets_open+=[len(operations)]
        operations+=[a]
        if len(operations)>0 and a_final!='': #если до этого стек был непустой
            output+=[a_final]
            a_final=''
         
    elif a==')':
        if a_final!='':
            output+=[a_final]
            a_final=''
        end=len(operations)
        for i in range(end-1,brackets_open[-1]+1-1,-1):
            p=operations[i]
            output+=[p]
        for j in range(brackets_open[-1],end):
            operations.pop()
            
        brackets_open.pop(-1)
        
    else:          #когда ввели число
        a_final+=a #формируем наше число

    '''print(a, a_final)
    print(operations)
    print(output)
    #input()'''

if a_final!='':
    output+=[a_final]

for i in range(len(operations)-1,-1,-1):
    output+=[operations[i]]

print('Reverse Polish Notation:')        
print(*output)
print('Result:')
print(int(eval(x)))
