// АИСД-2, 2023, задание 5
// Крамник Илья Михайлович, БПИ-213
// Clion
// Выполнены все 13 сортировок на 4 типах массивов с помощью указателей на функции. Все необходимые
// данные записаны в csv файлы
// Несделанная часть отсутствует

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

uint64_t selectionSort(std::vector<int> &arr, int size) {  // сортировка выбором
    uint64_t op = 0;
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        op += 2;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
                op += 3;
            }
        }
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
            op += 10;
        }
    }
    return op;
}

uint64_t bubbleSort(std::vector<int> &arr, int size) {  // сортировка пузырьком
    uint64_t op = 0;
    int temp;
    for (int i = size - 1; i >= 1; --i) {
        ++op;
        for (int j = 0; j < i; ++j) {
            ++op;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                op += 10;
            }
        }
    }
    return op;
}

uint64_t bubbleSortAiverson1(std::vector<int> &arr,
                             int size) {  // сортировка пузырьком с условием Айверсона 1
    uint64_t op = 0;
    int temp;
    int i = 0;
    bool t = true;
    while (t) {
        t = false;
        ++op;
        for (int j = 0; j < size - i - 1; ++j) {
            ++op;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                t = true;
                op += 11;
            }
        }
        ++i;
        ++op;
    }
    return op;
}

uint64_t bubbleSortAiverson2(std::vector<int> &arr,
                             int size) {  // сортировка пузырьком с условием Айверсона 1+2
    uint64_t op = 0;
    int temp;
    int i = 0;
    int pos = size - i - 1;
    int pos_new;
    while (pos != 0) {
        pos_new = -1;
        ++op;
        for (int j = 0; j < pos; ++j) {
            ++op;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                pos_new = j;
                op += 11;
            }
        }
        if (pos_new == -1) {
            pos = 0;
        } else {
            pos = pos_new;
        }
        ++i;
        ++op;
    }
    return op;
}

uint64_t insertionSort(std::vector<int> &arr, int size) {  // сортировка вставками
    uint64_t op = 0;
    int tmp;
    for (int i = 1; i < size; ++i) {
        ++op;
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
            op += 14;
        }
    }
    return op;
}

uint64_t insertionBinarySort(std::vector<int> &arr, int size) {  // сортировка бинарными вставками
    uint64_t op = 0;
    int hi, key, lo, mid;
    for (int i = 1; i < size; ++i) {
        key = arr[i];
        lo = 0, hi = i - 1;
        op += 3;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            op += 6;
            if (key < arr[mid]) {
                hi = mid;
                ++op;
            } else {
                lo = mid + 1;
                op += 2;
            }
        }
        for (int j = i; j > lo + 1; --j) {
            arr[j] = arr[j - 1];
            op += 7;
        }
        arr[lo] = key;
        op += 2;
    }
    return op;
}

uint64_t countingSort(std::vector<int> &res, int size) {  // сортировка подсчетом (устойчивая)
    uint64_t op = 0;
    int maxi, mini, delta = 0, right_border;
    std::vector<int> arr;
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            maxi = res[i];
            mini = res[i];
            op += 3;
        }
        maxi = std::max(maxi, res[i]);
        mini = std::min(mini, res[i]);
        arr.push_back(res[i]);
        op += 7;
    }

    right_border = maxi + 1;
    if (mini < 0) {
        delta = mini * -1;
    }
    op += 5;
    int *counts = new int[right_border + delta];
    for (int i = 0; i < right_border + delta; ++i) {
        counts[i] = 0;
        op += 3;
    }
    for (int i = 0; i < size; ++i) {
        ++counts[arr[i] + delta];
        op += 5;
    }
    for (int i = mini + delta + 1; i < right_border + delta; ++i) {
        counts[i] += counts[i - 1];
        op += 6;
    }
    for (int i = size - 1; i >= 0; --i) {
        --counts[arr[i] + delta];
        res[counts[arr[i] + delta]] = arr[i];
        op += 11;
    }
    delete[] counts;
    return op;
}

int numOfDigits(
    int num) {  // вспомогателная функция 1 к цифровой сортировке. Определяет число разрядов в числе
    int k = 0;
    while (num > 0) {
        ++k;
        num /= 10;
    }
    return k;
}

