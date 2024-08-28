#include "graph.h"
#include <iostream>
using namespace std;

int sumWeights(Graph& g) {
    vector<pair<int, int>> mst = g.primMST();
    int totalWeight = 0;
    for (int i = 0; i < mst.size(); i++) {
        totalWeight += g.getEdgeWeight(mst[i].first, mst[i].second);
    }
    return totalWeight;
}

int testPrims() {
    Graph g;
    vector<int> vertices = {0, 1, 2, 3, 4, 5};
    vector<tuple<int, int, int>> edges = {{0, 1, 12}, {0, 2, 8},
                                          {1, 2, 9}, {1, 3, 22}, {1, 5, 11},
                                          {2, 5, 14}, {2, 3, 16},
                                          {3, 5, 18}, {3, 4, 15},
                                          {4, 5, 3}};

    for (int i = 0; i < vertices.size(); i++) {
        g.addVertex(vertices[i]);
    }

    for (int i = 0; i < edges.size(); i++) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int w = get<2>(edges[i]);
        g.addEdge(v, u, w);
    }
   
    if (sumWeights(g) != 46) {
        cout << "Total cost of minimum spanning tree failed " << sumWeights(g) << endl;
        return 0;
    }

    g.removeEdge(2, 0);
    g.addEdge(0, 2, 4);

    if (sumWeights(g) != 42) {
        cout << "Total cost of minimum spanning tree failed" << sumWeights(g) << endl;
        return 0;
    }

    cout << "Passed Prims" << endl;
    return 50;
}

int main() {
    int score = testPrims();
    return 0;
}