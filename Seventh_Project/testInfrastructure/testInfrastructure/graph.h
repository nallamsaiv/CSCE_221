#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    private:
        unordered_map<int, unordered_map<int, int>> adjList;

    public:
        Graph() {};

        bool contains_vertex(int u) {
            if(adjList.find(u) != adjList.end()){
                return true;
            }
            return false;
        }

        bool contains_edge(int u, int v) {
            if(contains_vertex(u) == false){
                return false;
            }

            if(contains_vertex(v) == false){
                return false;
            }

            if(adjList[u].find(v) != adjList[u].end()){
                return true;
            }
            return false;
        }

        void addVertex(int u) {
            if(contains_vertex(u) == false){
                adjList[u];
            }
        }

        void addEdge(int u, int v, int w) {
            addVertex(u);
            addVertex(v);
            adjList[u][v] = w;
            adjList[v][u] = w;
        }

        void removeEdge(int u, int v) {
            if(contains_edge(u, v) == true){
                adjList[u].erase(v);
                adjList[v].erase(u);
            }
        }

        void removeVertex(int id) {
            if(contains_vertex(id) == true){
                adjList.erase(id);
            }
        }

        int numVertices() {
            return adjList.size();
        }

        int getEdgeWeight(int u, int v) {
            if(contains_edge(u, v) == true){
                return adjList[u][v];
            }
            return -1;
        }

        vector<pair<int, int>> primMST() {
            int pnt;
            int vertex;
            int dis;
            int u;
            int edge;
            int s = adjList.begin()->first;
            int index;
            vector<pair<int, int>> p;
            unordered_map<int, int> d;
            unordered_map<int, int> parent;
            unordered_map<int, bool> contains;
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            d[s] = 0;
            parent[s] = -1;
            pq.push(make_pair(d[s], make_pair(s, parent[s])));
            contains[s] = true;

            unordered_map<int, unordered_map<int, int>>::iterator itr;
            for(itr = adjList.begin(); itr != adjList.end(); itr++){
                if(itr->first != s){
                    index = itr->first;
                    d[index] = INT32_MAX;
                    parent[index] = -1;
                    pq.push(make_pair(d[index], make_pair(index, parent[index])));
                    contains[index] = true;
                }
            }
            while(pq.empty() == false){
                vertex = pq.top().second.first;
                pnt = pq.top().second.second;
                dis = pq.top().first;
                pq.pop();
                if(contains[vertex] == true){
                    contains[vertex] = false;
                    if(pnt != -1){
                        p.push_back(make_pair(pnt, vertex));
                    }
                    unordered_map<int, int>::iterator itr2;
                    for(itr2 = adjList[vertex].begin(); itr2 != adjList[vertex].end(); itr2++){
                        u = itr2->first;
                        edge = itr2->second;
                        if(contains[u] == true){
                            if(edge < d[u]){
                                d[u] = edge;
                                pq.push(make_pair(d[u], make_pair(u, vertex)));
                            }
                        }
                    }
                }
            }
            return p;
        }
};