/*
Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию.
A[0..n-1] и B[0..m-1]. n >> m. Найдите их пересечение.
Требуемое время работы: O(m * log k), где k - позиция элемента B[m-1] в массиве A.
В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. n, k ≤ 10000.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

int BinarySort(int const *arr, int lengthA, int symbol, int *fromIndex){
    int i = 1;
    int firstIndex = *fromIndex;
    int lastIndex = lengthA-1;
    int flag=1;
    while(flag == 1){
        i++;
        if (firstIndex+i*i >= lastIndex){
            flag=0;
        }
        else{
            if (arr[firstIndex+i*i] < symbol){
                firstIndex +=i*i;
            }
            else{
                lastIndex = firstIndex +i*i;
                flag=0;
            }
        }
    }

//    cout << "first_index= " << firstIndex << "  last_index= " << lastIndex << " lastA= " << *fromIndex << endl;
    for (i=firstIndex; i<=lastIndex; i++){
//        cout << "arr(" <<i<< ")= "<< arr[i] << "  symbol= " << symbol << endl;
        if (arr[i]==symbol){
            *fromIndex = i;
            return true;
        }
    }
    return false;
}

int Crossing(int lengthA, int *arrA, int lengthB, int *arrB, int *res) {
    int lastA = 0; //последний индекс в A, числа до которого проверять не имеет смысла т.к. они точно меньше проверяемого числа из массива arrB
    int indexRes = 0; //индекс последнего элемента массива res

    for (int i=0; i<lengthB; i++){
        if (BinarySort(arrA, lengthA, arrB[i], &lastA)){
            res[indexRes] = arrB[i];
            indexRes++;
        }
    }
    return indexRes;
}

int main() {
    int *arrA = NULL, *arrB = NULL, *res = NULL;
    int lengthA = 0, lengthB = 0;

    if (!(cin >> lengthA)) return 0; //ввод и проверка длинны массива А
    if (!(cin >> lengthB)) return 0; //ввод и проверка длинны массива B

    //ввод массива А
    arrA = new int[lengthA];
    for(int i = 0; i < lengthA; i++) {
        if(!(cin >> arrA[i])){
            cout << arrA[i];
            delete [] arrA;
            return 0;
        }
    }

    //ввод массива B
    arrB = new int[lengthB];
    for(int i = 0; i < lengthB; i++) {
        if (!(cin >> arrB[i])){
            delete [] arrA;
            delete [] arrB;
            return 0;
        }
    }

    //ввод и инициализация дополнительного массива
    res = new int[lengthB];
    for(int i = 0; i < lengthB; i++) {
        res[i] = 0;
    }

    //логика и вывод результата
    int indexRes = Crossing(lengthA, arrA, lengthB, arrB, res); //получаем индекс последнего элемента массива res, содержащего элементы пересечения массивов arrA и arrB
    for (int i=0; i<indexRes; i++){
        cout << res[i] << " ";
    }
    //очистка памяти
    delete [] arrA;
    delete [] arrB;
    delete [] res;
    return 0;
}