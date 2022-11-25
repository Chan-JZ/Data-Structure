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

    int getMinNode(std::vector<int>& dist, std::vector<bool>& set) {
        int curMinIndex = 0;
        int curMin = INT32_MAX;

        for (int i=0; i<dist.size(); i++) if (dist[i] < curMin && !set[i]) {
            curMin = dist[i];
            curMinIndex = i;
        }
        set[curMinIndex] = true;

        return curMinIndex;
    }

    void PrimMST() {
        std::vector<bool> set(V, false);
        std::vector<int> dist(V, INT32_MAX);
        std::vector<int> parent(V, -1);

        dist[0] = 0;

        for (int i=0; i<V-1; i++) {
            int minNode = getMinNode(dist, set);

            for (int j=0; j<adjList[minNode].size(); j++) {
                Edge curAdjNode = adjList[minNode][j];
                if (!set[curAdjNode.y] && curAdjNode.weight < dist[curAdjNode.y]) {
                    dist[curAdjNode.y] = curAdjNode.weight;
                    parent[curAdjNode.y] = minNode;
                }
            }
        }

        int totalWeight = 0;
        for (int i=1; i<parent.size(); i++) {
            std::cout << parent[i] << "-" << i << ", weight: " << dist[i] << std::endl;
            totalWeight += dist[i];
        }
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
    g1->PrimMST();
}