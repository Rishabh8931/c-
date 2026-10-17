#include <iostream>
#include <unordered_map>
#include <vector>

/*
    GRAPH
    =====
    A graph contains vertices (nodes) and edges (connections).
    This example uses an adjacency list: each vertex stores its neighbours.
    It is memory-efficient for sparse graphs.

    - Add an edge: O(1) average for an adjacency list
    - Visit all vertices and edges with BFS/DFS: O(V + E)
    - An undirected edge is stored in both directions.

    Weighted graphs can store pairs such as {neighbour, weight} instead.
*/

void depth_first_search(
    int vertex,
    const std::unordered_map<int, std::vector<int>>& graph,
    std::vector<bool>& visited
) {
    visited[vertex] = true;
    std::cout << vertex << ' ';

    for (int neighbour : graph.at(vertex)) {
        if (!visited[neighbour]) {
            depth_first_search(neighbour, graph, visited);
        }
    }
}

int main() {
    std::unordered_map<int, std::vector<int>> graph{
        {0, {1, 2}}, {1, {0, 3}}, {2, {0, 3}}, {3, {1, 2}}
    };
    std::vector<bool> visited(4, false);

    std::cout << "DFS: ";
    depth_first_search(0, graph, visited);
    std::cout << '\n';
}
