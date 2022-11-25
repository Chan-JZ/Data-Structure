#include <iostream>
#include <vector>
#include <queue>

class Graph
{
    public:
    int v;
    std::vector<std::vector<int>> adjList;

    Graph(int v) {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void bfs(int s) {
        std::queue<int> q;
        q.push(s);

        std::vector<int> visited(this->v, false);
        visited[s] = true;

        while(!q.empty()) {
            int cur = q.front();
            std::cout << cur << " ";
            q.pop();

            for (auto adjacent : adjList[cur]) {
                if (!visited[adjacent]) {
                    q.push(adjacent);
                    visited[adjacent] = true;
                }
            }
        }

        std::cout << std::endl;
    }

    int isNotVisited(int x, std::vector<int>& path) {
        int size = path.size();
        for (int i = 0; i < size; i++)
            if (path[i] == x)
                return 0;
        return 1;
    }

    void bfsReconstructedPaths(int s, int e) {
        std::queue<std::vector<int>> q;
        std::vector<int> path;
        path.push_back(s);
        q.push(path);

        while(!q.empty()) {
            path = q.front();
            q.pop();

            int last = path[path.size()-1];
            if (last == e) {
                for (int i=0; i<path.size(); i++) {
                    std::cout << path[i] << " ";
                }
                std::cout << std::endl;
                continue;
            }

            for (int i=0; i<adjList[last].size(); i++) {
                if (isNotVisited(adjList[last][i], path)) {
                    std::vector<int> newPath(path);
                    newPath.push_back(adjList[last][i]);
                    q.push(newPath);
                }
            }
        }

    }
};

int main() {
    Graph *g1 = new Graph(4);
    g1->addEdge(0, 1);
    g1->addEdge(0, 2);
    g1->addEdge(0, 3);
    g1->addEdge(1, 3);
    // g1->addEdge(2, 0);
    g1->addEdge(2, 1);

    // for (int i=0; i<4; i++) {
    //     for (int j=0; j<g1->adjList[i].size(); j++) {
    //         std::cout << i << "," << g1->adjList[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // g1->bfs(2);
    g1->bfsReconstructedPaths(2, 3);
}

