#include <iostream>
#include <vector>

class Graph
{
    public:
    int V;
    std::vector<std::vector<int>> adjList;
    std::vector<bool> visited;
    std::vector<int> dist;

    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        dist.resize(V);
        visited = std::vector<bool> (V, false);
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    void DFS(int s) {
        visited[s] = true;
        std::cout << s << " ";

        for (int i=0; i<adjList[s].size(); i++) {
            if (!visited[adjList[s][i]]) DFS(adjList[s][i]);
        }
    }

    void DFS_dist_helper(int s) {
        if (adjList[s].size() != 0) DFS_dist(s);
    }

    void DFS_dist(int s) {
        visited[s] = true;
        
        for (int i=0; i<adjList[s].size(); i++) {
            if (!visited[adjList[s][i]]) {
                dist[adjList[s][i]] = dist[s] + 1;
                DFS_dist(adjList[s][i]);
            }
        }
    }
};

int main() {
    Graph *g1 = new Graph(4);
    g1->addEdge(0, 1);
    g1->addEdge(0, 2);
    g1->addEdge(1, 2);
    g1->addEdge(2, 0);
    g1->addEdge(2, 3);

    for (int i=0; i<g1->adjList.size(); i++) {
        std::cout << i << ": ";
        for (int j=0; j<g1->adjList[i].size(); j++) std::cout << g1->adjList[i][j] << " ";
        std::cout << std::endl;
    }

    // g1->DFS(2);

    g1->DFS_dist_helper(2);
    for (int x : g1->dist) std::cout << x << " ";
    std::cout << std::endl;
}