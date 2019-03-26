//#include <iostream>
//#include <ctime>
//using namespace std;
//
//int main() {
//    srand(time(0));
//    int buffSize = 10000000;
//    int *Buffer = new int[buffSize];
//
//    for (int i=0; i<buffSize; i++){
//        Buffer[i] = rand() % 10;
//
//    }
//
//    unsigned int start_time =  clock(); // начальное время
//
//    int NewBuffSize = buffSize*2;
//    int *NewBuffer = new int[NewBuffSize];
//    for (int i=0; i<buffSize; i++){
//        NewBuffer[i] = Buffer[i];
//    }
//
//    delete [] Buffer;
//    Buffer = NewBuffer;
//
//    unsigned int end_time = clock(); // конечное время
//    unsigned int search_time = end_time - start_time; // искомое время
//    cout << "start_time: " << start_time/1000.0 << endl;
//    cout << "end_time: " << end_time/1000.0 << endl;
//    cout << "Increase_of_buffer: " << search_time/1000.0 << endl;
//    return 0;
//}

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int buffSize = 10000000;
    int *Buffer = (int*)malloc(buffSize* sizeof(int));

    for (int i=0; i<buffSize; i++){
        Buffer[i] = rand() % 10;

    }

    unsigned int start_time =  clock(); // начальное время
    Buffer = (int*) realloc (Buffer,2*buffSize);

    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "start_time: " << start_time/1000.0 << endl;
    cout << "end_time: " << end_time/1000.0 << endl;
    cout << "Increase_of_buffer: " << search_time/1000.0 << endl;
    return 0;
}