int digit(
    int num,
    int pos) {  // вспомогателная функция 2 к цифровой сортировке. Возвращает нужный разряд числа
    return (num / static_cast<int>(std::pow(10, pos - 1))) % 10;
}

uint64_t radixSort(std::vector<int> &res, int n) {  // цифровая сортировка (LSD, основание 10)
    uint64_t op = 0;
    int max_digit = 1, d, count, tmp;
    int *arr = new int[n];
    int *counts = new int[10];
    for (int i = 0; i < n; ++i) {
        arr[i] = res[i];
        max_digit = std::max(max_digit, numOfDigits(res[i]));
        op += 7;
    }
    for (int i = 1; i <= max_digit; ++i) {
        ++op;
        for (int j = 0; j < 10; ++j) {
            counts[j] = 0;
            op += 3;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j], i);
            ++counts[d];
        }
        count = 0;
        for (int j = 0; j < 10; ++j) {
            tmp = counts[j];
            counts[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j], i);
            res[counts[d]] = arr[j];
            ++counts[d];
            op += 11;
        }
        for (int j = 0; j < n; ++j) {
            arr[j] = res[j];
            op += 4;
        }
    }
    delete[] arr;
    delete[] counts;
    return op;
}

uint64_t merge(std::vector<int> &arr, int left, int mid, int right,
               uint64_t &op) {  // выполняют слияение двух массивов
    int it1 = 0;
    int it2 = 0;
    int *result = new int[right - left];

    while (left + it1 < mid && mid + it2 < right) {
        op += 9;
        if (arr[left + it1] < arr[mid + it2]) {
            result[it1 + it2] = arr[left + it1];
            ++it1;
            op += 6;
        } else {
            result[it1 + it2] = arr[mid + it2];
            ++it2;
            op += 6;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = arr[left + it1];
        ++it1;
        op += 8;
    }
    while (mid + it2 < right) {
        result[it1 + it2] = arr[mid + it2];
        ++it2;
        op += 8;
    }
    for (int i = 0; i < it1 + it2; ++i) {
        arr[left + i] = result[i];
        op += 6;
    }
    delete[] result;
    return op;
}

void mergeSortMain(std::vector<int> &arr, int left, int right,
                   uint64_t &op) {  // рекурсивная реализация сортировки слиянием
    if (left + 1 >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    op += 4;
    mergeSortMain(arr, left, mid, op);
    mergeSortMain(arr, mid, right, op);
    merge(arr, left, mid, right, op);
}

uint64_t mergeSort(std::vector<int> &array, int size) {  // сортировка слиянием
    uint64_t op = 0;
    mergeSortMain(array, 0, size, op);
    return op;
}

int partition(std::vector<int> &arr, int start, int end,
              uint64_t &op) {  // разделение массива на два подмассива
    int pivot = arr[start];
    int p_index = end;

    for (int i = end; i > start; --i) {
        op += 3;
        if (arr[i] >= pivot) {
            std::swap(arr[i], arr[p_index]);
            --p_index;
            op += 10;
        }
    }
    std::swap(arr[p_index], arr[start]);
    op += 10;
    return p_index;
}

void quickSortMain(std::vector<int> &arr, int start, int end,
                   uint64_t &op) {  // рекурсивная реализация быстрой сортировки
    if (start >= end) {
        return;
    }
    int pivot = partition(arr, start, end, op);
    quickSortMain(arr, start, pivot - 1, op);
    quickSortMain(arr, pivot + 1, end, op);
}

uint64_t quickSort(std::vector<int> &arr, int size) {  // быстрая сортировка
    uint64_t op = 0;
    quickSortMain(arr, 0, size - 1, op);
    return op;
}

void heapify(std::vector<int> &heap, int root, int size, uint64_t &op) {  // обновление кучи
    int curr_max = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    op += 11;
    if (l < size && heap[l] > heap[curr_max]) {
        curr_max = l;
        ++op;
    }
    op += 4;
    if (r < size && heap[r] > heap[curr_max]) {
        curr_max = r;
        ++op;
    }
    ++op;
    if (curr_max != root) {
        std::swap(heap[root], heap[curr_max]);
        op += 9;
        heapify(heap, curr_max, size, op);
    }
}

uint64_t heapSort(std::vector<int> &heap, int n) {  // пирамидальная сортировка (кучей)
    uint64_t op = 0;
    for (int i = n / 2 - 1; i >= 0; --i) {
        ++op;
        heapify(heap, i, n, op);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(heap[0], heap[i]);
        op += 10;
        heapify(heap, 0, i, op);
    }
    return op;
}

uint64_t shellSortCiur(std::vector<int> &arr,
                       int size) {  // сортировка Шелла (последовательность Циура)
    uint64_t op = 0;
    int t = 0, tmp, step;
    int ciur[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    while (t < 9) {
        step = ciur[t];
        op += 2;
        for (int i = step; i < size;
             ++i) {  // Перечисление элементов, которые сортируются на определенном шаге
            ++op;
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step];
                 j -=
                 step) {  // Перестановка элементов внутри поиска, пока i-тый не будет отсортирован
                op += 6;
                tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
                op += 15;
            }
        }
        ++t;
        ++op;
    }
    return op;
}

uint64_t shellSort(std::vector<int> &arr,
                   int size) {  // сортировка Шелла (последовательность Шелла)
    uint64_t op = 0;
    int tmp;
    for (int step = size / 2; step > 0; step /= 2) {  // Выбор шага
        ++op;
        for (int i = step; i < size;
             ++i) {  // Перечисление элементов, которые сортируются на определенном шаге
            ++op;
            for (int j = i - step; j >= 0 && arr[j] > arr[j + step];
                 j -=
                 step) {  // Перестановка элементов внутри поиска, пока i-тый не будет отсортирован
                op += 6;
                tmp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = tmp;
                op += 15;
            }
        }
    }
    return op;
}

int check(std::vector<int> &arr) {  // проверка на то, правильно ли отсортировался массив
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void firstArrayType(std::vector<int> &arr, int size) {  // первый тип массива (0-5)
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        int num = 0 + rand() % 6;
        arr.push_back(num);
    }
}

void secondArrayType(std::vector<int> &arr, int size) {  // второй тип массива (0-4000)
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        int num = 0 + rand() % 4001;
        arr.push_back(num);
    }
}

