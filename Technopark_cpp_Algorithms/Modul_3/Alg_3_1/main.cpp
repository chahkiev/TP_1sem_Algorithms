/*
Требуется отыскать самый выгодный маршрут между городами. Требуемое время работы O((N+M)logN),
где N-количество городов, M-известных дорог между ними.

Формат входных данных.
Первая строка содержит число N – количество городов.
Вторая строка содержит число M - количество дорог.
Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
Последняя строка содержит маршрут (откуда и куда нужно доехать).

Формат выходных данных.
Вывести длину самого выгодного маршрута.
*/

#include <iostream>
#include <list>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;


class GraphEdge {
public:
    int to;
    int weight_edge;

    GraphEdge() {};
    GraphEdge(int to_vertex, int weight_edge) : to(to_vertex), weight_edge(weight_edge) {};

    ~GraphEdge() {};
};


class GraphNode {
public:
    int min_path;
    bool considered;
    list<GraphEdge> edges;

    GraphNode() : min_path(2147483647), edges(), considered(false) {};

    ~GraphNode() {};
};


class GraphNodePtr {
public:
    GraphNode *node;
    int saved_priority;

    GraphNodePtr() {};
    ~GraphNodePtr() {};

    GraphNodePtr(GraphNode &node, int id) : node(&node), saved_priority(node.min_path) {}

    bool isValid() {
        return saved_priority == node->min_path;
    }

    //переопреденение greater
    friend bool operator > (const GraphNodePtr &left, const GraphNodePtr &right) {
        bool result = left.saved_priority > right.saved_priority;
        return result;
    };
};

//невзвешенный неориентированный граф
class ListGraph {
public:
    explicit ListGraph(int n) : nodes(n), from(-1) {}
    ~ListGraph() {};

    void AddEdge(int from, int to, int weight);

    int LengthOfShortestPaths(int from, int to);

private:
    vector<GraphNode> nodes;
    int from;

    void dextreeAlgorithm(int from);
};


void ListGraph::AddEdge(int from, int to, int weight) {
    nodes[from].edges.push_back(GraphEdge(to, weight));
    nodes[to].edges.push_back(GraphEdge(from, weight));
}


int ListGraph::LengthOfShortestPaths(int from, int to) {
    if (this->from != -1) {
        assert(false);
    }
    this->from = from;
    dextreeAlgorithm(from);
    return nodes[to].min_path;
}


void ListGraph::dextreeAlgorithm(int from) {
    priority_queue<GraphNodePtr, vector<GraphNodePtr>, greater<>> queue;
    nodes[from].min_path = 0;
    queue.push(GraphNodePtr(nodes[from], from));

    while (!queue.empty()) {
        GraphNodePtr node_ptr = queue.top();
        queue.pop();
        if (node_ptr.isValid()) {
            GraphNode &current_node = *(node_ptr.node);
            for (GraphEdge edge : current_node.edges) {
                GraphNode &child_node = nodes[edge.to];
                int new_path = current_node.min_path + edge.weight_edge;
                if (!child_node.considered && child_node.min_path > new_path) {
                    //релаксируем вершину
                    child_node.min_path = new_path;
                    queue.push(GraphNodePtr(child_node, edge.to));
                }
            }
            current_node.considered = true;
        }
    }
}


int main() {
    int N = 0;
    cin >> N;
    int M = 0;
    cin >> M;
    ListGraph graph(N);

    for (int i = 0; i < M; i++) {
        int from = -1, to = -1, time = 0;
        cin >> from >> to >> time;
        graph.AddEdge(from, to, time);
    }

    int from = -1, to = -1;
    cin >> from >> to;
    cout << graph.LengthOfShortestPaths(from, to) << endl;
    return 0;
}