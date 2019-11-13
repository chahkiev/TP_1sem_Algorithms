/*
Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 106.
Отсортировать массив методом поразрядной сортировки LSD по байтам.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//получение n-го байта числа
int getByte(long long number, int n) {
    number = number >> (8*n)&255; //сдвиг вправо 8*n&255
    return number;
}

//сортировка подсчетом массива чисел по n-тому байту
void SortByBite(long long *data, int size, const int n) {
    int count[256];

    for(int i=0; i<256; i++) {
        count[i]=0;
    }

    //считывание количества чисел с разными значениями байта (от 0 до 255)
    for(int i=0; i<size; i++) {
        count[getByte(data[i], n)]++;
    }

    //рассчет первых индексов для вставки чисел
    for(int i=1; i<256; i++) {
        count[i]+=count[i-1];
    }

    long long *tmp = new long long[size];  // массив результатов

    // создание отсортированного массива результатов
    for(int i=size-1; ; i--) {
        tmp[--count[getByte(data[i], n)]] = data[i];
        if(i==0)
            break;
    }

    //переписывание отсортированного массива в исходный
    for(int i=0; i<size; i++) {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

void LSD(long long *data, int size) {
    int totalBytes = sizeof(long long);

    for(int byte=0; byte<totalBytes; byte++) {
        SortByBite(data, size, byte);
    }
}

int main() {
    int n = 0;
    if(!(cin >> n)) return 0; //ввод и проверка длинны массива

    long long *data = new long long[n];
    for(int i=0; i<n; i++) {
        cin >> data[i];
    }

    LSD(data, n); //сортировка LSD

    for(int i=0; i<n; i++) {
        cout << data[i] << " ";
    }

    delete[] data; //очистка памяти
    return 0;
}