void thirdArrayType(std::vector<int> &arr,
                    int size) {  // третий тип массива (почти отсортированный)
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        int num = 0 + rand() % 4001;
        arr.push_back(num);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < size / 10; ++i) {
        std::swap(arr[rand() % 4000], arr[size - (rand() % 4000)]);
    }
}

void fourthArrayType(std::vector<int> &arr,
                     int size) {  // четвертый тип массива (обратно отсортированный 4100-1)
    for (int i = size; i >= 1; --i) {
        arr.push_back(i);
    }
}

int main() {
    std::vector<int> arr, arr_new;
    uint64_t op;                       // число элементарных операций
    const int num_of_sorts = 13;       // число сортировок
    const int num_of_array_types = 4;  // число типов массива
    uint64_t (*sort_pointers[num_of_sorts])(std::vector<int> &, int) = {
        // массив указателей на функции сортировок
        selectionSort,
        bubbleSort,
        bubbleSortAiverson1,
        bubbleSortAiverson2,
        insertionSort,
        insertionBinarySort,
        countingSort,
        radixSort,
        mergeSort,
        quickSort,
        heapSort,
        shellSortCiur,
        shellSort};
    void (*arr_pointers[num_of_array_types])(std::vector<int> &, int) = {
        // массив указателей на функции, генерирующие типы массивов
        firstArrayType, secondArrayType, thirdArrayType, fourthArrayType};
    FILE *file, *file2, *inp, *out;
    file = fopen(R"(C:\Users\User\Algorithms_2nd grade\KDZ1\sorts\50-350.4.csv)",
                 "w+");  // файл для замера времени
    file2 = fopen(R"(C:\Users\User\Algorithms_2nd grade\KDZ1\sorts\50-350.4_op.csv)",
                  "w+");  // файл для замера элементарных операций
    inp = fopen(R"(C:\Users\User\Algorithms_2nd grade\KDZ1\sorts\input.txt)",
                "w+");  // файл с несортированной частью массива
    out = fopen(R"(C:\Users\User\Algorithms_2nd grade\KDZ1\sorts\output.txt)",
                "w+");  // файл с отсортированной частью массива

    int wrt = 0;
    int is_big = 0;  // определяем, работаем с массивами 50-300 или 100-4100
    if (is_big == 0) {
        for (int i = 50; i <= 300;
             i += 50) {  // заполнение файлов длинами массивов для удобства построения графиков
            fprintf(file, "%d;", i);
            fprintf(file2, "%d;", i);
        }
    } else {
        for (int i = 100; i <= 4100;
             i += 100) {  // заполнение файлов длинами массивов для удобства построения графиков
            if ((i / 100) % 10 == 1) {
                fprintf(file, "%d;", i);
                fprintf(file2, "%d;", i);
            }
        }
    }
    fprintf(file, "\n");
    fprintf(file2, "\n");

    for (int i = 0; i < num_of_sorts; ++i) {  // цикл по всем сортировкам
        for (int j = 0; j < num_of_array_types; ++j) {  // цикл по всем типам массивов
            (*arr_pointers[j])(arr, 4100);  // создаем большой массив на 4100 элементов
            if (is_big == 0) {
                for (int k = 50; k <= 300; k += 50) {  // массивы размером 50-350
                    uint64_t sum = 0;  // сумма всех записей времени для усреднения
                    for (int s = 0; s < 100; ++s) {  // 100 раз сортируем одинаковую часть массива,
                                                     // чтобы усреднить время
                        arr_new.clear();
                        arr_new.resize(k);  // создаем подмассив размером k
                        std::copy(arr.begin(), arr.begin() + k,
                                  arr_new.begin());  // копируем в него первые k элементов из
                                                     // большого массива
                        auto start =
                        std::chrono::high_resolution_clock::now();  // начало замера времени
                        op = (*sort_pointers[i])(arr_new,
                                                 k);  // получаем число элементарных операций
                        auto elapsed = std::chrono::high_resolution_clock::now() -
                                       start;  // завершаем замер времени
                        uint64_t nanoseconds =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed)
                                .count();  // находим кол-во наносекунд
                        sum += nanoseconds;  // увеличиваем сумму на число работы сортировки
                        if (check(arr_new) == 0) {  // проверка на то, отсортировался ли массив
                            std::cout << "not sorted";
                            return -1;
                        }
                        if (wrt == 0) {
                            for (int ss = 0; ss < k;
                                 ++ss) {  // записываем в файлы inp и out несортированный подмассив
                                          // и сортированный подмассив соответственно
                                fprintf(inp, "%d ", arr[ss]);
                                fprintf(out, "%d ", arr_new[ss]);
                            }
                            ++wrt;
                        }
                    }
                    fprintf(file, "%d;",
                            sum / 100);  // усредняем время работы сортировки и записываем в файл
                    fprintf(file2, "%d;", op);  // записываем в файл число элементарных операций
                }
                // std::cout << "okay\n";
                fprintf(file, "\n");
                fprintf(file2, "\n");
                arr.clear();
            } else {  // для массивов размером 100-4100 все аналогично массивам размером 50-350 за
                      // исключением комментариев, которые я указал ниже
                for (int k = 100; k <= 4100; k += 100) {  // массивы размером 100-4100
                    uint64_t sum = 0;
                    for (int s = 0; s < 100; ++s) {
                        arr_new.clear();
                        arr_new.resize(k);
                        std::copy(arr.begin(), arr.begin() + k, arr_new.begin());
                        auto start = std::chrono::high_resolution_clock::now();
                        op = (*sort_pointers[i])(arr_new, k);
                        auto elapsed = std::chrono::high_resolution_clock::now() - start;
                        uint64_t nanoseconds =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
                        sum += nanoseconds;
                        if (check(arr_new) == 0) {
                            std::cout << "not sorted";
                            return -1;
                        }
                        if (wrt == 0) {
                            for (int ss = 0; ss < k; ++ss) {
                                fprintf(inp, "%d ", arr[ss]);
                                fprintf(out, "%d ", arr_new[ss]);
                            }
                            ++wrt;
                        }
                    }
                    if ((k / 100) % 10 ==
                        1) {  // записываем в файл только длины 100, 1100, 2100, 3100, 4100
                        fprintf(file, "%d;", sum / 100);
                        fprintf(file2, "%d;", op);
                    }
                }
                std::cout << "okay\n";
                fprintf(file, "\n");
                fprintf(file2, "\n");
                arr.clear();
            }
        }
    }
}