import sys

n = int(input())
coords = []
Graph = {}
cities = []
path_len = n
for i in range(n):
    row = input().split()
    v1, v2 = row[0], row[3:]
    if len(v2) > 0:
        coords += [[int(row[1]), int(row[2])]]
        cities += [v1]
        for w in v2:
            if v1 not in Graph:
                Graph[v1] = {w}
            else:
                Graph[v1].add(w)
    else:
        path_len -= 1

row = input().split()
start = row[0]
end = row[1]

if path_len == 0 or start not in Graph or end not in Graph:
    print('Path:')
    print('No way')
    sys.exit()

path = [10**10] * path_len
path[cities.index(start)] = 0
visited = []
while len(visited) != n:
    min_len = 10**10
    min_index = -1
    for i in range(len(path)):
        if i not in visited:
            if path[i] < min_len:
                min_len = path[i]
                min_index = i

    if cities[min_index] in Graph:
        for w in Graph[cities[min_index]]:
            if cities.index(w) not in visited:
                path[cities.index(w)] = min(path[cities.index(w)],
                                            path[min_index] +
                                             ((coords[cities.index(w)][0] -
                                             coords[min_index][0])**2 +
                                             (coords[cities.index(w)][1] -
                                             coords[min_index][1])**2)**0.5)

        visited += [min_index]

result = [end]
step = 0
while start not in result:
    step += 1
    if step == 10**4:
        break
    if result[-1] in Graph:
        for w in Graph[result[-1]]:
            a = round(((coords[cities.index(w)][0] -
                    coords[cities.index(result[-1])][0])**2 +
                    (coords[cities.index(w)][1] -
                     coords[cities.index(result[-1])][1]) ** 2)**0.5, 2)
            b = round(path[cities.index(result[-1])] -
                    path[cities.index(w)], 2)
            if a == b:
                result += [w]
                break

if step != 10**4:
    result = result[::-1]
    print('Path is not greater than', int(path[cities.index(end)]) + 1)
    print('Path:')
    print(*result)
else:
    print('Path:')
    print('No way')