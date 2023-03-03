#include <cstdio>

int rangeWithLen2(int first, int second) {
    int index;
    printf("%c %d %d\n", '?', first, second);
    fflush(stdout);
    scanf("%d", &index);
    if (index == first) {
        return second;
    } else {
        return first;
    }
}

int isRightSegment(int l, int r, int index) {
    int index2;
    printf("%c %d %d\n", '?', l, r);
    fflush(stdout);
    scanf("%d", &index2);
    if (index == index2) {
        return 1;  // нашли максимум
    }
    return 0;
}

int binarySearch(int l, int r, int index) {
    int m, flag;
    if (r == index) {
        flag = 0;  // находимся в левой части массива
    } else {
        flag = 1;
    }
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (flag) {
            if (isRightSegment(index, m, index)) {
                r = m;
            } else {
                l = m;
            }
        } else {
            if (isRightSegment(m, index, index)) {
                l = m;
            } else {
                r = m;
            }
        }
    }
    if (r - l == 1) {
        return rangeWithLen2(l, r);
    }
    if (isRightSegment(l, m, index)) {
        return l;
    }
    return 0;
}

int main() {
    int n, index, index2;
    scanf("%d", &n);
    printf("%c %d %d\n", '?', 1, n);
    fflush(stdout);
    scanf("%d", &index);
    if (n == 2) {
        printf("%c %d\n", '!', rangeWithLen2(1, 2));
    } else {
        if (index == 1) {
            printf("%c %d %d\n", '?', 1, index + 1);
            fflush(stdout);
        } else {
            printf("%c %d %d\n", '?', 1, index);
            fflush(stdout);
        }
        scanf("%d", &index2);
        if (index == index2) {  // максимум лежит левее index
            printf("%c %d\n", '!', binarySearch(1, index, index));
            fflush(stdout);
        } else {
            printf("%c %d\n", '!', binarySearch(index, n, index));
            fflush(stdout);
        }
    }
    fflush(stdout);
}