def qsort(a, start, end):
    if abs(end - start) >= 2:
        p = partition(a, start, end)
        qsort(a, start, p)
        qsort(a, p + 1, end)


def partition(a, start, end):
    index = start + (end - start - 1) // 2
    left = []
    right = []
    pivot = a[index]
    print('Pivot index:', index, ',', 'pivot element:', pivot)

    for i in range(start, index):
        if a[i] <= pivot:
            left += [a[i]]
        else:
            right += [a[i]]
    for i in range(index + 1, end):
        if a[i] <= pivot:
            left += [a[i]]
        else:
            right += [a[i]]

    index_new = start + len(left)
    a[start:end] = left + [pivot] + right

    print('Array after partition:', *a)
    print()
    return index_new


n = int(input())
a = [int(n) for n in input().split()]

print('Initial array:')
print(*a)
print()

qsort(a, 0, len(a))
