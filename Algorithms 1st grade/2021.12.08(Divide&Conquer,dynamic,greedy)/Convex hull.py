def deg(a,b,c):
  return (c[0]-a[0])*(b[1]-a[1])-(c[1]-a[1])*(b[0]-a[0])

def vector(a,b):
    return (b[0]-a[0])**2 + (b[1]-a[1])**2

def insertion_sort(p):
    for i in range(2,len(mas)):
        j=i
        while j>1 and((deg(mas[p[0]],mas[p[j]],mas[p[j-1]])<0) or\
              (deg(mas[p[0]],mas[p[j]],mas[p[j-1]])==0) and\
        (vector(mas[p[0]],mas[j])<vector(mas[p[0]],mas[j-1]))): 
          p[j],p[j-1]=p[j-1],p[j]
          j-=1
    return p

f=open('input.txt')
mas=[]
for line in f:
    x,y=line.split()
    mas+=[[int(x),int(y)]]

minx=10**10
p=[]
for i in range(len(mas)):
    p+=[i]
index=-1
for i in range(len(mas)):
    if mas[i][0]<minx:
        minx=mas[i][0]
        index=i

p[0],p[index]=p[index],p[0]

insertion_sort(p)
hull=[p[0],p[1]]
for i in range(2,len(mas)):
    while len(hull)>1 and deg(mas[hull[-1]],mas[hull[-2]],mas[p[i]])<=0:
        hull.pop()
    hull+=[p[i]]
    
convex_hull=[]
for i in hull:
    convex_hull+=[mas[i]]

convex_hull.sort()
print('Convex Hull is:')
for x in convex_hull:
    print(*x)
