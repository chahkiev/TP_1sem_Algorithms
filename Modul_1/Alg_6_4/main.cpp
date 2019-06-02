/*
6_4. Реализуйте стратегию выбора опорного элемента “случайный элемент”.
Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
using namespace std;

int Partition(int *mas, int left, int right) {
    int buf;
    int rand_index;

    if (left!=right){
        rand_index = left + rand()% (right-left);
        buf = mas[rand_index];
        mas[rand_index] = mas[left];
        mas[left] = buf;
    }
    int x = mas[left];

    // два счетчика справа
    int i = right+1;
    for (int j = right; j >= left; j--) {
        if (mas[j] >= x) {
            i = i - 1;
            buf = 0;
            buf = mas[j];
            mas[j] = mas[i];
            mas[i] = buf;
        }
    }
    return i;
}

int get_pivot(int *mas, const int k, int left, int right) {
    while(1) {
        int pos = Partition(mas, left, right);

        if (pos < k)
            left = pos + 1;
        else if (pos > k)
            right = pos - 1;
        else
            return mas[k];
    }
}

int main() {
    int *mas = NULL;
    int n,k;

    if (!(cin >> n)) return 0; //ввод и проверка длинны массива
    if (!(cin >> k)) return 0; //ввод и проверка статистики

    mas = new int[n]; //инициализация массива
    for(int i = 0; i < n; i++) {
        if(!(cin >> mas[i])) {
            cout << mas[i];
            delete [] mas;
            return 0;
        }
    }

    cout << get_pivot(mas, k, 0, n - 1);
    delete [] mas; //освобождение памяти
    return 0;
}

