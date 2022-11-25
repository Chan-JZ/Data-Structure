#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    int V;
    std::vector<std::vector<int>> adjList;

    public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void printList() {
        for (int i=0; i<adjList.size(); i++) {
            std::cout << i << ": ";
            for (int j=0; j<adjList[i].size(); j++) {
                std::cout << adjList[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int s) {
        std::queue<int> q;
        std::vector<bool> visited(V, false);

        q.push(s);
        visited[s] = true;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            std::cout << cur << " ";

            for (int i=0; i<adjList[cur].size(); i++) {
                if (!visited[adjList[cur][i]]) {
                    q.push(adjList[cur][i]);
                    visited[adjList[cur][i]] = true;
                }
            }
        }
        std::cout << std::endl;
    }

    void BFS_dist(int s) {
        std::queue<int> q;
        std::vector<bool> visited(V, false);
        std::vector<int> dist(V);

        q.push(s);
        visited[s] = true;
        dist[s] = 0;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i=0; i<adjList[cur].size(); i++) {
                if (!visited[adjList[cur][i]]) {
                    dist[adjList[cur][i]] = dist[cur] + 1;
                    q.push(adjList[cur][i]);
                    visited[adjList[cur][i]] = true;
                }
            }
        }

        std::cout << "printing distances: " << std::endl;
        for (int i=0; i<dist.size(); i++) {
            std::cout << i << ": " << dist[i] << std::endl;
        }
    }

    bool isNotVisited(std::vector<int>& path, int x) {
        for (int y : path) if (y == x) return false;
        return true;
    }

    void BFS_reconstructed(int s, int e) {
        std::queue<std::vector<int>> q;
        std::vector<int> path;
        path.push_back(s);
        q.push(path);

        while(!q.empty()) {
            path = q.front();
            q.pop();

            int last = path.back();
            if (last == e) {
                std::cout << "Found a path: " << std::endl;
                for (int x : path) std::cout << x << " ";
                std::cout << std::endl;
                continue;
            }

            for (int i=0; i<adjList[last].size(); i++) {
                if (isNotVisited(path, adjList[last][i])) {
                    std::vector<int> newPath(path);
                    newPath.push_back(adjList[last][i]);
                    q.push(newPath);
                }
            }
        }
    }
};

int main() {
    Graph *g1 = new Graph(13);
    g1->addEdge(0, 9);
    g1->addEdge(0, 7);
    g1->addEdge(0, 11);
    g1->addEdge(9, 10);
    g1->addEdge(9, 8);
    g1->addEdge(1, 10);
    g1->addEdge(1, 8);
    g1->addEdge(12, 8);
    g1->addEdge(12, 2);
    g1->addEdge(3, 2);
    g1->addEdge(3, 4);
    g1->addEdge(6, 7);
    g1->addEdge(3, 7);
    g1->addEdge(11, 7);
    g1->addEdge(6, 5);

    g1->BFS_reconstructed(0, 4);
}