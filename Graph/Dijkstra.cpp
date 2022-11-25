#include <iostream>
#include <vector>

typedef struct Edge {
    int y;
    int weight;
} Edge;

class Graph
{
    int V;
    std::vector<std::vector<Edge>> adjList;
    std::vector<std::vector<Edge>> MST;

    public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        MST.clear();
    }

    void addEdge(int v, int w, int weight) {
        Edge e1 = {v, weight};
        Edge e2 = {w, weight};
        adjList[v].push_back(e2);
        adjList[w].push_back(e1);
    }

    int getMinDistance(std::vector<int>& dist, std::vector<bool>& visited) {
        int min = INT32_MAX, minIndex;

        for (int i=0; i<dist.size(); i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void Dijkstra() {
        std::vector<int> dist(V, INT32_MAX);
        std::vector<bool> visited(V, false);

        dist[0] = 0;

        for (int i=0; i<V; i++) {
            int minVertex = getMinDistance(dist, visited);

            visited[minVertex] = true;

            for (int j=0; j<adjList[minVertex].size(); j++) {
                Edge curAdjVertex = adjList[minVertex][j];
                if (!visited[curAdjVertex.y] && dist[minVertex] + curAdjVertex.weight < dist[curAdjVertex.y]) {
                    dist[curAdjVertex.y] = curAdjVertex.weight + dist[minVertex];
                }
            }
        }

        std::cout << "Printing distances" << std::endl;
        for (int x : dist) std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main() {
    Graph *g1 = new Graph(9);
    g1->addEdge(0, 1, 4);
    g1->addEdge(0, 7, 8);
    g1->addEdge(1, 2, 8);
    g1->addEdge(8, 2, 2);
    g1->addEdge(1, 7, 11);
    g1->addEdge(8, 7, 7);
    g1->addEdge(8, 6, 6);
    g1->addEdge(7, 6, 1);
    g1->addEdge(2, 3, 7);
    g1->addEdge(2, 5, 4);
    g1->addEdge(6, 5, 2);
    g1->addEdge(3, 5, 14);
    g1->addEdge(3, 4, 9);
    g1->addEdge(5, 4, 10);
    g1->Dijkstra();
}