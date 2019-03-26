/*
5_3. На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка (Li и Ri).
Найти длину окрашенной части числовой прямой.
 */

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

int main(){
    int *mas=NULL;
    int n;
    int max_elem, flag_first=0;

    if(scanf("%d", &n)!=1) return 0;
    assert(n >= 0);

    mas = (int *) malloc(2*n * sizeof(int)); //инициализация массива
    for(int i = 0; i < 2*n; i=i+2) {
        if(scanf("%d", mas + i) != 1) {
            printf("%d", *(mas+i));
            free(mas);
            return 0;
        }
        if (flag_first==0){
            max_elem = mas[i];
            flag_first=1;
        }
        if (mas[i] > max_elem) max_elem = mas[i];
        if(scanf("%d", mas + i + 1) != 1) {
            printf("%d", *(mas+i+1));
            free(mas);
            return 0;
        }
        if (mas[i+1] > max_elem) max_elem = mas[i+1];

    }

    for (int i=0; i<2*n; i++) cout << mas[i] << " ";
    cout << "max = " << max_elem;
    return 0;
}
