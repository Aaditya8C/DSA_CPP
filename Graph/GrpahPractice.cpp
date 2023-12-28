#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
class Graph{
    unordered_map<int,string> color;
    unordered_map<int,int> pd;
    queue<int>sortedVertices;
    unordered_map<int,vector<int>> adj;

    public:
        void insert(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void BFS(int s){
            for(auto u:adj){
                color[u.first] = "white";
                pd[u.first] = 0;
            }
            color[s] = "gray";
            pd[s] = 0;
            sortedVertices.push(s);

            while(!sortedVertices.empty()){
                int u = sortedVertices.front();
                sortedVertices.pop();

                for(auto v:adj[u]){
                    if(color[v] == "white"){
                        color[v] = "gray";
                        pd[v] = u;
                        sortedVertices.push(v);
                    }
                }
                cout << u << endl;
                color[u] = "black";
            }
        }

        void DFS(){
            for(auto u:adj){
                color[u.first] = "white";
                pd[u.first] = 0;
            }
            for(auto elem:adj){
                int u = elem.first;
                if(color[u] == "white")
                    DFS_Visit(u);
            }
        }
        void DFS_Visit(int u){
            color[u] = "gray";
            for(auto v:adj[u]){
                if(color[v] == "white"){
                    pd[v] = u;
                    DFS_Visit(v);
                }
            }
            color[u] = "black";
            cout << u;
        }
};
int main(){
    Graph gg;
    gg.insert(1,2);
    gg.insert(2,3);
    gg.insert(3,4);
    gg.insert(4,1);
    // gg.BFS(4);
    gg.DFS();
}