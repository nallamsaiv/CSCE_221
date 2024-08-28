#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
    private:
        int n;
        typedef pair<int, int> Edge;
        vector<list<Edge>> v;
        
    public:
        Graph(int size = 2) {
            n = size;
            v.resize(n);
        }

        void addEdge(int x, int y, int w) {
            v[x].push_back(make_pair(y, w));
            v[y].push_back(make_pair(x, w));
        }

        void print() {
            for(int i = 0; i < n; i++) {
                cout << "Node " << i << " is connected to: ";
                for (pair<int,int> j : v[i]) {
                    if(j.first != -1){
                        cout << j.first << " : "<< j.second<<", ";
                    }
                }
                cout << endl;
            }
        }

        vector<pair<int, int>> dijkstra(int startNode) {
            int node;
            int weight;
            int u;
            int u_weight;
            vector<pair<int, int>> p(n);
            vector<int> d(n);
            vector<int> parent(n);
            vector<bool> done(n);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            d[startNode] = 0;
            parent[startNode] = -1;
            pq.push(make_pair(d[startNode], startNode));

            for(int i = 0; i < n; i++){
                if(i != startNode){
                    d[i] = INT32_MAX;
                    parent[i] = -1;
                    pq.push(make_pair(d[i], i));
                }
                done[n] = false;
            }

            while(pq.empty() == false){
                node = pq.top().second;
                weight = pq.top().first;
                pq.pop();
                if(done[node] == false){
                    done[node] = true;
                    for(pair<int,int> j : v[node]){
                        u = j.first;
                        u_weight = j.second;
                        if(d[u] > (d[node] + u_weight)){
                            d[u] = d[node] + u_weight;
                            parent[u] = node;
                            pq.push(make_pair(d[u], u));
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++){
                p[i] = make_pair(d[i], parent[i]);
            }

            return p;
        }

        string printShortestPath(int startNode, int endNode) {
           int p;
           int curr_node = endNode;
           bool path_found = false;
           string string_to_return;
           vector<pair<int, int>> arr = this->dijkstra(startNode);


           if(arr[endNode].first == INT32_MAX){
                return "";
           }

           string_to_return = " " + std::to_string(endNode) + " ";

           while(path_found == false){
                p = arr[curr_node].second;
                if(p == startNode){
                    path_found = true;
                    string_to_return = std::to_string(p) + string_to_return;
                }else{
                    curr_node = p;
                    string_to_return = " " + std::to_string(p) + string_to_return;
                }
           }

           return string_to_return;
        }
};



