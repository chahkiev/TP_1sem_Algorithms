/*
Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
n, m ≤ 100000.
Указание. Обходите массив B от конца к началу.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
using namespace std;

int Indexes(int lengthA, int *arrA, int lengthB, int *arrB, int k) {
    int lastJ = 0, //последний индекс в A
            res = 0; // кол-во индексов

    for(int i = lengthB - 1; i >= 0; i--) {
        int b = arrB[i];

        // обход А с j, которое не удовлетворило условию для прошлого b
        for(int j = lastJ; j < lengthA; j++) {
            int k0 = b + arrA[j];   //k0 - текущая сумма
            if(k0 == k) {
                res++;
            }
            else if(k0 > k) {
                lastJ = j;
                break;
            }
        }
    }
    return res;
}

int main() {
    int *arrA = NULL, *arrB = NULL;
    int lengthA = 0, lengthB = 0;

    //длинна массива А
    cin >> lengthA;

    //ввод массива А
    arrA = new int[lengthA];
    for(int i = 0; i < lengthA; i++) {
        if (!(cin >> arrA[i])) {
            cout << arrA[i];
            delete[] arrA;
            return 0;
        }
    }

    //длинна массива В
    cin >> lengthB;

    //ввод массива B
    arrB = new int[lengthB];
    for(int i = 0; i < lengthB; i++) {
        if (!(cin >> arrB[i])) {
            cout << arrB[i];
            delete[] arrB;
            return 0;
        }
    }

    //ввод k
    int k = 0;
    if(!(cin >> k)) {
        delete [] arrA;
        delete [] arrB;
        return 0;
    }

    //логика и вывод результата
    int res = Indexes(lengthA, arrA, lengthB, arrB, k);
    cout << res;
    delete [] arrA;
    delete [] arrB;

    return 0;
}