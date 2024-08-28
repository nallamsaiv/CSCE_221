#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    int n = 9;
    Graph g(n);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);

    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);

    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);

    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    string path1 = g.printShortestPath(0, 1);
    string expectedPath1 = "0 1 ";
    cout << path1 << endl;

    string path2 = g.printShortestPath(0, 2);
    string expectedPath2 = "0 1 2 ";
    cout << path2 << endl;
    
    string path3 = g.printShortestPath(0, 3);
    string expectedPath3 = "0 1 2 3 ";
    cout << path3 << endl;

    string path4 = g.printShortestPath(0, 4);
    string expectedPath4 = "0 7 6 5 4 ";
    cout << path4 << endl;

    string path5 = g.printShortestPath(0, 5);
    string expectedPath5 = "0 7 6 5 ";
    cout << path5 << endl;

    string path6 = g.printShortestPath(0, 6);
    string expectedPath6 = "0 7 6 ";
    cout << path6 << endl;

    string path7 = g.printShortestPath(0, 7);
    string expectedPath7 = "0 7 ";
    cout << path7 << endl;

    string path8 = g.printShortestPath(0, 8);
    string expectedPath8 = "0 1 2 8 ";
    cout << path8 << endl;

    return 0;
}