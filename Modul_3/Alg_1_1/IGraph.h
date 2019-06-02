#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>

struct IGraph {
    virtual ~IGraph() = default;
    virtual void AddEdge(int from, int to) = 0;

    virtual unsigned long VerticesCount() const  = 0;

    virtual void GetNextVertices(int vertex, std::vector<int>& vertices) const = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int>& vertices) const = 0;
};

#endif