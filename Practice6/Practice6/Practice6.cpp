#include "Graph.h"


std::map<int, std::map<int, int>> floydWarshall(std::map<int, Node*>& graph) {
    std::map<int, std::map<int, int>> D;
    for (auto entry : graph) {
        int i = entry.first;
        D[i][i] = 0;

        for (auto edge : entry.second->edges) {
            int j = edge->adjacentNode->value;
            D[i][j] = edge->weight;
        }
    }
    for (auto entry_k : graph) {
        int k = entry_k.first;
        for (auto entry_i : graph) {
            int i = entry_i.first;
            for (auto entry_j : graph) {
                int j = entry_j.first;
                if (D[i][k] != 0 && D[k][j] != 0 && (D[i][j] == 0 || D[i][j] > D[i][k] + D[k][j])) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    return D;
}


int main() {
    std::locale::global(std::locale(""));

    std::vector<std::vector<int>> graphData;
    int numEdges;
    std::cout << "Введите количество рёбер графа: ";
    std::cin >> numEdges;

    std::cout << "Вводите информацию в таком виде: номер узла от которого ведёт ребро, номер узла к которому ведёт ребро, вес данного ребра" << std::endl;
    for (int i = 0; i < numEdges; i++) {
        int start, end, weight;
        std::cin >> start >> end >> weight;
        graphData.push_back({start, end, weight});
    }

    std::map<int, Node*> graph = createGraph(graphData);
    std::map<int, std::map<int, int>> shortestPaths = floydWarshall(graph);

    for (auto row : shortestPaths) {
        int i = row.first;
        for (auto cell : row.second) {
            int j = cell.first;
            int distance = cell.second;
            if (distance != 0) {
                std::cout << "Наикратчайший путь от " << i << " до " << j << ": " << distance << std::endl;
            }
        }
    }

    return 0;
}