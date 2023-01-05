#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int NEW = 0;
int during = 1;
int visited = 2;
int n;
vector<int> g[123];
bool used[123];
vector<int> state(123, NEW);
vector<int> path(123);

void dfs(int v){
    if(state[v] == during){
        cout << "No" << endl;
        exit(0);
    }
    if(state[v] == visited){
        return;
    }
    state[v] = during;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        path[to] = v;
        dfs(to);
    }
    state[v] = visited;
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(state[i] == NEW){
            path[i] = -1;
            dfs(i);
        }
    }
    cout << "Yes" << endl;
}