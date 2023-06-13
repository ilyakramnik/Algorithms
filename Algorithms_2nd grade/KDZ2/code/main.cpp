// КДЗ-2, выполнил Крамник Илья Михайлович БПИ-213

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <chrono>

int nativeAlgorithm(std::string str, std::string substr) { // наивный алгоритм
    int ind = -1;
    for (int i = 0; i < str.size() - substr.size(); ++i) {
        bool is_same = true;
        for (int j = 0; j < substr.size(); ++j) {
            if (str[i + j] != substr[j] && substr[j] != '?') {
                is_same = false;
                break;
            }
        }
        if (is_same) {
            ind = i;
        }
    }
    return ind;
}

std::vector<int> prefix_function(std::string s) { // префикс-функция
    int n = static_cast<int>(s.size());
    std::vector<int> br(n);
    for (int i = 1; i < n; ++i) {
        int j = br[i - 1];
        while (j > 0 && (s[i] != s[j] && s[j] != '?')) {
            j = br[j - 1];
        }
        if (s[i] == s[j] || s[j] == '?') {
            ++j;
        }
        br[i] = j;
    }
    return br;
}

std::vector<int> makeBrs(std::string &s) { // уточненные грани
    std::vector<int> br = prefix_function(s);
    int n = br.size();
    std::vector<int> brs(n);

    brs[0] = 0;
    brs[n - 1] = br[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        if (s[br[i]] != s[i + 1] && s[br[i]] != '?') {
            brs[i] = br[i];
        } else {
            brs[i] = brs[br[i]];
        }
    }
    return brs;
}

int kmp(std::string str, std::string substr) { //алгоритм КМП
    int n = static_cast<int>(str.size());
    int m = static_cast<int>(substr.size());
    std::vector<int> br = prefix_function(substr);
    int j = 0;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && ((str[i] != substr[j] && substr[j] != '?') || j == m)) {
            j = br[j - 1];
        }
        if (str[i] == substr[j] || substr[j] == '?') {
            ++j;
        }
        if (j == m) {
            pos = i - m + 1;
            j = br[j - 1];
        }
    }
    return pos;
}

int kmpBRS(std::string str, std::string substr) { // алгоритм КМП с уточненными гранями
    int n = static_cast<int>(str.size());
    int m = static_cast<int>(substr.size());
    std::vector<int> brs = makeBrs(substr);
    int j = 0;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && ((str[i] != substr[j] && substr[j] != '?') || j == m)) {
            j = brs[j - 1];
        }
        if (str[i] == substr[j] || substr[j] == '?') {
            ++j;
        }
        if (j == m) {
            pos = i - m + 1;
            j = brs[j - 1];
        }
    }
    return pos;
}

