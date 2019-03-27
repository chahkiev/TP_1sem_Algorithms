/*
На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка (Li и Ri).
Найти длину окрашенной части числовой прямой.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const size_t strings_size = 8; // изначальный размер строки
const size_t increase = 2;

// функция для ввода 1 строки массива строк
char* input_string() {
    size_t size = strings_size;
    char* string = (char*)malloc(sizeof(char) * size);
    if (string == NULL){
        printf("[error]");
        return 0;
    }
    char letter = getchar();
    int i = 0;
    while (letter != '\n' && letter != EOF){
// увеличиваем строку, если вышли за начальный размер
        if (i >= size) {
            size *= increase;
            string = realloc(string, sizeof(char) * size);
        }
// добавляем символ
        string[i] = letter;
        letter = getchar();
        i++;
    }
//освобождаем память, если строка пустая
    if (letter == EOF && i == 0) {
        free(string);
        return NULL;
    }
//добавляем в конце '\0' для обозначения конца строки
    string[i+1] = '\0';
    return string;
}

char** input_strings(int* str_size) {
    char** answer;
    size_t size = strings_size;
    char** strings = (char**)malloc(sizeof(char*) * size);
    if (strings == NULL){
        printf("[error]");
        return 0;
    }
    int i = 0;
    char *string = input_string();
    while (!feof(stdin) && !ferror(stdin)) {
        if (string == NULL || string[0] == '\0') {
            answer = strings;
            return answer;
        }
// увеличиваем размер массива строк аналогично увеличиванию строки
        if (i >= size) {
            size *= increase;
            strings = realloc(strings, sizeof(char*) * size);
        }
// добавляем строку
        strings[i] = string;
        string = input_string();
// увеличиваем количество введеных строк
        (*str_size)++;
        i++;
    }
// освобождаем память, если вдруг на вход не было подано ничего
    if (ferror(stdin) || (i == 0 && string == NULL) ) {
        size_t j;
        for (j = 0; j < i; j++) {
            free(strings[j]);
        }
        free(strings);
        return NULL;
    }
    answer = strings;
    return answer;
}

int count(const char *const *strings, int *str_size, char ***res) {
    if (strings == NULL || * str_size == 0 || res == NULL) {
        return 0;
    }
    char** result = (char**)malloc(sizeof(char*) **str_size);
    if (result == NULL){
        printf("[error]");
        return 0;
    }
    int counter = 0;
    int iter = 0;
    for (int i = 0; i < *str_size; ++i) {
        int current_size = strlen(strings[i]);
        for (int j = 0; j < current_size + 1; j++) {
            if (strings[i][j] == '(')
                counter += 1;
            else if (strings[i][j] == ')')
                counter -= 1;
        }
        if (counter == 0) {
            result[iter] = (char*)malloc(sizeof(char) * current_size + 1);
            if (result[iter] == NULL){
                printf("[error]");
                return 0;
            }
            for (int j = 0; j < current_size + 1; j++) {
                result[iter][j] = strings[i][j];
            }
            iter += 1;
        }
        counter = 0;
    }

    result = realloc(result, (sizeof(char*) * iter));
    *res = result;
    return iter;
}

int main(){
// считываем строки в массив строк
    int input_size = 0;
    char** input = (input_strings(&input_size));
// если введено ноль строк - память не выделялась, выводим сообщение
    if (input_size == 0) {
        printf("[error]");
        return 0;
    }
// вызваем метод для счета скобок
    char** res;
    int strings = count((const char *const *) input, &input_size, &res);
// выводим на экран
    for (int i = 0; i < strings; i++) {
        printf("%s\n", res[i]);
    }
//освобождаем память
    for (int i = 0; i < input_size; i++) {
        free(input[i]);
    }
    free(input);
    for (int i = 0; i < input_size; i++) {
        free(res[i]);
    }
    free(res);
    return 0;
}
