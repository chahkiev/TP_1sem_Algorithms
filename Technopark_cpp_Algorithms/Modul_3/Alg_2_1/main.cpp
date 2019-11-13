/*
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
*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;


class Node {
public:
    int min_path;
    int number_of_incoming;
    list<int> connected_vertexes;

    Node() : number_of_incoming(0), min_path(2147483647), connected_vertexes() {};
    ~Node() {};
};

//невзвешенный неориентированный граф
class ListGraph {
public:
    explicit ListGraph(int n) : nodes(n), from(-1) {}
    ~ListGraph() {};

    //добавление ребра от from к to
    void AddEdge(int from, int to);

    int NumberOfShortestPaths(int from, int to);

private:
    vector<Node> nodes;
    int from;

    void setNumbersOfShortestPaths(int from);
};

// Добавление ребра от from к to
void ListGraph::AddEdge(int from, int to){
    nodes[from].connected_vertexes.push_back(to);
    nodes[to].connected_vertexes.push_back(from);
}

// Количество кратчайших путей между двумя вершинами
int ListGraph::NumberOfShortestPaths(int from, int to){
    if (this->from == from) { // если уже посчитано
        return nodes[to].number_of_incoming;
    } else if (this->from == -1){
        setNumbersOfShortestPaths(from);
        return nodes[to].number_of_incoming;
    } else {
        return 0;
    }
}


void ListGraph::setNumbersOfShortestPaths(int from){
    queue<int> vertexes_ids; //очередь, содержащая рассматриваемый слой вершин
    vertexes_ids.push(from);
    nodes[from].number_of_incoming = 1;
    nodes[from].min_path = 0;
    while (!vertexes_ids.empty()) {
        int current_vertex = vertexes_ids.front(); //текущая рассматриваемая вершина
        vertexes_ids.pop();
        //единица - вес любого ребра невзвешенного графа
        int new_path = nodes[current_vertex].min_path + 1;
        for (int to : nodes[current_vertex].connected_vertexes){
            //если ещё не были в этой вершине
            if (nodes[to].number_of_incoming == 0){
                vertexes_ids.push(to);
                //Добавляем путей ровно столько, сколькими можно прийти в текущую вершину
                nodes[to].number_of_incoming += nodes[current_vertex].number_of_incoming;
                nodes[to].min_path = new_path;
            } else { // если мы были в этой вершине
                //если путь, которым пришли - короче, чем в данный момент указанный
                if (new_path < nodes[to].min_path){
                    nodes[to].min_path = new_path;
                    nodes[to].number_of_incoming = nodes[current_vertex].number_of_incoming;
                    //если путь такой же длинны
                } else if (new_path == nodes[to].min_path){
                    //Добавляем путей столько, сколькими можно прийти в текущую вершину.
                    nodes[to].number_of_incoming += nodes[current_vertex].number_of_incoming;
                } //если пришли более длинным путём - ничего не делаем
            }
        }
    }
}


int main(){
    int vertex = 0;
    cin >> vertex;
    ListGraph list_graph(vertex);
    int edges = 0;
    cin >> edges;
    for(int i = 0; i < edges; ++i){
        int from(0), to(0);
        cin >> from >> to;
        list_graph.AddEdge(from, to);
    }
    int from = 0;
    int to = 0;
    cin >> from >> to;
    cout << list_graph.NumberOfShortestPaths(from, to) << endl;
    return 0;
}