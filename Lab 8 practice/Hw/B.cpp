#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> g[n + 1];
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    cout << n << endl;
    for(int i = 1; i <= n; i++){
        cout << g[i].size() << " ";
        sort(g[i].begin(), g[i].end());
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}