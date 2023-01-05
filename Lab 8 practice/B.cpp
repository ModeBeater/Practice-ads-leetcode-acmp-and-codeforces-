#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> g[n + 1];
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        cout << g[i].size() << " ";
    }
}