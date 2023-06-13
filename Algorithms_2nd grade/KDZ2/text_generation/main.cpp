// генерация исходных текстов

#include <iostream>
#include <cstdlib>

int main() {
    FILE *file1, *file2, *file3, *file4;
    int num;
    srand(1); // чтобы в случае чего не потерять сгенерированную последовательность

    file1 = fopen(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\binary_10k.txt)", "w+");
    for (int i = 0; i < 10000; ++i) {
        num = rand() % 2;
        fprintf(file1, "%d", num);
    }
    fclose(file1);

    file2 = fopen(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\binary_100k.txt)", "w+");
    for (int i = 0; i < 100000; ++i) {
        num = rand() % 2;
        fprintf(file2, "%d", num);
    }
    fclose(file2);

    file3 = fopen(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\dnk_10k.txt)", "w+");
    for (int i = 0; i < 10000; ++i) {
        num = rand() % 4;
        fprintf(file3, "%d", num);
    }
    fclose(file3);

    file4 = fopen(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\dnk_100k.txt)", "w+");
    for (int i = 0; i < 100000; ++i) {
        num = rand() % 4;
        fprintf(file4, "%d", num);
    }
    fclose(file4);
}