int main() {
    srand(time(nullptr));
    int pos, question_pos;
    int last_ind;
    std::string text, text2, text3, text4, final_text, line, pattern;
    int (*search_pointers[3])(std::string, std::string) = {
            // массив указателей на функции поиска подстроки в строке
            nativeAlgorithm, kmp, kmpBRS
    };

    std::ifstream in1(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\binary_10k.txt)");
    if (in1.is_open()) {
        while (std::getline(in1, line)) {
            text += line;
        }
    }

    std::ifstream in2(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\dnk_10k.txt)");
    if (in2.is_open()) {
        while (std::getline(in2, line)) {
            text2 += line;
        }
    }

    std::ifstream in3(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\binary_100k.txt)");
    if (in3.is_open()) {
        while (std::getline(in3, line)) {
            text3 += line;
        }
    }

    std::ifstream in4(R"(C:\Users\User\Algorithms\Algorithms_2nd grade\KDZ2\code\dnk_100k.txt)");
    if (in4.is_open()) {
        while (std::getline(in4, line)) {
            text4 += line;
        }
    }

    std::ofstream out1, out2, out3, out4;

    int type_of_pattern = 0; // шаблоны со знаком ? или без

    if (type_of_pattern == 0) {
        out1.open("binary_10k_time.csv");
        out2.open("dnk_10k_time.csv");
        out3.open("binary_100k_time.csv");
        out4.open("dnk_100k_time.csv");
        out1.close();
        out2.close();
        out3.close();
        out4.close();
        out1.open("binary_10k_time.csv", std::ios::app);
        out2.open("dnk_10k_time.csv", std::ios::app);
        out3.open("binary_100k_time.csv", std::ios::app);
        out4.open("dnk_100k_time.csv", std::ios::app);

        for (int i = 100; i <= 3000; i += 500) {
            if (out1.is_open()) {
                out1 << i << ';';
            }
            if (out2.is_open()) {
                out2 << i << ';';
            }
            if (out3.is_open()) {
                out3 << i << ';';
            }
            if (out4.is_open()) {
                out4 << i << ';';
            }
        }
        out1 << '\n';
        out2 << '\n';
        out3 << '\n';
        out4 << '\n';

        for (int type = 0; type < 2; ++type) { // выбираем размер файла (10к / 100к)
            for (int f = 0; f < 2; ++f) { // выбираем с каким файлом работаем (binary / dnk)
                for (int i = 0; i < 3; ++i) { // цикл по всем алгоритмам
                    for (int count = 100; count <= 3000; count += 100) { // цикл по размерам подстроки
                        if (type == 0) {
                            pos = rand() % 7000; // начальная позиция для подстроки
                            if (f == 0) {
                                pattern = text.substr(pos, count);
                                final_text = text;
                            } else {
                                pattern = text2.substr(pos, count);
                                final_text = text2;
                            }
                        } else {
                            pos = rand() % 97000; // начальная позиция для подстроки
                            if (f == 0) {
                                pattern = text3.substr(pos, count);
                                final_text = text3;
                            } else {
                                pattern = text4.substr(pos, count);
                                final_text = text4;
                            }
                        }
                        uint64_t sum = 0;  // сумма всех записей времени для усреднения
                        for (int j = 0; j < 100; ++j) { // 100 раз запускаем алгоритм, чтобы усреднить время
                            auto start = std::chrono::high_resolution_clock::now();  // начало замера времени
                            last_ind = (*search_pointers[i])(final_text,
                                                             pattern);  // получаем последний индекс вхождения подстроки в строку
                            auto elapsed =
                                    std::chrono::high_resolution_clock::now() - start;  // завершаем замер времени
                            uint64_t nanoseconds =
                                    std::chrono::duration_cast<std::chrono::nanoseconds>(
                                            elapsed).count();  // находим кол-во наносекунд
                            sum += nanoseconds;  // увеличиваем сумму на число работы алгоритма
                        }

                        if ((count / 100) % 10 == 1 || (count / 100) % 10 == 6) { // запись в файлы
                            if (type == 0) { // файлы размером 10к
                                if (f == 0) { // бинарный файл
                                    if (out1.is_open()) {
                                        out1 << sum / 100 << ';';
                                    }
                                } else { //днк файл
                                    if (out2.is_open()) {
                                        out2 << sum / 100 << ';';
                                    }
                                }
                            } else { // файлы размером 100к
                                if (f == 0) { // бинарный файл
                                    if (out3.is_open()) {
                                        out3 << sum / 100 << ';';
                                    }
                                } else { //днк файл
                                    if (out4.is_open()) {
                                        out4 << sum / 100 << ';';
                                    }
                                }
                            }
                        }
                    }
                    if (type == 0) {
                        if (f == 0) {
                            out1 << '\n';
                        } else {
                            out2 << '\n';
                        }
                    } else {
                        if (f == 0) {
                            out3 << '\n';
                        } else {
                            out4 << '\n';
                        }
                    }
                }
            }
        }
    } else { // type_of_pattern = 1
        out1.open("binary_10k_time_4_symb.csv");
        out2.open("dnk_10k_time_4_symb.csv");
        out3.open("binary_100k_time_4_symb.csv");
        out4.open("dnk_100k_time_4_symb.csv");
        for (int i = 100; i <= 3000; i += 500) {
            if (out1.is_open()) {
                out1 << i << ';';
            }
            if (out2.is_open()) {
                out2 << i << ';';
            }
            if (out3.is_open()) {
                out3 << i << ';';
            }
            if (out4.is_open()) {
                out4 << i << ';';
            }
        }
        out1 << '\n';
        out2 << '\n';
        out3 << '\n';
        out4 << '\n';
        out1.close();
        out2.close();
        out3.close();
        out4.close();
        out1.open("binary_10k_time_4_symb.csv", std::ios::app);
        out2.open("dnk_10k_time_4_symb.csv", std::ios::app);
        out3.open("binary_100k_time_4_symb.csv", std::ios::app);
        out4.open("dnk_100k_time_4_symb.csv", std::ios::app);

        for (int symb = 0; symb < 5; ++symb) { // число символов подстановки
            for (int type = 0; type < 2; ++type) { // выбираем размер файла (10к / 100к)
                for (int f = 0; f < 2; ++f) { // выбираем с каким файлом работаем (binary / dnk)
                    for (int i = 0; i < 3; ++i) { // цикл по всем алгоритмам
                        for (int count = 100; count <= 3000; count += 100) {
                            if (type == 0) {
                                pos = rand() % 7000; // начальная позиция для подстроки
                                if (f == 0) {
                                    pattern = text.substr(pos, count);
                                    final_text = text;
                                } else {
                                    pattern = text2.substr(pos, count);
                                    final_text = text2;
                                }
                            } else {
                                pos = rand() % 97000; // начальная позиция для подстроки
                                if (f == 0) {
                                    pattern = text3.substr(pos, count);
                                    final_text = text3;
                                } else {
                                    pattern = text4.substr(pos, count);
                                    final_text = text4;
                                }
                            }
                            for (int s = 0; s < symb; ++s) { // замена рандомных символов строки знаками ?
                                question_pos = rand() % pattern.size(); // генерируем рандомную позицию для ?
                                pattern[question_pos] = '?';
                            }
                            uint64_t sum = 0;  // сумма всех записей времени для усреднения
                            for (int j = 0; j < 100; ++j) { // 100 раз запускаем алгоритм, чтобы усреднить время
                                auto start = std::chrono::high_resolution_clock::now();  // начало замера времени
                                last_ind = (*search_pointers[i])(final_text,
                                                                 pattern);  // получаем последний индекс вхождения подстроки в строку
                                auto elapsed =
                                        std::chrono::high_resolution_clock::now() - start;  // завершаем замер времени
                                uint64_t nanoseconds =
                                        std::chrono::duration_cast<std::chrono::nanoseconds>(
                                                elapsed).count();  // находим кол-во наносекунд
                                sum += nanoseconds;  // увеличиваем сумму на число работы алгоритма
                            }

                            if ((count / 100) % 10 == 1 || (count / 100) % 10 == 6) { // запись в файлы
                                if (type == 0) { // файлы размером 10к
                                    if (f == 0) { // бинарный файл
                                        if (out1.is_open()) {
                                            out1 << sum / 100 << ';';
                                        }
                                    } else { //днк файл
                                        if (out2.is_open()) {
                                            out2 << sum / 100 << ';';
                                        }
                                    }
                                } else { // файлы размером 100к
                                    if (f == 0) { // бинарный файл
                                        if (out3.is_open()) {
                                            out3 << sum / 100 << ';';
                                        }
                                    } else { //днк файл
                                        if (out4.is_open()) {
                                            out4 << sum / 100 << ';';
                                        }
                                    }
                                }
                            }
                        }
                        if (type == 0) {
                            if (f == 0) {
                                out1 << '\n';
                            } else {
                                out2 << '\n';
                            }
                        } else {
                            if (f == 0) {
                                out3 << '\n';
                            } else {
                                out4 << '\n';
                            }
                        }
                    }
                }
            }
        }
    }
}
