#include <iostream>
#include <vector>
#include <algorithm>

typedef struct Edge {
    int y;
    int weight;
} Edge;

class Graph
{
    int V;
    std::vector<std::vector<Edge>> adjList;

    public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int v, int w, int weight) {
        Edge e = {v, weight};
        adjList[w].push_back(e);
    }

    void getEdge(std::vector<std::vector<int>>& edges) {
        for (int i=0; i<adjList.size(); i++) {
            for (int j=0; j<adjList[i].size(); j++) edges.push_back(std::vector<int>{i, adjList[i][j].y, adjList[i][j].weight});
        }
    }

    void printEdge(std::vector<std::vector<int>>& edges) {
        for (int i=0; i<edges.size(); i++) {
            std::cout << edges[i][0] << "-" << edges[i][1] << ", weight: " << edges[i][2] << std::endl;
        }
    }

    void Union(int x, int y, std::vector<int> &parents) {
        int p1 = getParent(x, parents);
        int p2 = getParent(y, parents);
        parents[p1] = p2;
    }

    int getParent(int n, std::vector<int> &parents) {
        if (parents[n] == -1) return n;

        return getParent(parents[n], parents);
    }

    void Kruskal() {
        std::vector<std::vector<int>> edges;
        std::vector<std::vector<int>> result;
        
        getEdge(edges);
        std::sort(edges.begin(), edges.end(), [&edges](auto a, auto b) {
            return a[2] < b[2];
        });

        std::vector<int> parents(edges.size(), -1);

        for (auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            int w = edge[2];

            if (getParent(x, parents) != getParent(y, parents)) {
                Union(x, y, parents);
                result.push_back(std::vector<int> {x, y, w});
            }
        }

        printEdge(result);
        int totalWeight = 0;
        for (auto x : result) totalWeight += x[2];
        std::cout << "totalWeight: " << totalWeight << std::endl;
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
    g1->Kruskal();
}