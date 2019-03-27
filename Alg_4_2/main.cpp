/*
Для сложения чисел используется старый компьютер. Время, затрачиваемое на нахождение суммы двух чисел равно их сумме.
Таким образом для нахождения суммы чисел 1,2,3 может потребоваться разное время, в зависимости от порядка вычислений.
((1+2)+3) -> 1+2 + 3+3 = 9
((1+3)+2) -> 1+3 + 4+2 = 10
((2+3)+1) -> 2+3 + 5+1 = 11
Требуется написать программу, которая определяет минимальное время, достаточное для вычисления суммы заданного набора чисел.
Формат входных данных. Вначале вводится n - количество чисел. Затем вводится n строк - значения чисел
(значение каждого числа не превосходит 10^9, сумма всех чисел не превосходит 2*10^9).
Формат выходных данных. Натуральное число - минимальное время.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void SiftDown(int *arr, int n, int i) {     //n вместо arr.size()
    int left = 2*i + 1;
    int right = 2*i + 2;
    int min = i;

    if (left < n && arr[left] < arr[i]) {
        min = left;
    }

    if (right < n && arr[right] < arr[min]) {
        min = right;
    }

    if (min != i) {
        swap(arr[i], arr[min]);
        SiftDown(arr, n, min);
    }
}

void BuildHeap(int *arr, int n) {       //построение кучи
    for (int i = n / 2; i > 0; --i) {
        SiftDown(arr, n, i - 1);
    }
}

int Time(int *arr, int n){
    int sum = 0;
    while (n > 1) {
        int min = 1;

        if (n > 2 && arr[2] < arr[min]){
            min = 2;
        }

        arr[0] += arr[min];
        sum += arr[0];
        arr[min] = arr[n - 1];
        n--;
        SiftDown(arr, n, min);
        SiftDown(arr, n, 0);
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    BuildHeap(arr, n);      //построение кучи
    int time = Time(arr, n);

    cout << time;

    return 0;
}

