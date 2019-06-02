/*
Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв.
Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае, когда коэффициент заполнения таблицы достигает 3/4.
Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.

Для разрешения коллизий используйте квадратичное пробирование. i-ая проба
g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//константы
#define DEFAULT_TABLE_SIZE 8
#define REHASH_INDEX 0.75
#define HASH 7


template<class T>
int getHash(const T& keys, int size){     // хэш-функция
    int hash = 0;
    for (int i = keys.size(); i >= 0; i--)
    {
        hash += (HASH * hash + keys[i]) % size;
    }
    hash = hash % size;
    return hash;
}


//int SquareProbe(int hash, int i, int M){ // функция квадратичного пробирования
//    hash = (hash + i) % M;
//    return hash;
//}


template<class T>
class Hash_table_node //элемент таблицы
{
public:
    T key = "*";
    bool is_empty = true;
    bool is_deleted = false;


    explicit Hash_table_node(){   //конструктор без параметров
        key = "*";
        is_empty = true;
        is_deleted = false;
//        cout << key << is_empty << " + " << is_deleted << endl;
    }

    explicit Hash_table_node(const T& value){   //конструктор
        key = value;
        is_empty = true;
        is_deleted = false;
//        cout << key << is_empty << " - " << is_deleted << endl;
    }

    const T& get_key() const { return key; }                 // получить ключ
    void set_key(const T& value) { key = value; }            // установить ключ
    bool empty() const { return is_empty; }                  // проверить ключ на empty
    bool deleted() const { return is_deleted; }              // проверить ключ на deleted
    void set_deleted() { is_deleted = true; }                // установить ключ в deleted = true
    void set_not_deleted() { is_deleted = false; }           // установить ключ в deleted = false
};


template<class T>
class Hash_table //хеш-таблица
{
public:
//    vector<Hash_table_node<T>> buffer;
//    vector<Hash_table_node<T>> *buffer, *new_buffer;
//    vector<Hash_table_node<T>> buffer;
    vector<Hash_table_node<T>> buffer;
    int buffer_size;
    int size; //реальное количество элементов в таблице

    Hash_table(){
//        buffer = vector<Hash_table_node<T>*>(DEFAULT_TABLE_SIZE, NULL);
//        vector<Hash_table_node<T>> buffer(DEFAULT_TABLE_SIZE);
        buffer.reserve(DEFAULT_TABLE_SIZE);
        buffer_size = DEFAULT_TABLE_SIZE;
        for (int j=0; j< buffer_size; j++){
//            buffer[j].key = "*";
            buffer[j].is_empty = true;
            buffer[j].is_deleted = false;
//            cout << buffer[j].key << " " << buffer[j].is_empty << "  " << buffer[j].is_deleted << endl;
        }
        size = 0;
    }

    ~Hash_table()
    {
//        for (int i = 0; i < buffer.size(); i++) delete buffer[i];
        buffer.clear();
    }

    void rehash() //перехэширование
    {
        int new_buffer_size = buffer_size * 4;
        vector<Hash_table_node<T>> new_buffer(new_buffer_size);
//        new_buffer  = new vector<Hash_table_node<T>>;

//        for (int j=0; j< new_buffer_size; j++){
//            new_buffer[j].key = "*";
//            new_buffer[j].is_empty = true;
//            new_buffer[j].is_deleted = false;
//            cout << new_buffer[j].key << " " << new_buffer[j].is_empty << "  " << new_buffer[j].is_deleted << endl;
//        }

        for (int i = 0; i < buffer_size; i++)
        {
            if (!buffer[i].empty() && !buffer[i].deleted()) //если элемент существует в старой таблице
            {
                int h1 = getHash(buffer[i].get_key(), new_buffer_size);
                int k = 0;
                while (!new_buffer[h1].empty() && k < new_buffer_size) //ищем свободную ячейку в новой таблице
                {
//                    h1 = SquareProbe(h1, i, new_buffer_size);
                    h1 = (h1 + k) % new_buffer_size;
                    k++;
                }
                new_buffer[h1] = buffer[i];
            }
//            else //если ячейка старой таблицы пуста
//            {
//                delete buffer[i];
//            }
            buffer[i].is_empty = false;
        }
        buffer = new_buffer;
        buffer_size = new_buffer_size;
    }


    bool add(const T& value)
    {
        if (((float)size / buffer_size) >= REHASH_INDEX) //проверка на необходимость перехэширования
        {
            rehash();
        }
        int h1 = getHash(value, buffer_size);
        int i = 0;
        int	first_deleted = -1;
//        cout << "h1= " << h1 << "   " << "is_empty= " << buffer[h1].empty() << endl;
        while (!buffer[h1].empty() && i < buffer_size)
//        while (i < buffer_size)
        {
            if (buffer[h1].get_key() == value && !buffer[h1].deleted()) //если такой ключ уже есть в таблице
            {
                return false;
            }
            if (buffer[h1].deleted() && first_deleted < 0) // сохраняем номер первого удалённого элемента
            {
                first_deleted = h1;
            }

//            h1 = SquareProbe(h1, i, buffer_size);
            h1 = (h1 + i) % buffer_size;
//            cout << "h1= " << h1 << "   " << "is_empty= " << buffer[h1].empty() << endl;
            i++;
        }

        if (first_deleted < 0) //вставляем новый ключ
        {
            buffer[h1].set_key(value);
            buffer[h1].is_empty = false;
        }
        else //вставляем на место первого удалённого
        {
            buffer[first_deleted].set_key(value);
            buffer[first_deleted].set_not_deleted();
            buffer[first_deleted].is_empty = false;
        }
        size++;
        return true;
    }

    bool remove(const T& value)
    {
        int h1 = getHash(value, buffer_size);
        int i = 0;
        while (!buffer[h1].empty() && i < buffer_size)
        {
            if (buffer[h1].get_key() == value && !buffer[h1].deleted()) //если нашли элемент
            {
                buffer[h1].set_deleted();
//                buffer[h1].is_empty = true;
                size--;
                return true;
            }
//            h1 = SquareProbe(h1, i, buffer_size);
            h1 = (h1 + i) % buffer_size;
            i++;
        }
        return false; //не нашли такой элемент
    }

    bool has(const T& value) const
    {
        int h1 = getHash(value, buffer_size);
        int i = 0;
        while (!buffer[h1].empty() && i < buffer_size)
//        while (i < buffer_size)
        {
            if (buffer[h1].get_key() == value && !buffer[h1].deleted()) //если нашли элемент
            {
                return true;
            }
//            h1 = SquareProbe(h1, i, buffer_size);
            h1 = (h1 + i) % buffer_size;
            i++;
        }
        return false; //если не нашли такого элемента
    }

//    void Print(){
//        for (int i=0; i < buffer_size; i++){
//            cout << buffer[i].key << "   ";
//        }
//
//        cout << endl;
//
//        for (int i=0; i < buffer_size; i++){
//            cout << buffer[i].is_empty << "   ";
//        }
//
//        cout << endl;
//
//        for (int i=0; i < buffer_size; i++){
//            cout << buffer[i].is_deleted << "   ";
//        }
//
//    }
};


int main()
{
    Hash_table<string> hash_table;
//    hash_table = new Hash_table<string>;
    char command = ' ';
    string value;
    bool status = false;


//    vector<Hash_table_node<string>> buffer (8);


    while (cin >> command >> value)
    {
        switch (command)
        {
            case '+':
                status = hash_table.add(value);
                break;
            case '?':
                status = hash_table.has(value);
                break;
            case '-':
                status = hash_table.remove(value);
                break;
            default:
//                hash_table.Print();
                continue;
        }

        if (status) { cout << "OK" << endl; }
        else { cout << "FAIL" << endl; }
    }
//    delete [] hash_table;

    return 0;
}


//#include <vector>
//#include <iostream>
//
//class Car {
//public:
//    Car() : name("Default") {};
//    Car(std::string inputName) : name(inputName) {};
//    const void print() { std::cout << name << std::endl;}
//protected:
//    std::string name;
//};
//
//int main() {
//
//    std::vector<Car> v1(3);
//    for(int i = 0; i < 3; i++) v1[i].print();
//
//    return 0;
//}
