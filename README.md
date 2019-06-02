# Algorithms in Technopark Mail.Ru Group
#### Modul 1
***
1_3
```bash
Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
n, m ≤ 100000.
Указание. Обходите массив B от конца к началу.
```
2_3
```bash
Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию.
A[0..n-1] и B[0..m-1]. n >> m. Найдите их пересечение.
Требуемое время работы: O(m * log k), где k - позиция элемента B[m-1] в массиве A.
В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. n, k ≤ 10000.
```

3_3
```bash
Реализовать очередь с помощью двух стеков.
Использовать стек, реализованный с помощью динамического буфера.
```

4_2
```bash
Для сложения чисел используется старый компьютер. Время, затрачиваемое на нахождение суммы двух чисел равно их сумме.
Таким образом для нахождения суммы чисел 1,2,3 может потребоваться разное время, в зависимости от порядка вычислений.
((1+2)+3) -> 1+2 + 3+3 = 9
((1+3)+2) -> 1+3 + 4+2 = 10
((2+3)+1) -> 2+3 + 5+1 = 11
Требуется написать программу, которая определяет минимальное время, достаточное для вычисления суммы заданного набора чисел.
Формат входных данных. Вначале вводится n - количество чисел. Затем вводится n строк - значения чисел
(значение каждого числа не превосходит 10^9, сумма всех чисел не превосходит 2*10^9).
Формат выходных данных. Натуральное число - минимальное время.
```

5_3
```bash
На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка (Li и Ri).
Найти длину окрашенной части числовой прямой.
```

6_4
```bash
Реализуйте стратегию выбора опорного элемента “случайный элемент”.
Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.
```

7_2
```bash
Дан массив неотрицательных целых 64-битных чисел. Количество чисел не больше 106.
Отсортировать массив методом поразрядной сортировки LSD по байтам.
```

#### Modul 2
***
1_2
```bash
Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв.
Хеш-функция строки должна быть реализована с помощью вычисления значения многочлена методом Горнера.
Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае, когда коэффициент заполнения таблицы достигает 3/4.
Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.
1_1. Для разрешения коллизий используйте квадратичное пробирование. i-ая проба
g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.
```

2_2
```bash
Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
Требуется построить бинарное дерево, заданное наивным порядком вставки.
Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
Рекурсия запрещена.
Выведите элементы в порядке pre-order (сверху вниз).
```

3_1
```bash
Дано число N < 106 и последовательность пар целых чисел из [-231..231] длиной N.
Построить декартово дерево из N узлов, характеризующихся парами чисел {Xi, Yi}.
Каждая пара чисел {Xi, Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.
Добавление узла в декартово дерево выполняйте второй версией алгоритма, рассказанного на лекции:
При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом. Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x, а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y). Новый узел вставьте на место узла P.

Построить также наивное дерево поиска по ключам Xi методом из задачи 2.
Вычислить разницу глубин наивного дерева поиска и декартового дерева. Разница может быть отрицательна.
```

#### Modul 3
***
1_1
```bash
 Необходимо написать несколько реализаций интерфейса:
 CListGraph, хранящий граф в виде массива списков смежности,
 CMatrixGraph, хранящий граф в виде матрицы смежности,
 CSetGraph, хранящий граф в виде массива хэш-таблиц,
 CArcGraph, хранящий граф в виде одного массива пар {from, to}.
 Также необходимо реализовать конструктор, принимающий const IGraph*. Такой конструктор должен скопировать переданный граф в создаваемый объект.
 Для каждого класса создавайте отдельные .h и .cpp файлы.
 Число вершин графа задается в конструкторе каждой реализации.
```

2_1
```bash
Дан невзвешенный неориентированный граф.
В графе может быть несколько кратчайших путей между какими-то вершинами.
Найдите количество различных кратчайших путей между заданными вершинами.
Требуемая сложность O(V+E).

Формат ввода.
v: кол-во вершин (макс. 50000),
n: кол-во ребер (макс. 200000),
n пар реберных вершин,
пара вершин u, w для запроса.

Формат вывода.
Количество кратчайших путей от u к w.
```

3_1
```bash
Требуется отыскать самый выгодный маршрут между городами. Требуемое время работы O((N+M)logN),
где N-количество городов, M-известных дорог между ними.

Формат входных данных.
Первая строка содержит число N – количество городов.
Вторая строка содержит число M - количество дорог.
Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
Последняя строка содержит маршрут (откуда и куда нужно доехать).

Формат выходных данных.
Вывести длину самого выгодного маршрута.
```













































